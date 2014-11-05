#ifndef SCRABBLEFUNC_H
#define SCRABBLEFUNC_H

#include "field.h"
#include <string>

class ScrabbleFunc
{
public:
  ScrabbleFunc(int count);
  ~ScrabbleFunc();
  void setCell(int x, int y, char c);
  char getCell(int x, int y);

private:
  int countOfGamers;
  int gamer;
  Field field;
  Field newField;
  int *scores;
  std::string newWord;
};

#endif // SCRABBLEFUNC_H
