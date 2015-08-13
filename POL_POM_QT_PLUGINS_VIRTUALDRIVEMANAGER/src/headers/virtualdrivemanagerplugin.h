#ifndef VIRTUALDRIVEMANAGERPLUGIN_H
#define VIRTUALDRIVEMANAGERPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QObjectList>

#include "../../POL_POM_QT/src/headers/plugininterface.h"
#include "../../POL_POM_QT/src/headers/mainwindow.h"

#include "../../POL_POM_QT_LIB_VIRTUALDRIVE/virtualdriveitem.h"

class VirtualDriveManagerPlugin : public QObject, public IPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "playonlinux.IPluginInterface" FILE "POL_POM_QT_PLUGINS_VIRTUALDRIVEMANAGER.json")
    Q_INTERFACES(IPluginInterface)
public:
    VirtualDriveManagerPlugin();
    ~VirtualDriveManagerPlugin();

    bool connectPlugin(MainWindow *mainWindow) Q_DECL_OVERRIDE;

private:
    MainWindow *mainWindow;
    QList<VirtualDriveItem*> listOfVirtualDrives;

    void getListOfVirtualDrives();

signals:
    void signal_VirtualDriveListChange(QList<VirtualDriveItem*> virtualDriveItems);
    void signal_addActionToAddVirtualDriveButton(QAction *action, int index);

private slots:
    void slot_mainWindowIsShown();

    void slot_actionAddNewVirtualDrive_triggered();
};

#endif // VIRTUALDRIVEMANAGERPLUGIN_H
