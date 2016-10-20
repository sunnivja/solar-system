
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
#DEFINES += CATCH_CONFIG_MAIN

SOURCES += main.cpp \
    celestialbody.cpp \
    solarsystem.cpp \
    vec3.cpp \
    euler.cpp \
    verlet.cpp \
    tests.cpp

HEADERS += \
    celestialbody.h \
    solarsystem.h \
    vec3.h \
    euler.h \
    verlet.h \
    tests.h \
    catch.hpp

