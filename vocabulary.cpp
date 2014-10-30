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
    ifstream reader;
    reader.open("vocabulary.txt");
    string wordFromDictionary;
    while(reader >> wordFromDictionary)
    {
        myTrie->add(wordFromDictionary);
    }    
}

bool Vocabulary::add(string &word)
{
    bool result = myTrie->setWord(word);
    return result;
}

