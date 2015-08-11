#-------------------------------------------------
#
# Project created by QtCreator 2015-07-21T20:25:01
#
#-------------------------------------------------

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = $$OUT_PWD/POL_POM_QT/lib/PolCommon
TEMPLATE = lib

DEFINES += POL_POM_QT_LIB_COMMON_LIBRARY

SOURCES += \
    configfilemanager.cpp

HEADERS +=\
        pol_pom_qt_lib_common_global.h \
    configfilemanager.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}


