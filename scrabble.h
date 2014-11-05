#pragma once
#include <QWidget>
#include "scrabblefunc.h"
#include <map>
#include <QPushButton>

namespace Ui {
class Scrabble;
}

class Scrabble : public QWidget
{
  Q_OBJECT

public:
  explicit Scrabble(int _countOfGamers, QWidget *parent = 0);
  ~Scrabble();
  void generate();

public slots:
  void buttonPressed();

private:
  Ui::Scrabble *ui;
  ScrabbleFunc *scrabble;
  std::map<QPushButton *, std::pair<int, int> > pos;
};

