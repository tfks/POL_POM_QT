#include <QDir>
#include <QDirIterator>
#include <QSettings>

#include "virtualdrivemanager.h"

#include "constants.h"
#include "../POL_POM_QT_LIB_COMMON/configfilemanager.h"

VirtualDriveManager::VirtualDriveManager()
{
    this->configFileManager = new ConfigFileManager();
}

VirtualDriveManager::~VirtualDriveManager()
{
    if (this->configFileManager)
    {
        delete this->configFileManager;
    }
}

QIcon VirtualDriveManager::getIconForVirtualDrive(QDir virtualDriveItemLocation, QIcon defaultIcon)
{
    // find playonlinux.cfg in the virtual drive's directory.
    QFileInfo configPath = QFileInfo(virtualDriveItemLocation, "playonlinux.cfg");

    QString iconValue = this->configFileManager->readConfigValue(VD_CONFIG_KEYS_ICON, configPath);

    if (iconValue != "")
    {
        return QIcon(iconValue);
    }
    else
    {
        return defaultIcon;
    }
}

QList<VirtualDriveItem*> VirtualDriveManager::getListOfVirtualDrives(QIcon defaultIcon)
{
    QList<VirtualDriveItem*> virtualDriveItems = QList<VirtualDriveItem*>();

    QDir virtualDriveItemDir = QDir::home();

    if (virtualDriveItemDir.cd(".PlayOnLinux"))
    {
        if (virtualDriveItemDir.cd("wineprefix"))
        {
            QString dirForIteration = virtualDriveItemDir.absolutePath();

            QDirIterator dirIterator(dirForIteration, QStringList() << "*", QDir::Dirs, QDirIterator::NoIteratorFlags);

            while (dirIterator.hasNext())
            {
                QString dirName = dirIterator.next();

                QDir virtualDriveDir = QDir(dirName);

                dirName = virtualDriveDir.absolutePath();

                if(virtualDriveDir.dirName() != "default" && virtualDriveDir.dirName() != "." && virtualDriveDir.dirName() != "..")
                {
                    VirtualDriveItem* virtualDriveItem = new VirtualDriveItem();

                    virtualDriveItem->setName(virtualDriveDir.dirName());
                    virtualDriveItem->setPath(virtualDriveDir.absolutePath());
                    virtualDriveItem->setDescription("Dummy for now...");

                    virtualDriveItem->setIcon(getIconForVirtualDrive(virtualDriveDir, defaultIcon));

                    virtualDriveItems.append(virtualDriveItem);
                }
            }
        }
    }

    return virtualDriveItems;
}
