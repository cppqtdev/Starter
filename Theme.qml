// Copyright (C) 2024 Adesh Singh

pragma Singleton
import QtQuick

QtObject {
    id:theme
    property color background: gTheme.isDark ? DarkTheme.background : LightTheme.background
    property color text: gTheme.isDark ? DarkTheme.text : LightTheme.text



    //font style and font family name

    readonly property int       h1 : 32
    readonly property int       h2 : 24
    readonly property double    h3 : 18.72
    readonly property int       h4 : 16
    readonly property double    h5 : 13.28
    readonly property double    h6 : 10.72

    readonly property int content : 14

    readonly property var getAwesomeRegular: fontAwesomeRegular
    readonly property var getAwesomeSolid: fontAwesomeSolid
    readonly property var getContentFontBold: contentFontBold
    readonly property var getContentFontRegular: contentFontRegular
    readonly property var getContentFontLight: contentFontLight

    readonly property var fontAwesomeRegular: FontLoader {
        source: "qrc:/resources/fonts/Font Awesome 5 Free-Regular-400.otf"
    }
    readonly property var fontAwesomeSolid: FontLoader {
        source: "qrc:/resources/fonts/Font Awesome 5 Free-Solid-900.otf"
    }

    readonly property var contentFontLight: FontLoader {
        source: "qrc:/resources/fonts/Nunito-Light.ttf"
    }

    readonly property var contentFontBold: FontLoader {
        source: "qrc:/resources/fonts/Nunito-Bold.ttf"
    }

    readonly property var contentFontRegular: FontLoader {
        source: "qrc:/resources/fonts/Nunito-Regular.ttf"
    }

    property var basic: {
        whatsapp: "image:///whatsapp.svg"
    }
}
