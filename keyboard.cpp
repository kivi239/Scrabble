#include "keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
  QWidget(parent),
  layouts(nullptr),
  layout(new QVBoxLayout),
  letter('\0')
{
  generate();
}

Keyboard::~Keyboard()
{
  for (int i = 0; i < 3; i++)
    delete layouts[i];
  delete layouts;
  delete layout;
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
      //newButton->setStyleSheet("background-color: rgb(255, 228, 225); ");
      newButton->setStyleSheet("QPushButton {color:black;background-color: rgb(255, 228, 225); border-radius: 20px; border-top: 20px transparent; border-bottom: 20px transparent; border-right: 100px transparent; border-left: 100px transparent; min-height: 1.6em; min-width: 1em; font: 100 16pt \"System\";}");

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
