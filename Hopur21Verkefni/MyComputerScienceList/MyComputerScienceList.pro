#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T11:56:35
#
#-------------------------------------------------

QT       += core gui sql

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyComputerScienceList
TEMPLATE = app


SOURCES += main.cpp\
    models/csperson.cpp \
    models/computer.cpp \
    repositories/datalayer.cpp \
    repositories/dbcon.cpp \
    services/cspersonservice.cpp \
    services/service.cpp \
    services/computerservice.cpp \
    ui/mainwindow.cpp

HEADERS  += models/csperson.h \
    models/computer.h \
    utilities/constants.h \
    repositories/datalayer.h \
    repositories/dbcon.h \
    services/cspersonservice.h \
    services/service.h \
    services/computerservice.h \
    ui/mainwindow.h

FORMS    += ui/mainwindow.ui \
    ui/addcomputerscientist.ui \
    ui/addcomputer.ui \
    ui/startloadingscreen.ui \
    ui/addtype.ui \
    ui/showlist.ui

RESOURCES += \
    resources.qrc

