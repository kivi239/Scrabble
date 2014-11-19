#include "vocabulary.h"
#include <fstream>
#include <QDebug>
#include <QFile>

Vocabulary::Vocabulary()
{
    myTrie = new Trie();    
}

Vocabulary::~Vocabulary()
{
    delete myTrie;
}

void Vocabulary::build()
{    
    QFile reader(":/new/prefix1/vocabulary.txt");
    if (!reader.open(QIODevice::ReadOnly | QIODevice::Text))
    {
    }
    QTextStream inReader(&reader);
    string wordFromDictionary;
    while(!inReader.atEnd())
    {
        QString wordTmp = inReader.readLine();
        wordFromDictionary = "";
        for (int i = 0; i < wordTmp.size(); ++i)
            wordFromDictionary += wordTmp[i].toLatin1();
        if ((int)wordFromDictionary.size() < 3)
            continue;
        myTrie->add(wordFromDictionary);
    }    
}

bool Vocabulary::add(string &word)
{
    bool result = myTrie->setWord(word);
    return result;
}

string Vocabulary::getRandomStartWord()
{
    return myTrie->getRandomWord(Size);
}

Trie *Vocabulary::getTrie()
{
    return myTrie;
}

