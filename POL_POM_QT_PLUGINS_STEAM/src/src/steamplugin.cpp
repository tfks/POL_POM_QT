#include "../headers/steamplugin.h"
#include "../headers/wizardsteaminstallation.h"


SteamPlugin::SteamPlugin()
{
}

SteamPlugin::~SteamPlugin()
{

}

// should go to libcommonui as generic method...
void SteamPlugin::createAddVirtualDriveButton()
{
    this->addVirtualDriveButton = new QToolButton();

    this->addVirtualDriveButton->setObjectName("addVirtualDriveButton");

    this->addVirtualDriveButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    this->addVirtualDriveButton->setPopupMode(QToolButton::MenuButtonPopup);

    this->addVirtualDriveButton->setText(QString(tr("Add Virtual Drive")));
    this->addVirtualDriveButton->setIcon(QIcon(":/mainwindow/add_plus_48"));

    QMenu *menuForAddVirtualDriveButton = new QMenu(this->addVirtualDriveButton);

    QAction *actionAddVirtualDrive = new QAction(QIcon(":/wizardsteaminstallation/steam-icon"),
                                                 QString(tr("Create Steam installation")),
                                                 menuForAddVirtualDriveButton);

    actionAddVirtualDrive->setStatusTip(QString(tr("Create a Steam installation with separate Virtual Drives for each game")));

    menuForAddVirtualDriveButton->addAction(actionAddVirtualDrive);

    this->addVirtualDriveButton->setMenu(menuForAddVirtualDriveButton);

    connect(actionAddVirtualDrive, SIGNAL(triggered(bool)), this, SLOT(slot_actionCreateSteamInstallation_triggered()));
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
    connect(this, SIGNAL(signal_addNewVirtualDriveButton(QToolButton*)), this->mainWindow, SLOT(slot_addVirtualDriveControlButton(QToolButton*)));

    // add a toolbutton or it's action to the add virtual drive menu first index
    this->createAddVirtualDriveButton();

    emit signal_addNewVirtualDriveButton(this->addVirtualDriveButton);

    return true;
}

void SteamPlugin::slot_mainWindowIsShown()
{
    /* Add code to react on main window showing */
    /* MainWindow needs to expose methods to interact with ui elements */

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
