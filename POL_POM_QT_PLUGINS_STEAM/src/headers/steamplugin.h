#ifndef POL_POM_QT_PLUGINS_STEAM_H
#define POL_POM_QT_PLUGINS_STEAM_H

#include <QObject>

#include "../../POL_POM_QT/src/headers/plugininterface.h"
#include "../../POL_POM_QT/src/headers/mainwindow.h"

#include "../headers/pol_pom_qt_plugins_steam_global.h"

class SteamPlugin : public QObject, IPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "playonlinux.com.SteamPluginInterface" FILE "POL_POM_QT_PLUGINS_STEAM.json")
    Q_INTERFACES(IPluginInterface)

public:
    SteamPlugin();
    ~SteamPlugin();

    bool connectPlugin(MainWindow *mainWindow) Q_DECL_OVERRIDE;

private:
    MainWindow *mainWindow;
    QToolButton *addVirtualDriveButton;

    void createAddVirtualDriveButton();

signals:
    void signal_addNewVirtualDriveButton(QToolButton *addVirtualDriveButton);

private slots:
    void slot_mainWindowIsShown();

    void slot_actionCreateSteamInstallation_triggered();
};

#endif // POL_POM_QT_PLUGINS_STEAM_H
