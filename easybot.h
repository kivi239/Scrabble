#pragma once
#include "botinterface.h"

class EasyBot : public BotInterface
{
public:
    EasyBot();
    Cell nextTurn(Field *field, Vocabulary *vocabulary);
    ~EasyBot();
};

