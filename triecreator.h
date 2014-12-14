#pragma once
#include "mainHeader.h"
#include <QThread>
#include "trie.h"

class TrieCreator : public QThread
{
    Q_OBJECT
public:

    TrieCreator(Trie *trie);
    void run();

signals:
    void resultReady(Trie *result);
private:
    void dfs(Trie *in, string cur, int v, Trie *out);
    Trie *myTrie;
    int tmp;
};

