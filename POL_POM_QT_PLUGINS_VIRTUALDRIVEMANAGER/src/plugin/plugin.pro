#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T16:59:16
#
#-------------------------------------------------

QT       += core gui

TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../../../POL_POM_QT/src
TARGET          = $$qtLibraryTarget(VirtualDriveManagerPlugin)
DESTDIR         = $$OUT_PWD/../../../POL_POM_QT/plugins/

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix: LIBS += -L$$OUT_PWD/../../../POL_POM_QT/lib/ -lVirtualDrive

INCLUDEPATH += $$OUT_PWD/../../../POL_POM_QT
DEPENDPATH += $$OUT_PWD/../../../POL_POM_QT

include(../src/src.pri)
include(../headers/headers.pri)
include(../ui/ui.pri)
include(../resources/resources.pri)
