#ifndef STEAMPLUGININTERFACE_H
#define STEAMPLUGININTERFACE_H

#include <QObject>
#include <QtPlugin>

class SteamPluginInterface
{
public:
    virtual ~SteamPluginInterface() {}

    virtual int Execute();
};

#define SteamPluginInterface_iid "playonlinux.com.SteamPluginInterface"

Q_DECLARE_INTERFACE(SteamPluginInterface, SteamPluginInterface_iid)

#endif // STEAMPLUGININTERFACE_H

