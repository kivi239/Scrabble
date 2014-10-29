#include "scrabble.h"
#include "ui_scrabble.h"

Scrabble::Scrabble(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Scrabble)
{
  ui->setupUi(this);
}

Scrabble::~Scrabble()
{
  delete ui;
}
