import QtQuick 2.15
import QtQuick.Controls
import Theme

import QStarter.Component
import  QStarter.Icons
Item {
    anchors.fill: parent
    StarterLabel{
        y:30
        text: qsTr("This is Font System")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Image{
        source: IconProvider.basic.whatsapp
    }

    Button{
        text: qsTr("Switch")
        anchors.centerIn: parent
        onClicked: {
            gTheme.isDark = !gTheme.isDark
        }
    }
}
