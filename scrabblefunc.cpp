#include "scrabblefunc.h"

ScrabbleFunc::ScrabbleFunc(int count) : countOfGamers(count), gamer(0), field(), newField(field),
                                        scores(new int[countOfGamers]), newWord("") {}

void ScrabbleFunc::setCell(int x, int y, char c)
{
  field.setCell(x, y, c);
}

char ScrabbleFunc::getCell(int x, int y)
{
  return field.getCell(x, y);
}
