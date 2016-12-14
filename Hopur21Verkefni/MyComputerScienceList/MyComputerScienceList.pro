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
    repositories/dbcon.cpp \
    services/cspersonservice.cpp \
    services/service.cpp \
    services/computerservice.cpp \
    ui/mainwindow.cpp \
    ui/addcomputer.cpp \
    ui/addcomputerscientist.cpp \
    ui/addtype.cpp \
    ui/showlist.cpp \
    ui/showtrash.cpp

HEADERS  += models/csperson.h \
    models/computer.h \
    utilities/constants.h \
    repositories/dbcon.h \
    services/cspersonservice.h \
    services/service.h \
    services/computerservice.h \
    ui/mainwindow.h \
    ui/addcomputer.h \
    ui/addcomputerscientist.h \
    ui/addtype.h \
    ui/showlist.h \
    ui/showtrash.h

FORMS    += ui/mainwindow.ui \
    ui/addcomputer.ui \
    ui/addcomputerscientist.ui \
    ui/addtype.ui \
    ui/showlist.ui \
    ui/showtrash.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../../../icons/noun_570270_cc copy.png

