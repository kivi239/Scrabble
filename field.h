#ifndef FIELD_H
#define FIELD_H

#include "const.h"

class Field
{
public:
  Field();
  Field(Field &from);
  ~Field();
  char getCell(int x, int y);
  void setCell(int x, int y, char c);
  static const int size = 5;

private:
  char f[size][size];
};

#endif // FIELD_H
