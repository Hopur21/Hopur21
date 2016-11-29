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
    userlayer.cpp \
    datalayer.cpp

HEADERS += \
    csperson.h \
    menuinterface.h \
    userlayer.h \
    datalayer.h
