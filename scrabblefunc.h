#pragma once
#include "field.h"
#include <string>

class ScrabbleFunc
{
public:
  ScrabbleFunc(int count);
  ~ScrabbleFunc();
  void setCell(int x, int y, char c);
  char getCell(int x, int y);
  char getOldCell(int x, int y);
  void updateField();
  void cancelFieldChange();

private:
  int countOfGamers;
  int gamer;
  Field field;
  Field newField;
  int *scores;
  std::string newWord;
};

