// Copyright (C) 2024 Adesh Singh

#include "svgelementprovider.h"
#include <algorithm>

#include <QQmlFile>
#include <QSvgRenderer>
#include <QPainter>
#include <QFont>
#include <QFontDatabase>
#include <QDebug>

namespace
{

/* Create a placeholder that could be returned in case of errors. */
QImage placeholder(const QString& string, const QSize& size = QSize(200, 200))
{
    QImage image((size.isEmpty() ? QSize(200, 200) : size), QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::transparent);

    QPainter p(&image);
    QFont font(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    p.setFont(font);

    // Find the longest line
    QStringList lines = string.split("\n");
    std::sort(lines.begin(), lines.end(), [](const QString & lhs, const QString & rhs)
              { return rhs.size() < lhs.size(); });

    // Auto scale the font size. (5% margin on each side)
    qreal factor = (image.width() * 0.9) / static_cast<qreal>(p.fontMetrics().maxWidth());
    if ((factor < 1) || (factor > 1.25))
    {
        QFont f = p.font();
        f.setPointSizeF(f.pointSizeF() * factor);
        p.setFont(f);
    }

    p.drawText(image.rect(), Qt::AlignCenter, string);
    return image;
}

} // namespace

SvgElementProvider::SvgElementProvider(QQmlImageProviderBase::ImageType type, const QUrl& base):
    QQuickImageProvider(type), mBaseUrl(base)
{
}

QImage SvgElementProvider::requestImage(const QString& id, QSize* size, const QSize& requestedSize)
{
    // Resolve URL
    QUrl url = QUrl(id);
    if (url.isRelative() && !mBaseUrl.isEmpty())
        url = mBaseUrl.resolved(url);

    if (!url.isValid())
        return placeholder(QString("Invalid URL\nBase: %1\nInput: %2").arg(mBaseUrl.toString()).arg(id), requestedSize);

    // Make a filename from the given URL
    QString imagepath = QQmlFile::urlToLocalFileOrQrc(url);
    // Fragment is used to specify SVG element
    QString elementId = url.fragment();

    // Load image
    QSvgRenderer renderer;
    if (!renderer.load(imagepath))
    {
        qWarning() << "Unable to load image:" << imagepath;
        return placeholder(QStringLiteral("Unable to load image:\n") + imagepath, requestedSize);
    }

    // Check whether requested element exists
    if (!elementId.isEmpty() && !renderer.elementExists(elementId))
        return placeholder(QStringLiteral("Unable to find element:\n") + elementId + "\nin image:\n" + imagepath, requestedSize);

    // Get image or element size
    QSize itemSize = elementId.isEmpty() ? renderer.defaultSize() : renderer.boundsOnElement(elementId).size().toSize();

    if (size)
        *size = itemSize;

    // Create image
    QImage image(requestedSize.width() > 0 ? requestedSize.width() : itemSize.width(),
                 requestedSize.height() > 0 ? requestedSize.height() : itemSize.height(),
                 QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::transparent);

    // Paint svg or element
    QPainter p(&image);
    if (elementId.isEmpty())
        renderer.render(&p);
    else
        renderer.render(&p, elementId);

    return image;
}

QPixmap SvgElementProvider::requestPixmap(const QString& id, QSize* size, const QSize& requestedSize)
{
    return QPixmap::fromImage(requestImage(id, size, requestedSize));
}
