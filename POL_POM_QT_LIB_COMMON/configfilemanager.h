#ifndef CONFIGFILEMANAGER_H
#define CONFIGFILEMANAGER_H

#include <QObject>
#include <QString>
#include <QDir>
#include <QSettings>

bool readConfigFile( QIODevice& device, QSettings::SettingsMap& map );
bool writeConfigFile( QIODevice& device, const QSettings::SettingsMap& map );

class ConfigFileManager : public QObject
{
    Q_OBJECT
public:
    ConfigFileManager();
    ~ConfigFileManager();

    QString readConfigValue(QString configKey, QFileInfo configFilePath);
    QString readConfigValue(QString configKey, QString configFilePath);

    /*static bool readFile(QIODevice &device, QSettings::SettingsMap &map);
    static bool writeFile(QIODevice &device, const QSettings::SettingsMap &map);*/

private:
};

#endif // CONFIGFILEMANAGER_H
