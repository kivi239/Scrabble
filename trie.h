#pragma once
#include <vector>
#include <map>
#include <string>

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
    map <char, int> emptyMap;
    vector < pair <int, map <char, int> > > trie;
};

