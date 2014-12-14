#pragma once
#include "mainHeader.h"
#include "field.h"
#include "vocabulary.h"
#include "easybot.h"
#include "nyashbot.h"

class Bot
{
public:
    Bot(bool hard);
    ~Bot();
    vector<Cell> nextTurn(int level, Field *field, Vocabulary *vocabulary);
private:
    EasyBot *easyBot;
    NyashBot *nyashBot;
    bool hard;
};

