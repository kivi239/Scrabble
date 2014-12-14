#include "field.h"

Field::Field()
{
  for (int i = 0; i < Size; i++)
    for (int j = 0; j < Size; j++)
      f[i][j] = '\0';
}

Field::Field(Field &from)
{
  for (int i = 0; i < Size; i++)
    for (int j = 0; j < Size; j++)
      f[i][j] = from.f[i][j];
}

Field::~Field() {}

char Field::getCell(int x, int y)
{
  if (x < 0 || x >= Size || y < 0 || y >= Size)
    return '!';
  return f[x][y];
}

void Field::setCell(int x, int y, char c)
{
  if (x < 0 || x >= Size || y < 0 || y >= Size)
    return;
  if (f[x][y] != '\0')
    return;
  f[x][y] = c;
}

void Field::debugOutput()
{
    for (int i = 0; i < Size; i++)
    {
        QString nobodyReadsIt = "";
        for (int j = 0; j < Size; j++)
           nobodyReadsIt += f[i][j];
        qDebug() << nobodyReadsIt;
        qDebug() << '\n';
    }
}
