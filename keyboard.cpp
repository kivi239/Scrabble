#include "keyboard.h"
#include <QString>

Keyboard::Keyboard(QWidget *parent) :
  QWidget(parent),
  layouts(nullptr),
  layout(new QVBoxLayout),
  letter('\0')
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
      buttons[newButton] = (char)('a' + i * 9 + j);
      newButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      layouts[i]->addWidget(newButton);
      connect(newButton, &QPushButton::clicked, this, &Keyboard::letterPressed);
    }
  }

  for (int i = 0; i < 3; i++)
    layout->addLayout(layouts[i]);
  setLayout(layout);
}

void Keyboard::makeEnable()
{
  for (std::map<QPushButton *, char>::iterator it = buttons.begin(); it != buttons.end(); it++)
    (it)->first->setEnabled(true);
}

void Keyboard::makeUnable()
{
  for (std::map<QPushButton *, char>::iterator it = buttons.begin(); it != buttons.end(); it++)
    (it)->first->setEnabled(false);
}

void Keyboard::letterPressed()
{
  makeUnable();
  QPushButton *button = dynamic_cast<QPushButton *>(sender());
  letter = buttons[button];
  throwSignal();
}

char Keyboard::getLetter()
{
  return letter;
}
