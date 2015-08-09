#ifndef POL_POM_QT_PLUGINS_STEAM_H
#define POL_POM_QT_PLUGINS_STEAM_H

#include <QObject>

#include "headers/pol_pom_qt_plugins_steam_global.h"
#include "headers/steamplugininterface.h"

class SteamPlugin : public QObject, SteamPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "playonlinux.com.SteamPluginInterface" FILE "POL_POM_QT_PLUGINS_STEAM.json")
    Q_INTERFACES(SteamPluginInterface)

public:
    SteamPlugin();
    ~SteamPlugin();

    int Execute();
};

#endif // POL_POM_QT_PLUGINS_STEAM_H
