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
<<<<<<< HEAD
    field.cpp
=======
    field.cpp \
    const.cpp \
    vocabulary.cpp \
    trie.cpp \
    vocabularytest.cpp

>>>>>>> b280107635e0309b983e3098fb995ea505b9c3d5

HEADERS  += scrabble.h \
    scrabblefunc.h \
    field.h \
    const.h \
    vocabulary.h \
    trie.h \
    vocabularytest.h 

FORMS    += scrabble.ui

CONFIG += mobility
MOBILITY = 

