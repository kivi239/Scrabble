#include "keyboard.h"
#include <QString>

Keyboard::Keyboard(QWidget *parent) :
  QWidget(parent),
  layouts(nullptr),
  layout(new QVBoxLayout)
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
      QString letter= "";
      letter += (char)('a' + i * 9 + j);
      QPushButton *newButton = new QPushButton(letter);
      newButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      layouts[i]->addWidget(newButton);
    }
  }

  for (int i = 0; i < 3; i++)
    layout->addLayout(layouts[i]);
  setLayout(layout);
}

