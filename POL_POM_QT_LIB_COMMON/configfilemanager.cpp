#include <QSettings>
#include <QDebug>
#include <QCoreApplication>
#include <QTextStream>

#include "configfilemanager.h"

bool readConfigFile( QIODevice& device, QSettings::SettingsMap& map )
//bool /*ConfigFileManager::*/readFile(QIODevice &device, QSettings::SettingsMap &map)
{
#ifdef DEBUG
    qDebug() << Q_FUNC_INFO << endl << "Reading map:" << map;
#endif // DEBUG

    QTextStream inputFileStream(&device);

    while (!inputFileStream.atEnd() && inputFileStream.status() == QTextStream::Ok)
    {
         QString line = inputFileStream.readLine();

         if (line.contains("="))
         {
             QString key = line.split('=')[0];
             QString value = line.split('=')[1];

             if (key != "") {
                 map[key] = value;
             }
         }
    }

    if (inputFileStream.status() != QTextStream::Ok)
    {
        return false;
    }

    return true;
}

bool writeConfigFile( QIODevice& device, const QSettings::SettingsMap& map )
//bool /*ConfigFileManager::*/writeFile(QIODevice &device, const QSettings::SettingsMap &map)
{
#ifdef DEBUG
    qDebug() << Q_FUNC_INFO << endl << "Writing map:" << map;
#endif // DEBUG

    QTextStream outputFileStream(&device);

    QSettings::SettingsMap::ConstIterator map_i;

    for (map_i = map.begin(); map_i != map.end(); map_i++)
    {
        QString key = map_i.key();
        QString value = map_i.value().toString();

        outputFileStream << key << "=" << value;
    }

    outputFileStream.flush();

    return outputFileStream.status() == QTextStream::Ok;
}

ConfigFileManager::ConfigFileManager()
{
    QSettings settings(QSettings::UserScope, QCoreApplication::applicationName());
    QSettings::Format plainKeyValueFormat = settings.registerFormat("cfg", readConfigFile, writeConfigFile, Qt::CaseInsensitive);

    QString path = QString("/home/tamas/.PlayOnLinux/wineprefix/LDD/playonlinux.cfg").replace("/home/tamas/", "$HOME/");

    settings.setPath(plainKeyValueFormat, QSettings::UserScope, path);

    settings.sync();

    if (settings.status() == QSettings::AccessError)
    {
        qDebug() << "Access Error";
    }
    else if (settings.status() == QSettings::FormatError)
    {
        qDebug() << "Format Error";
    }

    QString test = settings.value("ICON", "").toString();

    qDebug() << test;
}

ConfigFileManager::~ConfigFileManager()
{
}

QString ConfigFileManager::readConfigValue(QString configKey, QFileInfo configFilePath)
{
    if (configFilePath.exists()/* && this->settings*/)
    {
        QSettings::Format plainKeyValueFormat = QSettings::registerFormat("cfg", readConfigFile, writeConfigFile, Qt::CaseInsensitive);

        QSettings settings(plainKeyValueFormat, QSettings::UserScope, QCoreApplication::applicationName());

        QString path = configFilePath.absoluteFilePath().replace("/home/tamas/", "$HOME/");

        settings.setPath(plainKeyValueFormat, QSettings::UserScope, path);

        settings.sync();

        if (settings.status() == QSettings::AccessError)
        {
            qDebug() << "access error";
        }
        else if (settings.status() == QSettings::FormatError)
        {
            qDebug() << "format error";
        }

        QVariant selectedValue = settings.value(configKey, "");

        //delete settings;

        return selectedValue.toString();
    }

    return "";
}

QString ConfigFileManager::readConfigValue(QString configKey, QString configFilePath)
{
    QFileInfo configFileInfo = QFileInfo(configFilePath);

    if (configFileInfo.exists())
    {
        return ConfigFileManager::readConfigValue(configKey, configFileInfo);
    }

    return "";
}




