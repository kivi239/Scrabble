#include "bot.h"

Bot::Bot():
  easyBot(new EasyBot),
  nyashBot(new NyashBot)
{    
}

Bot::~Bot()
{
    delete easyBot;
    delete nyashBot;
}

vector<Cell> Bot::nextTurn(int level, Field *field, Vocabulary *vocabulary)
{
    if (level <= EasyLevel)
        return nyashBot->nextTurn(field, vocabulary);
    return nyashBot->nextTurn(field, vocabulary);
}


