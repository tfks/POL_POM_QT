#-------------------------------------------------
#
# Project created by QtCreator 2015-05-28T14:56:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = $$OUT_PWD/../bin/playonlinux
TEMPLATE = app

unix: LIBS += -L$$OUT_PWD/../lib/ -lPolCommon

INCLUDEPATH += $OUT_PWD/../
DEPENDPATH += $OUT_PWD/../

unix: LIBS += -L$$OUT_PWD/../lib/ -lVirtualDrive

INCLUDEPATH += $OUT_PWD/../
DEPENDPATH += $OUT_PWD/../

include(src/src.pri)
include(headers/headers.pri)
include(ui/ui.pri)
include(resources/resources.pri)


#unix: LIBS += -L$$PWD/../../../../../On-Github/build-POL_POM_QT_SOLUTION-Qt_5_4_2_2_qt5-Debug/POL_POM_QT/lib/ -lPolCommon

#INCLUDEPATH += $$PWD/../../../../../On-Github/build-POL_POM_QT_SOLUTION-Qt_5_4_2_2_qt5-Debug/POL_POM_QT
#DEPENDPATH += $$PWD/../../../../../On-Github/build-POL_POM_QT_SOLUTION-Qt_5_4_2_2_qt5-Debug/POL_POM_QT

CONFIG += console
