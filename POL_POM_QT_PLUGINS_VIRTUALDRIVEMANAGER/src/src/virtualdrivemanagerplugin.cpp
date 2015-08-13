//#include <QtWidgets>
#include <QMainWindow>

#include "../headers/virtualdrivemanagerplugin.h"
#include "../../POL_POM_QT_LIB_VIRTUALDRIVE/virtualdriveitem.h"
#include "../../POL_POM_QT_LIB_VIRTUALDRIVE/virtualdrivemanager.h"

#include "../headers/wizardnewvirtualdrive.h"

VirtualDriveManagerPlugin::VirtualDriveManagerPlugin()
{
    this->listOfVirtualDrives = QList<VirtualDriveItem*>();
}

VirtualDriveManagerPlugin::~VirtualDriveManagerPlugin()
{
}

void VirtualDriveManagerPlugin::getListOfVirtualDrives()
{
    /*
     * Lets make this a private method. This plugin sends its list to the main window
     * so the main window doesn't have to know about any special data types the plugin uses.
     * MainWindow dictates what can be done with it from a plugin and exposes signals and
     * slots for this goal. The plugin does its work the main window does the UI part.
     */

    // Find virtual drives dir

    // Scan all virtual drives

    // Add them to the list

    // dummy with default icon (used when no Virtual Drive icon is found)
    QIcon defaultIcon = QIcon(":/plugvdm/main/playonlinux");

    VirtualDriveManager *virtualDriveManager = new VirtualDriveManager();

    //this->listOfVirtualDrives.clear();

    this->listOfVirtualDrives = virtualDriveManager->getListOfVirtualDrives(defaultIcon);



    //VirtualDriveListItem *dummyVirtualDriveItem = new VirtualDriveListItem("Dummmy", QDir::homePath(), defaultIcon);

    //this->listOfVirtualDrives.append(dummyVirtualDriveItem);

    emit signal_VirtualDriveListChange(this->listOfVirtualDrives);
}

bool VirtualDriveManagerPlugin::connectPlugin(MainWindow *mainWindow)
{
    /*
     * Hook into the main window of POL
     * Add event listeners for menu items and buttons and set enabled state when connected
     * Make sure that the main window can provide a config object so that all configuration is in one central place
     */

    if (!mainWindow) return false;

    this->mainWindow = mainWindow;

    connect(this->mainWindow, SIGNAL(signal_showingMainWindow()), this, SLOT(slot_mainWindowIsShown()));
    connect(this, SIGNAL(signal_VirtualDriveListChange(QList<VirtualDriveItem*>)), this->mainWindow, SLOT(slot_VirtualDriveListChange(QList<VirtualDriveItem*>)));
    connect(this, SIGNAL(signal_addActionToAddVirtualDriveButton(QAction*, int)), this->mainWindow, SLOT(slot_addActionToAddVirtualDriveButton(QAction*, int)));

    // add an action to the add virtual drive menu first index.
    QIcon addVirtualDriveIcon = QIcon(":/mainwindow/add_plus_48");
    QString addVirtualDriveText = QString(tr("Add Virtual Drive"));

    QAction *action = new QAction(addVirtualDriveIcon, addVirtualDriveText, this->mainWindow);

    action->setStatusTip(QString(tr("Add a new Virtual Drive")));

    connect(action, SIGNAL(triggered(bool)), this, SLOT(slot_actionAddNewVirtualDrive_triggered()));

    emit signal_addActionToAddVirtualDriveButton(action, 0);

    return true;
}

void VirtualDriveManagerPlugin::slot_mainWindowIsShown()
{
    /* Add code to react on main window showing */
    /* MainWindow needs to expose methods to interact with ui elements */

    this->getListOfVirtualDrives();
}

void VirtualDriveManagerPlugin::slot_actionAddNewVirtualDrive_triggered()
{
    WizardNewVirtualDrive *wizardNewVirtualDrive = new WizardNewVirtualDrive(mainWindow);

    if (wizardNewVirtualDrive->exec() == QDialog::Accepted) {
        //
    }

    delete wizardNewVirtualDrive;
}
