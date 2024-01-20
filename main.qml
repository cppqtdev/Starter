// Copyright (C) 2024 Adesh Singh


/*
  Download free icons for application use : https://iconduck.com/
*/
import QtQuick
import QtQuick.Window
import QtQuick.Controls
import Theme
import "assets/IconProvider.js" as Icons

import QStarter.Component 0.1
import QStarter.Screens 0.1
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: Style.background


    HomePage{
        anchors.centerIn:parent
    }
}
