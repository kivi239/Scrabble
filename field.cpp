#include "field.h"

Field::Field()
{
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      f[i][j] = '\0';
}

Field::Field(Field &from)
{
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      f[i][j] = from.f[i][j];
}

Field::~Field() {}

char Field::getCell(int x, int y)
{
  if (x < 0 || x >= size || y < 0 || y >= size)
    return '\0';
  return f[x][y];
}

void Field::setCell(int x, int y, char c)
{
  if (x < 0 || x >= size || y < 0 || y >= size)
    return;
  if (f[x][y] != '\0')
    return;
  f[x][y] = c;
}
