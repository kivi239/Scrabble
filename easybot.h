#pragma once
#include "botinterface.h"

class EasyBot : public BotInterface
{
public:
    EasyBot();
    vector<Cell> nextTurn(Field *field, Vocabulary *vocabulary);
    ~EasyBot();
private:
    void searchWords(int currentVertex, int remainingLength, int currentX, int currentY);
    vector < vector <Cell> > results;
    vector < Cell > tmpWord;
    char stepsInSearch[sizeOfAlphabet];
    Trie *botTrie;
    Field *botField;
    int * directionX;
    int * directionY;
    bool used[Size][Size];
};

