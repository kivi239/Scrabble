#pragma once
#include "const.h"
#include <QDebug>

class Field
{
public:
  Field();
  Field(Field &from);
  ~Field();
  char getCell(int x, int y);
  void setCell(int x, int y, char c);
  void debugOutput();

private:
  char f[Size][Size];
};

