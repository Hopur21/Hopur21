QT += core
QT -= gui

CONFIG += c++11

TARGET = Verkefni
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    csperson.cpp \
    menuinterface.cpp \
    listaccess.cpp \
    userlayer.cpp

HEADERS += \
    csperson.h \
    menuinterface.h \
    listaccess.h \
    userlayer.h
