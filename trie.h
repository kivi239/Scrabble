#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cassert>
#include <ctime>

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

private:
    int sizeOfTrie;
    void findWord(int currentVertex, int lengthOfWord, vector <string> &result, string tmpWord);
    bool isGood(string &word);
    map <char, int> emptyMap;
    vector < pair <int, map <char, int> > > trie;
    char stepsInSearch[26];
};

