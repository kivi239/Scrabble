#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cassert>
#include <ctime>
#include <algorithm>
#include "const.h"

using namespace std;

class Trie
{
public:
    Trie();
    ~Trie();
    void add(string &word);
    bool isHave(string &word);
    bool setWord(string &word);
    string getRandomWord(int lengthOfWord);
    int nextVertex(int v, char ch);
    int getValue(int v);

private:
    int sizeOfTrie;
    void findWord(int currentVertex, int lengthOfWord, vector <string> &result, string tmpWord);
    bool isGood(string &word);
    map <char, int> emptyMap;
    vector < pair <int, map <char, int> > > trie;
    char stepsInSearch[sizeOfAlphabet];
};

