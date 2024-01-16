// Copyright (C) 2024 Adesh Singh

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "application.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QCoreApplication::setApplicationName("Starter");
    QCoreApplication::setOrganizationName("Starter app");
    QCoreApplication::setOrganizationDomain("starter.in");

    QQuickStyle::setStyle("Material");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    Application *_app = Application::getInstance(engine);
    Q_UNUSED(_app)

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine->load(url);

    return app.exec();
}
