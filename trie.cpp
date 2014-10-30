#include "trie.h"
#include <QDebug>

Trie::Trie()
{
    emptyMap.clear();
    trie.clear();
    trie.push_back(make_pair(0, emptyMap));
    sizeOfTrie = 0;
}

Trie::~Trie()
{
    for (int i = 0; i <(int)trie.size(); i++)
    {
        trie[i].second.clear();

    }
    trie.clear();
    sizeOfTrie = 0;
}

bool Trie::isGood(string &word)
{
    for (int i = 0; i < (int)word.size(); i++)
    {
        if ('a' <= word[i] && word[i] <= 'z')
            continue;
        return false;
    }
    return true;
}

void Trie::add(string &word)
{
    if (!isGood(word))
        return;
    int currentPosition = 0;
    for (int i = 0; i < (int)word.size(); i++)
    {       
        int nextPosition = -1;

        if (trie[currentPosition].second.find(word[i]) == trie[currentPosition].second.end())
        {
            sizeOfTrie++;
            nextPosition = sizeOfTrie;
            trie[currentPosition].second[word[i]] = nextPosition;
            trie.push_back(make_pair(0, emptyMap));
        }
        else
            nextPosition = trie[currentPosition].second[word[i]];
        assert(nextPosition != -1);
        currentPosition = nextPosition;
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
