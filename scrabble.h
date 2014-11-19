#pragma once
#include <QWidget>
#include "scrabblefunc.h"
#include <map>
#include <QPushButton>
#include "keyboard.h"
#include "vocabulary.h"

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
  void copyFromField();

public slots:
  void buttonPressed();
  void letterPressed();

private:
  Ui::Scrabble *ui;
  ScrabbleFunc *scrabble;
  std::map<QPushButton *, std::pair<int, int> > pos;
  Keyboard *keyboard;
  Vocabulary *vocabulary;
  std::pair<int, int> newCell;
};

