#pragma once
#include "const.h"
#include "mainHeader.h"

using namespace std;

class Trie
{
public:
  Trie();
  ~Trie();
  void add(string &word);
  bool hasWord(string &word);
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

