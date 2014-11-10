#include "bottest.h"

BotTest::BotTest(QObject *parent) :
    QObject(parent)
{
    vocabulary = new Vocabulary;
    field = new Field;
    vocabulary->build();
}

BotTest::~BotTest()
{
    delete vocabulary;
    delete field;
}

void BotTest::printField()
{
   field->debugOutput();
}
