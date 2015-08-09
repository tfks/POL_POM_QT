#include "virtualdriveitem.h"

VirtualDriveItem::VirtualDriveItem()
{
    this->m_name = QString("");
    this->m_path = QDir(QDir::homePath());
    this->m_icon = QIcon();
}

VirtualDriveItem::VirtualDriveItem(QString name, QDir path, QIcon icon)
{
    this->m_name = QString(name);
    this->m_path = QDir(path);
    this->m_icon = QIcon(icon);
}

VirtualDriveItem::~VirtualDriveItem()
{
}

QString VirtualDriveItem::getName()
{
    return this->m_name;
}

QString VirtualDriveItem::getDescription()
{
    return this->m_description;
}

QDir VirtualDriveItem::getPath()
{
    return this->m_path;
}

QIcon VirtualDriveItem::getIcon()
{
    return this->m_icon;
}

void VirtualDriveItem::setName(QString name)
{
    if (!name.isNull()) {
        this->m_name = name;
    }
}

void VirtualDriveItem::setDescription(QString description)
{
    if (!description.isNull()) {
        this->m_description = description;
    }
}

void VirtualDriveItem::setPath(QDir path)
{
    this->m_path = path;
}

void VirtualDriveItem::setIcon(QIcon icon)
{
    if (!icon.isNull()) {
        this->m_icon = icon;
    }
}
