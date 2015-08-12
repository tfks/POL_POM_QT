#include "../headers/steamplugin.h"


SteamPlugin::SteamPlugin()
{
}

SteamPlugin::~SteamPlugin()
{

}

bool SteamPlugin::connectPlugin(MainWindow *mainWindow)
{
    /*
     * Hook into the main window of POL
     * Add event listeners for menu items and buttons and set enabled state when connected
     * Make sure that the main window can provide a config object so that all configuration is in one central place
     */

    if (!mainWindow) return false;

    this->mainWindow = mainWindow;

    connect(this->mainWindow, SIGNAL(signal_showingMainWindow()), this, SLOT(slot_mainWindowIsShown()));

    return true;
}

void SteamPlugin::slot_mainWindowIsShown()
{
    /* Add code to react on main window showing */
    /* MainWindow needs to expose methods to interact with ui elements */

    //
}
