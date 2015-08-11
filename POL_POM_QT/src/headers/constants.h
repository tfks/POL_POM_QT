#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

const std::string POL_URL = "http://www.playonlinux.com";
const std::string POL_PLUGIN_DIR = "../plugins";

const std::string POL_BOUQUETS = QT_TR_NOOP("Bouquets");
const std::string POL_VIRTUAL_DRIVES = QT_TR_NOOP("Virtual Drives");
const std::string POL_NO_VIRTUAL_DRIVE_SELECTED = QT_TR_NOOP("No Virtual Drive selected");
const std::string POL_NO_BOUQUET_SELECTED = QT_TR_NOOP("No Bouquet selected");

const std::string POL_MSG_DELETE_BOUQUET_TITLE = QT_TR_NOOP("Delete Bouquet");
const std::string POL_MSG_DELETE_VIRTUAL_DRIVE_TITLE = QT_TR_NOOP("Delete Virtual Drive");

const std::string POL_MSG_DELETE_BOUQUET = QT_TR_NOOP("Do you really want to delete this Bouquet? Note that only the Bouquet's definition is deleted. Linked applications are not touched.");
const std::string POL_MSG_DELETE_VIRTUAL_DRIVE = QT_TR_NOOP("Do you really want to delete this Virtual Drive? Note that only the Virtual Drive's definition is deleted. Linked files are not touched.");

const std::string POL_FILTERS_ICON_SELECTION = QT_TR_NOOP( "Icon files  (*.ico *.png);; All files (*.*)");

const std::string POL_SELECT_ICON_FOR_BOUQUET = QT_TR_NOOP("Select an icon for this Bouquet");
const std::string POL_SELECT_ICON_FOR_VIRTUAL_DRIVE = QT_TR_NOOP("Select an icon for this Virtual Drive");

const std::string POL_OPEN_DEFAULT_APPLICATION_LOCATION = QT_TR_NOOP("Open default application location");


#endif // CONSTANTS_H

