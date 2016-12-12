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
    ui/mainwindow.cpp \
    ui/addcomputer.cpp \
    ui/addcomputerscientist.cpp \
    ui/addtype.cpp \
    ui/showlist.cpp

HEADERS  += models/csperson.h \
    models/computer.h \
    utilities/constants.h \
    repositories/datalayer.h \
    repositories/dbcon.h \
    services/cspersonservice.h \
    services/service.h \
    services/computerservice.h \
    ui/mainwindow.h \
    ui/addcomputer.h \
    ui/addcomputerscientist.h \
    ui/addtype.h \
    ui/showlist.h
FORMS    += ui/mainwindow.ui \
    ui/addcomputer.ui \
    ui/addcomputerscientist.ui \
    ui/addtype.ui \
    ui/showlist.ui

RESOURCES += \
    resources.qrc

