#include "keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
  QWidget(parent),
  layouts(nullptr)
  {}

void Keyboard::generate()
{
  layouts = new QHBoxLayout *[3];

  for (int i = 0; i < 3; i++)
  {
    layouts[i] = new QHBoxLayout;
    for (int j = 0; j < 9; j++)
    {
      if (i == 2 && j == 8)
        break;
      QPushButton *newButton = new QPushButton("" + (char)(i * 9 + j));
      layouts[i]->addWidget(newButton);
    }
  }
}

