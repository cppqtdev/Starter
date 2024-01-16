

#ifndef SVGELEMENTPROVIDER_HPP
#define SVGELEMENTPROVIDER_HPP

#include <QQuickImageProvider>

class SvgElementProvider : public QQuickImageProvider
{
public:
    explicit SvgElementProvider(QQmlImageProviderBase::ImageType type = QQmlImageProviderBase::Image, const QUrl& base = QUrl(QStringLiteral("qrc:///")));
    virtual ~SvgElementProvider() {}

    virtual QImage requestImage(const QString& id, QSize* size, const QSize& requestedSize);
    virtual QPixmap requestPixmap(const QString& id, QSize* size, const QSize& requestedSize);
    inline void setBaseUrl(const QUrl& base) { mBaseUrl = base; }

private:
    QUrl mBaseUrl;
};

#endif // SVGELEMENTPROVIDER_HPP
