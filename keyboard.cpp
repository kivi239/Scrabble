#include "keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
  QWidget(parent),
  layouts(nullptr),
  layout(nullptr)
{
  generate();
}

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
      newButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      layouts[i]->addWidget(newButton);
    }
  }

  for (int i = 0; i < 3; i++)
    layout->addLayout(layouts[i]);
  //setLayout(layout);
}

