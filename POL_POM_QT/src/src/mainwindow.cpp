#include <QDebug>

#include <QSettings>
#include <QActionGroup>
#include <QMessageBox>
#include <QDir>
#include <QPluginLoader>
#include <QLayout>

#include "headers/mainwindow.h"
#include "headers/plugininterface.h"

#include "ui_mainwindow.h"

#include "../headers/dialogabout.h"
#include "../headers/dialogaddbouquet.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings;

    this->restoreGeometry(settings.value("mainWindowGeometry").toByteArray());

    ui->gbxVirtualDrivesAndBouquets->setMinimumWidth(0);

    ui->actionExit->setIcon(QIcon::fromTheme("application-exit"));
    ui->actionAbout_Qt->setIcon(QIcon::fromTheme("help-about"));

    this->virtualDrivesVisible = false;
    this->set_SwitchToVirtualDrivesOrBouquets_toggle(this->virtualDrivesVisible);

    this->folderViewStyleGroup = new QActionGroup(this);

    this->virtualDriveAddMenu = new QMenu(tr("Add Virtual Drive"));
    this->ui->tbtnAddVirtualDriveExt->setMenu(this->virtualDriveAddMenu);

    this->setupFolderViewStyleGroup();

    this->readWindowState();

    this->loadPlugins();

    this->loadedPlugins = QList<IPluginInterface*>();
}

MainWindow::~MainWindow()
{
    delete this->folderViewStyleGroup;

    delete ui;
}

void MainWindow::readWindowState()
{
    QSettings settings;

    QByteArray spltrApplicationsVirtualDrivesAndBouquetsState = settings.value("spltrApplicationsVirtualDrivesAndBouquetsState", QByteArray()).toByteArray();

    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();

    QSize size = settings.value("size", QSize(400, 400)).toSize();

    QByteArray state = settings.value("state", QByteArray()).toByteArray();

    this->restoreState(state);
    this->resize(size);
    this->move(pos);

    this->ui->spltrApplicationsVirtualDrivesAndBouquets->restoreState(spltrApplicationsVirtualDrivesAndBouquetsState);
}

void MainWindow::writeWindowState()
{
    QSettings settings;

    settings.setValue("pos", this->pos());
    settings.setValue("size", this->size());
    settings.setValue("state", this->saveState());

    QByteArray spltrApplicationsVirtualDrivesAndBouquetsState = this->ui->spltrApplicationsVirtualDrivesAndBouquets->saveState();

    settings.setValue("spltrApplicationsVirtualDrivesAndBouquetsState", spltrApplicationsVirtualDrivesAndBouquetsState);
}

void MainWindow::setupFolderViewStyleGroup()
{
    this->folderViewStyleGroup->addAction(ui->action_Small_icons);
    this->folderViewStyleGroup->addAction(ui->action_Medium_icons);
    this->folderViewStyleGroup->addAction(ui->action_Large_icons);
    this->folderViewStyleGroup->addAction(ui->action_Very_large_icons);

    ui->action_Large_icons->setChecked(true);
}

void MainWindow::set_SwitchToVirtualDrivesOrBouquets_toggle(bool virtualDrivesVisible)
{
    QPixmap pmVirtualDrives(":/mainwindow/virtual_drive");
    QPixmap pmBouquets(":/mainwindow/bouquet");

    if (virtualDrivesVisible == false) {
        ui->stwVirtualDrivesAndBouquets->setCurrentIndex(1);

        ui->lblVirtualDrivesAndBouquetsHeaderSelectionIndicator->setText(QString::fromStdString(POL_BOUQUETS));
        ui->lblVirtualDrivesAndBouquetsHeaderSelectionIndicatorPix->setPixmap(QPixmap(pmBouquets));

        ui->lblVirtualDriveOrBouquetTitle->setText(QString::fromStdString(POL_NO_BOUQUET_SELECTED));
    }
    else {
        ui->stwVirtualDrivesAndBouquets->setCurrentIndex(0);

        ui->lblVirtualDrivesAndBouquetsHeaderSelectionIndicator->setText(QString::fromStdString(POL_VIRTUAL_DRIVES));
        ui->lblVirtualDrivesAndBouquetsHeaderSelectionIndicatorPix->setPixmap(QPixmap(pmVirtualDrives));

        ui->lblVirtualDriveOrBouquetTitle->setText(QString::fromStdString(POL_NO_VIRTUAL_DRIVE_SELECTED));
    }
}

