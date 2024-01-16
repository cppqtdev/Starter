#ifndef THEMEINFO_H
#define THEMEINFO_H

#include <QObject>
#include <QSettings>
class ThemeInfo : public QObject
{
    Q_OBJECT
public:
    explicit ThemeInfo(QObject *parent = nullptr);
    Q_PROPERTY(bool isDark READ isDark WRITE setIsDark NOTIFY isDarkChanged FINAL)
    bool isDark() const;

public slots:
    void setIsDark(bool newIsDark);
signals:
    void isDarkChanged();

private:

    void initSettings();
    void clearSettings();

    QSettings *_settings;
    bool m_isDark;
};

#endif // THEMEINFO_H
