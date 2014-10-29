#pragma once
#include "trie.h"

class Vocabulary
{
public:
    Vocabulary();
    ~Vocabulary();
    void build();
    bool add(string &word);
private:
    Trie * myTrie;
};


