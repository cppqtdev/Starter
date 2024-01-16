// Copyright (C) 2024 Adesh Singh

#include "themeinfo.h"

#define DARK_THEME "dark_theme"

ThemeInfo::ThemeInfo(QObject *parent)
    : QObject{parent}
{
    _settings  = new QSettings();
    _settings->setParent(this);

    initSettings();
}

bool ThemeInfo::isDark() const
{
    return m_isDark;
}

void ThemeInfo::setIsDark(bool newIsDark)
{
    if (m_isDark == newIsDark)
        return;
    m_isDark = newIsDark;
    _settings->setValue(DARK_THEME,m_isDark);
    emit isDarkChanged();
}

void ThemeInfo::initSettings()
{
    m_isDark = _settings->value(DARK_THEME,false).toBool();
}

void ThemeInfo::clearSettings()
{
    _settings->clear();
    initSettings();
}
