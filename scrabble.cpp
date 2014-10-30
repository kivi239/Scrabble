#include "scrabble.h"
#include "ui_scrabble.h"

Scrabble::Scrabble(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Scrabble),
  scrabble(new ScrabbleFunc(2))
{
  ui->setupUi(this);
  generate();
}

Scrabble::~Scrabble()
{
  //delete scrabble;
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
    }
}
