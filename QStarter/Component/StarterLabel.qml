import QtQuick 2.15
import QtQuick.Controls
import Theme

Label{
    elide: Text.ElideRight
    wrapMode: Label.WrapAtWordBoundaryOrAnywhere
    color: Style.text
    font.family: Style.getAwesomeRegular.name
    font.pixelSize: Style.h2

    Accessible.name: text
    Accessible.role: Accessible.StaticText

    onLinkActivated: {
        Qt.openUrlExternally(link)
    }

    onLinkHovered: {
       // do width link hover
    }
}
