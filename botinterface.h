#pragma once
#include "field.h"
#include "vocabulary.h"
#include "cell.h"

class BotInterface
{
public:
    BotInterface();
    virtual Cell nextTurn(Field *field, Vocabulary *vocabulary) = 0;
    virtual ~BotInterface() = 0;
};

