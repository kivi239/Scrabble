#include "triecreator.h"

TrieCreator::TrieCreator(Trie *trie)
{
    myTrie = trie;
}


void TrieCreator::run()
{
    tmp = 0;
    Trie *result = new Trie();
    dfs(myTrie, "", 0, result);
    emit resultReady(result);
}

void TrieCreator::dfs(Trie *in, string cur, int v, Trie *out)
{
    if (in->getValue(v) == 1)
    {
       for (int i = 0; i < (int)cur.size(); i++)
       {
           string ncur = cur;
           ncur[i] = 'X';
           out->add(ncur);
       }
    }
    for (char a = 'a'; a <= 'z'; a++)
    {
        if (in->nextVertex(v, a) == -1) continue;
        string nc = cur;
        nc.push_back(a);
        dfs(in, nc, in->nextVertex(v, a), out);
    }
}
