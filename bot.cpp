#include "bot.h"

Bot::Bot(QObject *parent) :
    QObject(parent),
easyBot(new EasyBot)
{
    isBuildNow = false;
    finishCreator = false;
    tmpWords.clear();
}

Bot::~Bot()
{
    delete easyBot;
    if (finishCreator)
        delete nyashBot;
    if (isBuildNow)
    {
        //delete tGenerator;
        // возможно он уже удалил это все в отложенном делите
    }
    tmpWords.clear();
}

vector<Cell> Bot::nextTurn(int level, Field *field, Vocabulary *vocabulary)
{
    if (rand() % 100 < 2)
        level = 100;
    // the catch with love

    if (!isBuildNow && level >= EasyLevel)
    {
        isBuildNow = true;
        tGenerator = new TrieCreator(vocabulary->getTrie());

        connect(tGenerator, SIGNAL(resultReady(Trie*)), this, SLOT(createNyashBot(Trie*)));
        connect(tGenerator, SIGNAL(finished()), tGenerator, SLOT(deleteLater()));
        tGenerator->start();
    }
    if (level <= EasyLevel || (!finishCreator))
        return easyBot->nextTurn(field, vocabulary);
    else
    {
        while ((int)tmpWords.size() > 0)
        {
            nyashBot->addWord(tmpWords.back());
            tmpWords.pop_back();
        }
        qDebug() << "i am";
        return nyashBot->nextTurn(field, vocabulary);
    }
}

void Bot::createNyashBot(Trie *t)
{
    finishCreator = true;
    nyashBot = new NyashBot(t);
}

void Bot::addWord(string const &word)
{
    tmpWords.push_back(word);
}
