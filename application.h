#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QQmlEngine>
#include <QQmlApplicationEngine>

#include "themeinfo.h"

class ThemeInfo;
class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QQmlApplicationEngine *engine,QObject *parent = nullptr);

    static Application *getInstance(QQmlApplicationEngine *engine = nullptr){
        if(_application== nullptr){
            qDebug()<<"Application instance created ...";
            _application = new Application(engine);
        }
        return _application;
    }

    ThemeInfo *getThemeInfo();


public slots:
signals:
private:
    void initComponent();
    void registerQML();

    QQmlApplicationEngine *m_engine;
    static Application * _application;
    ThemeInfo * _themeInfo;

};

#endif // APPLICATION_H
