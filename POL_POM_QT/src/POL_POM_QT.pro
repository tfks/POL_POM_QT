#-------------------------------------------------
#
# Project created by QtCreator 2015-05-28T14:56:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = playonlinux
TEMPLATE = app

unix: LIBS += -L$$PWD/../../build/POL_POM_QT/lib/ -lPolCommon

INCLUDEPATH += $$PWD/../../build/POL_POM_QT_LIB_COMMON/
DEPENDPATH += $$PWD/../../build/POL_POM_QT

unix: LIBS += -L$$PWD/../../build/POL_POM_QT/lib/ -lVirtualDrive

INCLUDEPATH += $$PWD/../../build/POL_POM_QT_LIB_VIRTUALDRIVE
DEPENDPATH += $$PWD/../../build/POL_POM_QT



include(src/src.pri)
include(headers/headers.pri)
include(ui/ui.pri)
include(resources/resources.pri)

