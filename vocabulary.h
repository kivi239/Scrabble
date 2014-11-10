#pragma once
#include "trie.h"
#include "const.h"

class Vocabulary
{
public:
    Vocabulary();
    ~Vocabulary();
    void build();
    bool add(string &word);
    string getRandomStartWord();
private:
    Trie * myTrie;
};


