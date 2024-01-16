// Copyright (C) 2024 Adesh Singh

#include "application.h"
#include <QQmlContext>
#include "src/svgelementprovider.h"

Application *Application::_application = nullptr;
Application::Application(QQmlApplicationEngine *engine,QObject *parent)
    : QObject{parent},
    m_engine{engine}
{
    _themeInfo = nullptr;

    initComponent();
    registerQML();
}

void Application::initComponent()
{
    _themeInfo = new ThemeInfo();
}

void Application::registerQML()
{
    qmlRegisterSingletonType(QUrl(QStringLiteral("qrc:/LightTheme.qml")),"Theme",1,0,"LightTheme");
    qmlRegisterSingletonType(QUrl(QStringLiteral("qrc:/DarkTheme.qml")),"Theme",1,0,"DarkTheme");


    m_engine->rootContext()->setContextProperty("gTheme",_themeInfo);
    m_engine->addImageProvider(QStringLiteral(""), new SvgElementProvider(QQmlImageProviderBase::Image, QUrl(QStringLiteral("qrc:///assets/"))));
}

ThemeInfo *Application::getThemeInfo()
{
    return _themeInfo;
}
