#ifndef VIRTUALDRIVEITEM_H
#define VIRTUALDRIVEITEM_H

#include <QString>
#include <QDir>
#include <QIcon>

#include "pol_pom_qt_lib_virtualdrive_global.h"

class POL_POM_QT_LIB_VIRTUALDRIVESHARED_EXPORT VirtualDriveItem
{
public:
    VirtualDriveItem();
    VirtualDriveItem(QString name, QDir path, QIcon icon);
    ~VirtualDriveItem();

    QString getName();
    QString getDescription();
    QDir getPath();
    QIcon getIcon();

    void setName(QString name);
    void setDescription(QString description);
    void setPath(QDir path);
    void setIcon(QIcon icon);

private:
    QString m_name;
    QString m_description;
    QDir m_path;
    QIcon m_icon;
};

#endif // VIRTUALDRIVEITEM_H
