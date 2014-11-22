#pragma once
#include "mainHeader.h"

class Cell
{
public:    
    Cell();
    Cell(int x, int y, char ch);
    int getX();
    int getY();
    char getCh();
    ~Cell();

public:
    int x, y;
    char ch;
};

