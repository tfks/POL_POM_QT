#-------------------------------------------------
#
# Project created by QtCreator 2015-06-07T14:30:36
#
#-------------------------------------------------

QT       += widgets

TARGET = POL_POM_QT_PLUGINS_STEAM
TEMPLATE = lib

DEFINES += POL_POM_QT_PLUGINS_STEAM_LIBRARY

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(src/src.pri)
include(headers/headers.pri)
include(ui/ui.pri)
include(resources/resources.pri)
