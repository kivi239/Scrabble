#include "bot.h"

Bot::Bot():
easyBot(new EasyBot)
{    
}

Bot::~Bot()
{
    delete easyBot;
}

vector<Cell> Bot::nextTurn(int level, Field *field, Vocabulary *vocabulary)
{
    if (level <= EasyLevel)
        return easyBot->nextTurn(field, vocabulary);
    return easyBot->nextTurn(field, vocabulary);
}


