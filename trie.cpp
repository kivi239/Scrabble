#include "trie.h"

Trie::Trie()
{
    emptyMap.clear();
    trie.clear();
}

Trie::~Trie()
{
    for (int i = 0; i <(int)trie.size(); i++)
    {
        trie[i].second.clear();

    }
    trie.clear();
}

void Trie::add(string &word)
{
    int currentPosition = 0;
    for (int i = 0; i < (int)word.size(); i++)
    {
        int nextPosition = -1;
        if (trie[currentPosition].second.find(word[i]) == trie[currentPosition].second.end())
        {
            nextPosition = sizeOfTrie + 1;
            trie[currentPosition].second[word[i]] = nextPosition;
            trie.push_back(make_pair(0, emptyMap));
        }
        else
            nextPosition = trie[currentPosition].second[word[i]];
    }
    trie[currentPosition].first = 1;
}

bool Trie::isHave(string &word)
{
    int currentPosition = 0;
    for (int i = 0; i < (int)word.size(); i++)
    {
        if (trie[currentPosition].second.find(word[i]) == trie[currentPosition].second.end())
            return false;
        currentPosition = trie[currentPosition].second[word[i]];
    }
    return (trie[currentPosition].first == 1);
}

bool Trie::setWord(string &word)
{
    if (!isHave(word))
        return false;
    int currentPosition = 0;
    for (int i = 0; i < (int)word.size(); i++)
    {
        currentPosition = trie[currentPosition].second[word[i]];
    }
    trie[currentPosition].first = 2;
    return true;
}
