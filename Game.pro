TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    scene.cpp \
    character.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    scene.h \
    character.h

