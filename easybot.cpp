#include "easybot.h"

EasyBot::EasyBot()
{
    for (int i = 0; i < sizeOfAlphabet; i++)
        stepsInSearch[i] = (char)('a' + i);
    directionX = new int[directionNumber];//{0, 0, -1, 1};
    directionX[0] = 0;
    directionX[1] = 0;
    directionX[2] = -1;
    directionX[3] = 1;
    directionY = new int[directionNumber];//{-1, 1, 0, 0};
    directionY[0] = -1;
    directionY[1] = 1;
    directionY[2] = 0;
    directionY[3] = 0;
}

vector <Cell> EasyBot::nextTurn(Field *field, Vocabulary *vocabulary)
{
    botTrie = vocabulary->getTrie();
    botField = field;
    results.clear();  

    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            if (field->getCell(i, j) != '\0')
            {
                random_shuffle(stepsInSearch, stepsInSearch + sizeOfAlphabet);
                if ((int)results.size() >= 10)
                    break;

                tmpWord.clear();
                for (int dx = 0; dx < Size; dx++)
                    for (int dy = 0; dy < Size; dy++)
                        used[dx][dy] = false;

                searchWords(0, 5, i, j);
            }

    random_shuffle(results.begin(), results.end());
    return results[0];
}

EasyBot::~EasyBot()
{
    delete[] directionX;
    delete[] directionY;
}

void EasyBot::searchWords(int currentVertex, int remainingLength, int currentX, int currentY)
{
    if ((int)results.size() >= 10)
        return;

    if (remainingLength == 0)
    {
        if (botTrie->getValue(currentVertex) == 1 && botField->getCell(currentX, currentY) == '\0')
        {
            results.push_back(tmpWord);
        }
        return;
    }
    used[currentX][currentY] = true;
    for (int directionId = 0; directionId < directionNumber; directionId++)
    {
        int nextX = currentX + directionX[directionId];
        int nextY = currentY + directionY[directionId];
        char ch = botField->getCell(nextX, nextY);
        if (ch == '!')
            continue;
        if (ch == '\0')
        {
            if (used[nextX][nextY])
                continue;

            for (int letterId = 0; letterId < sizeOfAlphabet; letterId++)
            {
                int nextVertex = botTrie->nextVertex(currentVertex, stepsInSearch[letterId]);
                if (nextVertex > 0)
                {
                    tmpWord.push_back(Cell(nextX, nextY, stepsInSearch[letterId]));
                    searchWords(nextVertex, 0, nextX, nextY);
                    tmpWord.pop_back();
                }
                if ((int)results.size() >= 10)
                    return;
            }
            continue;
        }

        if (used[nextX][nextY])
            continue;

        int nextVertex = botTrie->nextVertex(currentVertex, ch);
        if (nextVertex > 0)
        {
            tmpWord.push_back(Cell(nextX, nextY, ch));
            searchWords(nextVertex, remainingLength - 1, nextX, nextY);
            tmpWord.pop_back();
        }
    }

    if ((int)results.size() >= 10)
        return;

    used[currentX][currentY] = false;
}
