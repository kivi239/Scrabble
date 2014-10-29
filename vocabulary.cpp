#include "vocabulary.h"
#include <fstream>
#include <QDebug>

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
    q
    ifstream reader("vocabulary.txt");
    string wordFromDictionary;
    int x = 0;
    reader >> wordFromDictionary;
    {
        x++;
        myTrie->add(wordFromDictionary);
    }
    qDebug() << x;
}

bool Vocabulary::add(string &word)
{
    bool result = myTrie->setWord(word);
    return result;
}

