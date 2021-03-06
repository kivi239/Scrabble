#-------------------------------------------------
#
# Project created by QtCreator 2014-10-15T15:24:30
#
#-------------------------------------------------

QT       += core gui
QT       += testlib
CONFIG   += c++11
CONFIG   += console
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scrabble
TEMPLATE = app

RESOURCES += \
    MyRes.qrc

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
    cell.cpp \
    easybot.cpp \
    bottest.cpp \
    startmenu.cpp \
    user.cpp \
    maindatabase.cpp \
    dtabasetest.cpp \
    changeusersform.cpp \
    fieldbutton.cpp  \
    createusers.cpp \
    nyashBot.cpp \
    proxybutton.cpp \
    triecreator.cpp \
    bot.cpp


HEADERS  += scrabble.h \
    scrabblefunc.h \
    field.h \
    const.h \
    vocabulary.h \
    trie.h \
    vocabularytest.h \  
    keyboard.h \ 
    botinterface.h \
    cell.h \
    easybot.h \
    bottest.h \
    startmenu.h \
    user.h \
    mainHeader.h \
    maindatabase.h \
    dtabasetest.h \
    changeusersform.h \
    fieldbutton.h \
    createusers.h \
    nyashBot.h \
    proxybutton.h \
    triecreator.h \
    bot.h


FORMS    += scrabble.ui \
    changeusersform.ui \
    createusers.ui
FORMS    += startmenu.ui

CONFIG += mobility
MOBILITY = 

