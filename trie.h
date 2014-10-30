#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Trie
{
public:
    Trie();
    ~Trie();
    void add(string &word);
    bool isHave(string &word);
    bool setWord(string &word);

private:
    int sizeOfTrie;
    bool isGood(string &word);
    map <char, int> emptyMap;
    vector < pair <int, map <char, int> > > trie;
};

