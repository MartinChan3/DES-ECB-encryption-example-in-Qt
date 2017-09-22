#-------------------------------------------------
#
# Project created by QtCreator 2017-09-21T13:54:11
#
#-------------------------------------------------

include(openssl.pri)

QT       += core

QT       -= gui

TARGET = test_openssl
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    hex.c

HEADERS += \
    hex.h
