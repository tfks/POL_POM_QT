#include <QMainWindow>
#include <QMessageBox>

#include "../headers/bouquetmanagerplugin.h"
#include "../../POL_POM_QT_LIB_VIRTUALDRIVE/virtualdriveitem.h"
#include "../../POL_POM_QT_LIB_VIRTUALDRIVE/virtualdrivemanager.h"

#include "../headers/dialognewbouquet.h"

BouquetManagerPlugin::BouquetManagerPlugin()
{
    this->listOfVirtualDrives = QList<VirtualDriveItem*>();
}

BouquetManagerPlugin::~BouquetManagerPlugin()
{
}

void BouquetManagerPlugin::getListOfVirtualDrives()
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

// should go to libcommonui as generic method...
void BouquetManagerPlugin::createAddVirtualDriveButton()
{
    this->addVirtualDriveButton = new QToolButton();

    this->addVirtualDriveButton->setObjectName("addVirtualDriveButton");

    this->addVirtualDriveButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    this->addVirtualDriveButton->setPopupMode(QToolButton::MenuButtonPopup);

    this->addVirtualDriveButton->setText(QString(tr("Add Virtual Drive")));
    this->addVirtualDriveButton->setIcon(QIcon(":/mainwindow/add_plus_48"));

    QMenu *menuForAddVirtualDriveButton = new QMenu(this->addVirtualDriveButton);

    QAction *actionAddVirtualDrive = new QAction(QIcon(":/mainwindow/add_plus_48"),
                                                 QString(tr("Add Virtual Drive")),
                                                 menuForAddVirtualDriveButton);

    actionAddVirtualDrive->setStatusTip(QString(tr("Add a new Virtual Drive")));

    menuForAddVirtualDriveButton->addAction(actionAddVirtualDrive);

    this->addVirtualDriveButton->setMenu(menuForAddVirtualDriveButton);

    connect(actionAddVirtualDrive, SIGNAL(triggered(bool)), this, SLOT(slot_actionAddNewVirtualDrive_triggered()));
}

bool BouquetManagerPlugin::connectPlugin(MainWindow *mainWindow)
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
    connect(this, SIGNAL(signal_addNewVirtualDriveButton(QToolButton*)), this->mainWindow, SLOT(slot_addVirtualDriveControlButton(QToolButton*)));

    // add a toolbutton or it's action to the add virtual drive menu first index.
    this->createAddVirtualDriveButton();

    emit signal_addNewVirtualDriveButton(this->addVirtualDriveButton);

    return true;
}

void BouquetManagerPlugin::slot_mainWindowIsShown()
{
    /* Add code to react on main window showing */
    /* MainWindow needs to expose methods to interact with ui elements */

    this->getListOfVirtualDrives();
}

void BouquetManagerPlugin::slot_actionAddNewVirtualDrive_triggered()
{
    DialogNewBouquet *dialogNewBouquet = new DialogNewBouquet(mainWindow);

    if (dialogNewBouquet->exec() == QDialog::Accepted) {
        //
    }

    delete dialogNewBouquet;
}
