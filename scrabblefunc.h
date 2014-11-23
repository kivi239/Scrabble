#pragma once
#include "field.h"
#include "mainHeader.h"

class ScrabbleFunc
{
public:
  ScrabbleFunc(int count);
  ~ScrabbleFunc();
  void setCell(int x, int y, char c);
  char getCell(int x, int y);
  char getOldCell(int x, int y);
  bool isIsolated(int x, int y);
  bool areNeigbors(int x1, int y1, int x2, int y2);
  void updateField();
  void cancelFieldChange();
  void changeGamer();
  void updateScore(int score);
  int getScore(int numberOfGamer);
  int getCount();
  int getGamer();
  bool endOfGame();

private:
  int countOfGamers;
  int gamer;
  Field field;
  Field newField;
  int *scores;
  std::string newWord;
};

