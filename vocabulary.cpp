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

