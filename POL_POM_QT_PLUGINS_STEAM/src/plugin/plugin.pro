#-------------------------------------------------
#
# Project created by QtCreator 2015-06-07T14:30:36
#
#-------------------------------------------------

QT       += core gui

TEMPLATE     = lib
CONFIG      += plugin
QT          += widgets
INCLUDEPATH += ../../../POL_POM_QT/src
TARGET       = $$qtLibraryTarget(SteamPlugin)
DESTDIR      = $$OUT_PWD/../../../POL_POM_QT/plugins/

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(../src/src.pri)
include(../headers/headers.pri)
include(../ui/ui.pri)
include(../resources/resources.pri)
