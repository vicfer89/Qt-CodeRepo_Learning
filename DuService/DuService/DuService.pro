#-------------------------------------------------
#
# Project created by QtCreator 2014-03-02T14:01:31
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = MiServicio

CONFIG   += console

CONFIG   -= app_bundle

include(QtService/qtservice.pri)

TEMPLATE = app

SOURCES += main.cpp \
    DuService.cpp

HEADERS += \
    DuService.h
