#pragma once
#include "trie.h"
#include "const.h"
#include "mainHeader.h"

class Vocabulary
{
public:
  Vocabulary();
  ~Vocabulary();
  void build();
  bool add(string &word);
  string getRandomStartWord();
  Trie *getTrie();

private:
  Trie * myTrie;
};


