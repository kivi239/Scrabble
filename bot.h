#pragma once
#include "mainHeader.h"
#include "field.h"
#include "vocabulary.h"
#include "easybot.h"
#include "nyashbot.h"
#include "triecreator.h"

class Bot : public QObject
{
    Q_OBJECT
public:
    explicit Bot(QObject *parent = 0);
    ~Bot();
    vector<Cell> nextTurn(int level, Field *field, Vocabulary *vocabulary);
    void addWord(const string &word);

private slots:
    void createNyashBot(Trie *t);
private:
    EasyBot *easyBot;
    NyashBot *nyashBot;
    TrieCreator *tGenerator;
    bool isBuildNow;
    bool finishCreator;
    vector <string> tmpWords;
};

