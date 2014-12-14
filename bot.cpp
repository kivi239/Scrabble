#include "bot.h"

Bot::Bot(bool hard):
  easyBot(new EasyBot),
  nyashBot(new NyashBot),
  hard(hard)
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


