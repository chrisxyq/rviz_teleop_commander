#-------------------------------------------------
#
# Project created by QtCreator 2015-08-07T14:55:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = src
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Algorithm.cpp \
    NMotionCtrl.cpp \
    OdomOFPS1.cpp \
    OFPS1.cpp \
    TestNMotion.cpp \
    UART.cpp \
    UARTDev.cpp \
    UartNMotion.cpp \
    UartOFPS1.cpp \
    TFNav.cpp \
    UartPS.cpp \
    PS1.cpp \
    TestPS.cpp \
    UartPBUTTING.cpp \
    PBUTTING1.cpp \
    TestPBUTTING.cpp

HEADERS += \
    Algorithm.h \
    Project.h \
    UART.h \
    UARTDev.h \
    UartNMotion.h \
    UartOFPS1.h \
    UartPS.h \
    UartPBUTTING.h

DISTFILES += \
    ../manifest.xml \
    ../CMakeLists.txt
