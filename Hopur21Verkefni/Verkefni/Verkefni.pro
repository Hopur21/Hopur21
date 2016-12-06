QT += core sql
QT -= gui

CONFIG += c++11

TARGET = Verkefni
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    models/csperson.cpp \
    models/computer.cpp \
    ui/menuinterface.cpp \
    ui/userlayer.cpp \
    repositories/datalayer.cpp \
    repositories/dbcon.cpp \
    services/cspersonservice.cpp \
    services/service.cpp \
    services/computerservice.cpp


HEADERS += \
    models/csperson.h \
    models/computer.h \
    ui/menuinterface.h \
    ui/userlayer.h \
    utilities/constants.h \
    utilities/enums.h \
    repositories/datalayer.h \
    repositories/dbcon.h \
    services/cspersonservice.h \
    services/service.h \
    services/computerservice.h



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
