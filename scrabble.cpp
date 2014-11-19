#include "scrabble.h"
#include "ui_scrabble.h"
#include "keyboard.h"
#include <QDebug>
#include <QFont>

Scrabble::Scrabble(int _countOfGamers, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Scrabble),
  scrabble(new ScrabbleFunc(_countOfGamers)),
  keyboard(nullptr),
  newCell(std::make_pair(-1, -1)),
  vocabulary(new Vocabulary)
{
  ui->setupUi(this);
  generate();

}

Scrabble::~Scrabble()
{
  delete vocabulary;
  delete ui;
}

void Scrabble::generate()
{
  for (int i = 0; i < Size; i++)
    for (int j = 0; j < Size; j++)
    {
      QPushButton *button = new QPushButton;
      button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      pos[button] = std::make_pair(i, j);
      ui->gridLayout->addWidget(button, i, j);
      connect(button, &QPushButton::clicked, this, &Scrabble::buttonPressed);
    }
}

void Scrabble::buttonPressed()
{
  delete keyboard;
  keyboard = new Keyboard();
  connect(keyboard, &Keyboard::throwSignal, this, &Scrabble::letterPressed);
  QPushButton *button = dynamic_cast<QPushButton *>(sender());
  newCell = pos[button];
  for (std::map<QPushButton*, std::pair<int, int> > ::iterator it = pos.begin(); it != pos.end(); it++)
    it->first->setEnabled(false);
  button->setStyleSheet("background-color: rgb(175, 238, 238)");
  ui->verticalLayout->addWidget(keyboard);
}

void Scrabble::letterPressed()
{
  if (!keyboard)
    return;
  char letter = keyboard->getLetter();
  scrabble->setCell(newCell.first, newCell.second, letter);
  QPushButton *button = nullptr;
  for (std::map<QPushButton *, std::pair<int, int> >::iterator it = pos.begin(); it != pos.end(); it++)
    if (it->second == newCell)
    {
      button = it->first;
      break;
    }
  assert(button != nullptr);
  QString str = "";
  str += letter;
  button->setText(str);
}
