#-------------------------------------------------
#
# Project created by QtCreator 2014-10-15T15:24:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scrabble
TEMPLATE = app


SOURCES += main.cpp\
        scrabble.cpp \
    scrabblefunc.cpp \
    field.cpp \
    const.cpp

HEADERS  += scrabble.h \
    scrabblefunc.h \
    field.h \
    const.h

FORMS    += scrabble.ui

CONFIG += mobility
MOBILITY = 

