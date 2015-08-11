#-------------------------------------------------
#
# Project created by QtCreator 2015-07-19T19:21:08
#
#-------------------------------------------------

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = $$OUT_PWD/POL_POM_QT/lib/VirtualDrive
TEMPLATE = lib

DEFINES += POL_POM_QT_LIB_VIRTUALDRIVE_LIBRARY

SOURCES += \
    virtualdriveitem.cpp \
    virtualdrivemanager.cpp

HEADERS +=\
        pol_pom_qt_lib_virtualdrive_global.h \
    virtualdriveitem.h \
    virtualdrivemanager.h \
    constants.h

unix: LIBS += -L$$OUT_PWD/../POL_POM_QT/lib/ -lPolCommon

INCLUDEPATH += $$OUT_PWD/../POL_POM_QT/
DEPENDPATH += $$OUT_PWD/../POL_POM_QT/

unix {
    target.path = /usr/lib
    INSTALLS += target
}
