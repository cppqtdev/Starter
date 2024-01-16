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
