#-------------------------------------------------
#
# Project created by QtCreator 2014-10-15T15:24:30
#
#-------------------------------------------------

QT       += core gui
QT       += testlib
CONFIG   += c++11
CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scrabble
TEMPLATE = app

RESOURCES += \
    files.qrc 

SOURCES += main.cpp\
        scrabble.cpp \
    scrabblefunc.cpp \
    field.cpp \
    const.cpp \
    vocabulary.cpp \
    trie.cpp \
    vocabularytest.cpp \
    keyboard.cpp \
    botinterface.cpp \
    cell.cpp


HEADERS  += scrabble.h \
    scrabblefunc.h \
    field.h \
    const.h \
    vocabulary.h \
    trie.h \
    vocabularytest.h \  
    keyboard.h \ 
    botinterface.h \
    cell.h


FORMS    += scrabble.ui

CONFIG += mobility
MOBILITY = 

