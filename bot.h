#pragma once
#include "mainHeader.h"
#include "field.h"
#include "vocabulary.h"
#include "easybot.h"

class Bot
{
public:
    Bot();
    ~Bot();
    vector<Cell> nextTurn(int level, Field *field, Vocabulary *vocabulary);
private:
    EasyBot *easyBot;
};

