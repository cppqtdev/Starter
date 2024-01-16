// Copyright (C) 2024 Adesh Singh

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
import Theme
import "assets/IconProvider.js" as Icons
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: gTheme.isDark ? DarkTheme.background : LightTheme.background
    property alias fontSystem: fontSystem

    FontSystem{
        id:fontSystem
    }

    Label{
        y:30
        text: qsTr("This is Font System ..")
        anchors.horizontalCenter: parent.horizontalCenter
        font.family: fontSystem.getAwesomeRegular.name
        font.pixelSize: fontSystem.h2
    }

    Image{
        source: "image:///"+ Icons.basic.whatsapp
    }

    Button{
        text: qsTr("Switch")
        anchors.centerIn: parent
        onClicked: {
            gTheme.isDark = !gTheme.isDark
        }
    }
}
