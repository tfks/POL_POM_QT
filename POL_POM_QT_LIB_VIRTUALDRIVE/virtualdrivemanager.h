#ifndef VIRTUALDRIVEMANAGER_H
#define VIRTUALDRIVEMANAGER_H

#include <QObject>

#include "virtualdriveitem.h"
#include "../../POL_POM_QT_LIB_COMMON/configfilemanager.h"

class VirtualDriveManager
{
public:
    VirtualDriveManager();
    ~VirtualDriveManager();

    QList<VirtualDriveItem*> getListOfVirtualDrives(QIcon defaultIcon);
private:
    QIcon getIconForVirtualDrive(QDir virtualDriveItemLocation, QIcon defaultIcon);

    ConfigFileManager * configFileManager;
};

#endif // VIRTUALDRIVEMANAGER_H
