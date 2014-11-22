#pragma once
#include "scrabblefunc.h"
#include "keyboard.h"
#include "vocabulary.h"
#include "mainHeader.h"

namespace Ui {
class Scrabble;
}

class Scrabble : public QWidget
{
  Q_OBJECT

public:
  explicit Scrabble(int _countOfGamers, QWidget *parent = 0);
  ~Scrabble();
  void generate(string word);
  void copyFromField();

public slots:
  void buttonPressed();
  void letterPressed();
  void cancelPressed();

private:
  Ui::Scrabble *ui;
  ScrabbleFunc *scrabble;
  std::map<QPushButton *, std::pair<int, int> > pos;
  Keyboard *keyboard;
  Vocabulary *vocabulary;
  std::pair<int, int> newCell;
  bool enterWord;
};

