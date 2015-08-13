#include "../headers/steamplugin.h"
#include "../headers/wizardsteaminstallation.h"


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
    connect(this, SIGNAL(signal_addActionToAddVirtualDriveButton(QAction*, int)), this->mainWindow, SLOT(slot_addActionToAddVirtualDriveButton(QAction*, int)));

    return true;
}

void SteamPlugin::slot_mainWindowIsShown()
{
    /* Add code to react on main window showing */
    /* MainWindow needs to expose methods to interact with ui elements */

    QIcon steamIcon = QIcon(":/wizardsteaminstallation/steam-icon");
    QString steamText = QString(tr("Create Steam installation"));

    QAction *action = new QAction(steamIcon, steamText, this->mainWindow);

    action->setStatusTip(QString(tr("Create a Steam installation with separate Virtual Drives for each game")));

    connect(action, SIGNAL(triggered(bool)), this, SLOT(slot_actionCreateSteamInstallation_triggered()));

    emit signal_addActionToAddVirtualDriveButton(action, 1);
}

void SteamPlugin::slot_actionCreateSteamInstallation_triggered()
{
    WizardSteamInstallation *wizardSteamInstallation = new WizardSteamInstallation(mainWindow);

    if (wizardSteamInstallation->exec() == QDialog::Accepted)
    {
        //
    }

    delete wizardSteamInstallation;
}
