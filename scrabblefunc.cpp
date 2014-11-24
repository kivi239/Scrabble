#include "scrabblefunc.h"

ScrabbleFunc::ScrabbleFunc(int count) : countOfGamers(count), gamer(0), field(), newField(field),
                                        scores(new int[countOfGamers]), newWord("")
{
  for (int i = 0; i < countOfGamers; i++)
    scores[i] = 0;
}

void ScrabbleFunc::setCell(int x, int y, char c)
{
  newField.setCell(x, y, c);
}

char ScrabbleFunc::getCell(int x, int y)
{
  return newField.getCell(x, y);
}

void ScrabbleFunc::updateField()
{
  field = newField;
}

void ScrabbleFunc::cancelFieldChange()
{
  newField = field;
}

void ScrabbleFunc::updateScore(int score)
{
  scores[gamer] += score;
}

int ScrabbleFunc::getScore(int numberOfGamer)
{
  if (numberOfGamer >= 0 && numberOfGamer < countOfGamers)
    return scores[numberOfGamer];
  return 0;
}

int ScrabbleFunc::getCount()
{
  return countOfGamers;
}

int ScrabbleFunc::getGamer()
{
  return gamer;
}

bool ScrabbleFunc::endOfGame()
{
  for (int i = 0; i < Size; i++)
    for (int j = 0; j < Size; j++)
      if (getOldCell(i, j) == '\0')
        return false;
  return true;
}

Field *ScrabbleFunc::getField()
{
    return &field;
}

char ScrabbleFunc::getOldCell(int x, int y)
{
  return field.getCell(x, y);
}

void ScrabbleFunc::changeGamer()
{
  gamer++;
  gamer %= countOfGamers;
}

bool ScrabbleFunc::isIsolated(int x, int y)
{
  int moveX[4] = {1, -1, 0, 0};
  int moveY[4] = {0, 0, 1, -1};
  for (int i = 0; i < 4; i++)
    if (x + moveX[i] >= 0 && x + moveX[i] < Size
        && y + moveY[i] >= 0 && y + moveY[i] < Size
        && field.getCell(x + moveX[i], y + moveY[i]) != '!' && field.getCell(x + moveX[i], y + moveY[i]) != '\0')
      return false;
  return true;
}

bool ScrabbleFunc::areNeigbors(int x1, int y1, int x2, int y2)
{
  return (abs(x1 - x2) + abs(y1 - y2) == 1);
}
