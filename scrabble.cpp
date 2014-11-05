#include "scrabble.h"
#include "ui_scrabble.h"
#include "keyboard.h"
#include <QDebug>

Scrabble::Scrabble(int _countOfGamers, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Scrabble),
  scrabble(new ScrabbleFunc(_countOfGamers))
{
  ui->setupUi(this);
  generate();
}

Scrabble::~Scrabble()
{
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
  qDebug() << "here\n";
  QPushButton *button = dynamic_cast<QPushButton *>(sender());
  int x = pos[button].first, y = pos[button].second;
  Keyboard *keyboard = new Keyboard();
  ui->verticalLayout->addWidget(keyboard);
  keyboard->show();
}
