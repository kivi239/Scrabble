#pragma once
#include "botinterface.h"
#include "mainHeader.h"

typedef pair<int, int> pii;

class NyashBot : public BotInterface
{
public:
    NyashBot();
    vector<Cell> nextTurn(Field *field, Vocabulary *vocabulary);
    ~NyashBot();
    bool ls1(const vector<pii> &a, const vector<pii> &b);

  private:
    Trie *changed;
    int initialized;

    vector < vector <Cell> > results;
    Trie *botTrie;
    Field *botField;
    void modify(vector<string> &area, pair<vector<pii>, string> a);
    string getWord(const vector<string> &area, const vector<pii> &figure);
    void dfs(Trie *in, string cur, int v, Trie *out);
    void gen(const vector<string> &area, int vertex, pair<vector<pii>, string> cur, int n);
    pair<vector<pii>, string> getTheBestWord(vector<string> area, pii point, Trie *vocab);
    pair<vector<pii>, string> deepOptimise(vector<string> area, Trie *vocab, int &bestscore, int deepening);
    pair<vector<pii>, string> deepOptimise(vector<string> area, Trie *vocab);
    vector<vector<bool> > used;
    pair<vector<pii>, string> ans, cur;
    int bestAnswer;
    int go[4][2];
};