void MainWindow::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    this->signal_showingMainWindow();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    this->writeWindowState();

    event->accept();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_action_About_PlayOnLinux_triggered()
{
    DialogAbout * dialogAbout = new DialogAbout(this);
    dialogAbout->exec();
    delete dialogAbout;
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_SwitchToVirtualDrivesOrBouquets_toggle()
{
    this->virtualDrivesVisible = !this->virtualDrivesVisible;

    set_SwitchToVirtualDrivesOrBouquets_toggle(this->virtualDrivesVisible);
}

void MainWindow::on_pbtnAddVirtualDrive_clicked()
{
    // main button click find first item in menu en execute.
}

void MainWindow::on_pbtnAddNewBouquet_clicked()
{
    DialogAddBouquet *dialogAddBouquet = new DialogAddBouquet(this);

    if (dialogAddBouquet->exec() == QDialog::Accepted)
    {
        // read bouquet from property of dialog and save to disk;
        // update main window to reflect added Bouquet (reload data);
    }

    delete dialogAddBouquet;
}

void MainWindow::on_pbtnDeleteVirtualDrive_clicked()
{
    QMessageBox::StandardButton dialogResult;

    dialogResult = QMessageBox::question(this,
                                         QString::fromStdString(POL_MSG_DELETE_VIRTUAL_DRIVE_TITLE),
                                         QString::fromStdString(POL_MSG_DELETE_VIRTUAL_DRIVE),
                                         QMessageBox::Yes|QMessageBox::No);

    if (dialogResult == QMessageBox::Yes)
    {
        // delete the selected virtual drive from disk;
        // reload the list;
    } else {

    }
}

void MainWindow::on_pbtnDeleteBouquet_clicked()
{
    QMessageBox::StandardButton dialogResult;

    dialogResult = QMessageBox::question(this,
                                         QString::fromStdString(POL_MSG_DELETE_BOUQUET_TITLE),
                                         QString::fromStdString(POL_MSG_DELETE_BOUQUET),
                                         QMessageBox::Yes|QMessageBox::No);

    if (dialogResult == QMessageBox::Yes)
    {
        // Delete the bouquet from disk;
        // Reload the lists;
    } else {

    }
}

void MainWindow::on_pbtnConfigureVirtualDrive_clicked()
{
//
}

void MainWindow::addItemToVirtualDriveList(VirtualDriveItem *virtualDriveListItem)
{
    if (virtualDriveListItem)
    {
        QTreeWidgetItem* treeWidgetItem = new QTreeWidgetItem();

        QIcon icon = virtualDriveListItem->getIcon();
        QString text = virtualDriveListItem->getName();

        treeWidgetItem->setIcon(0, icon);
        treeWidgetItem->setText(0, text);

        QList<QVariant> dataList;

        dataList.append(virtualDriveListItem->getPath().absolutePath());

        QVariant data(dataList);

        treeWidgetItem->setData(2, Qt::UserRole, data);

        this->ui->trwVirtualDrives->addTopLevelItem(treeWidgetItem);
    }
}

bool MainWindow::loadPlugins()
{
    QDir pluginsDir(qApp->applicationDirPath());

    #if defined(Q_OS_WIN)
        if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
            pluginsDir.cdUp();
    #elif defined(Q_OS_MAC)
        if (pluginsDir.dirName() == "MacOS") {
            pluginsDir.cdUp();
            pluginsDir.cdUp();
            pluginsDir.cdUp();
        }
    #endif

    // TODO: add logic to search various locations. I.e.: ../plugins for development, ~/.playonlinux/plugins for live

    pluginsDir.cd(QString::fromStdString(POL_PLUGIN_DIR));

    pluginsDir.setNameFilters(QStringList()<<"*.so");

    foreach (QString fileName, pluginsDir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));

        QObject *plugin = pluginLoader.instance();

        if (plugin)
        {
            IPluginInterface *pluginToLoad = qobject_cast<IPluginInterface *>(plugin);

            if (pluginToLoad)
            {
                pluginToLoad->connectPlugin(this);

                this->loadedPlugins.append(pluginToLoad);
            }
        }
    }

    if (this->loadedPlugins.length() > 0) {
        return true;
    }
    else
        return false;
}

void MainWindow::slot_VirtualDriveListChange(QList<VirtualDriveItem *> virtualDriveItems)
{
    this->ui->trwVirtualDrives->clear();

    foreach (VirtualDriveItem *virtualDriveItem, virtualDriveItems) {
        this->addItemToVirtualDriveList(virtualDriveItem);
    }
}

// These slots can be combined to add a QToolButton when no action was previously added:

void MainWindow::slot_addVirtualDriveControlButton(QToolButton *buttonToAdd)
{
    /*
     * check for an existing button via its text. If not there, add a new button and a menu, else add function to the existing button menu.
     */

    // user defined buttons go last. The first one is default, after that user defined buttons are added.
    // best is to keep a list of elements added to various locations, optionally with an index, and
    // after sorting remove the spacer at the end, insert all items and than add a spacer again.

    if (buttonToAdd != NULL)
    {
        // this doesn't work. The button has already been assigned to the groupbox. So it finds itself overiding the other ones action.
        QToolButton *buttonToFind = this->ui->gbxVirtualDrivesControls->findChild<QToolButton*>(buttonToAdd->objectName());

        if (buttonToFind != NULL)
        {
            // there is a button with this name in the groupbox. Add the provided button's actions to it's menu.
            foreach (QAction *actionSource, buttonToAdd->menu()->actions())
            {
                QMessageBox::information(this, QString(tr("Info")), QString(actionSource->text()));

                QAction *copiedAction = qobject_cast<QAction*>(actionSource);

                copiedAction->setParent(buttonToFind->menu());

                buttonToFind->menu()->addAction(copiedAction);
            }

            delete buttonToAdd;
        }
        else
        {
            // there isn't a button with this name in the groupbox. Add the provided button.
            buttonToAdd->setParent(this->ui->gbxVirtualDrivesControls);
            buttonToAdd->setDefaultAction(buttonToAdd->menu()->actions().first());




            this->ui->gbxVirtualDrivesControls->layout()->addWidget(buttonToAdd);

            QMessageBox::information(this, QString(tr("Info")), QString(buttonToAdd->menu()->actions().first()->text()));
        }
    }
}
