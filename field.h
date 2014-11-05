#pragma once
#include "const.h"

class Field
{
public:
  Field();
  Field(Field &from);
  ~Field();
  char getCell(int x, int y);
  void setCell(int x, int y, char c);

private:
  char f[Size][Size];
};

