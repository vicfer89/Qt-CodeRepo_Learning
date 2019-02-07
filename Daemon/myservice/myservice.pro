#-------------------------------------------------
#
# Project created by QtCreator 2014-03-02T14:01:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = myservice
CONFIG   += console
CONFIG   -= app_bundle
include(QtService/qtservice.pri)
TEMPLATE = app


SOURCES += main.cpp \
    myservice.cpp

HEADERS += \
    myservice.h
