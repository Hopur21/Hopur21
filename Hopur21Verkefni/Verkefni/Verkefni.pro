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
    datalayer.cpp \
    cspersonservice.cpp

HEADERS += \
    csperson.h \
    menuinterface.h \
    userlayer.h \
    datalayer.h \
    cspersonservice.h

static { # everything below takes effect with CONFIG ''= static
 CONFIG+= static
 CONFIG += staticlib # this is needed if you create a static library, not a static executable
 DEFINES+= STATIC
 message("~~~ static build ~~~") # this is for information, that the static build is done
 mac: TARGET = $$join(TARGET,,,_static) #this adds an _static in the end, so you can seperate static build from non static build
 win32: TARGET = $$join(TARGET,,,s) #this adds an s in the end, so you can seperate static build from non static build
}

# change the nama of the binary, if it is build in debug mode
CONFIG (debug, debug|release) {
 mac: TARGET = $$join(TARGET,,,_debug)
 win32: TARGET = $$join(TARGET,,,d)
}
