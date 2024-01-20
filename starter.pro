# Copyright (C) 2024 Adesh Singh
QT += quick core quickcontrols2 svg qml

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = appicon.ico
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += \
    $$PWD/QStarter/Component \
    $$PWD/QStarter/Screens \
    $$PWD/QStarter/Icons

SOURCES += \
        application.cpp \
        main.cpp \
        src/svgelementprovider.cpp \
        themeinfo.cpp

RESOURCES += qml.qrc \
	     qstarter.qrc

HEADERS += \
	application.h \
	src/svgelementprovider.h \
	themeinfo.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
