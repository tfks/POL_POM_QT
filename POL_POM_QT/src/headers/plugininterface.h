#ifndef POLPLUGININTERFACE_H
#define POLPLUGININTERFACE_H

#include "mainwindow.h"

class IPluginInterface
{
public:
    virtual ~IPluginInterface() {}

    virtual bool connectPlugin(MainWindow *mainWindow) = 0;
};

#define IPluginInterface_iid "playonlinux.IPluginInterface"

Q_DECLARE_INTERFACE(IPluginInterface, IPluginInterface_iid)

#endif // POLPLUGININTERFACE_H
