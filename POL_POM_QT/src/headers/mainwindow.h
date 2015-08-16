#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QActionGroup>
#include <QCloseEvent>
#include <QMenu>
#include <QToolButton>

#include "constants.h"
#include "../../POL_POM_QT_LIB_VIRTUALDRIVE/virtualdriveitem.h"

class IPluginInterface;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_action_About_PlayOnLinux_triggered();

    void on_actionAbout_Qt_triggered();

    void on_SwitchToVirtualDrivesOrBouquets_toggle();

    void on_pbtnAddVirtualDrive_clicked();

    void on_pbtnAddNewBouquet_clicked();

    void on_pbtnDeleteVirtualDrive_clicked();

    void on_pbtnDeleteBouquet_clicked();

    void on_pbtnConfigureVirtualDrive_clicked();

private:
    Ui::MainWindow *ui;
    QActionGroup *folderViewStyleGroup;

    QList<IPluginInterface*> loadedPlugins;

    QMenu *virtualDriveAddMenu;

    bool virtualDrivesVisible;

    void readWindowState();
    void writeWindowState();

    void setupFolderViewStyleGroup();
    void set_SwitchToVirtualDrivesOrBouquets_toggle(bool virtualDrivesVisible);
    bool loadPlugins();
    void addItemToVirtualDriveList(VirtualDriveItem *virtualDriveListItem);

protected:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);

signals:
    void signal_showingMainWindow();

public slots:
    void slot_VirtualDriveListChange(QList<VirtualDriveItem*> virtualDriveItems);

    void slot_addVirtualDriveControlButton(QToolButton *buttonToAdd);
};

#endif // MAINWINDOW_H
