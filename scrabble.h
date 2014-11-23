#pragma once
#include "scrabblefunc.h"
#include "keyboard.h"
#include "vocabulary.h"
#include "mainHeader.h"
#include <vector>
#include <QLabel>

namespace Ui {
class Scrabble;
}

class Scrabble : public QWidget
{
  Q_OBJECT

public:
  explicit Scrabble(int _countOfGamers, QWidget *parent = 0);
  ~Scrabble();

public slots:
  void buttonPressed();
  void letterPressed();
  void cancelPressed();
  void buttonMarked();
  void okPressed();

private:
  void generate(string word);
  void copyFromField();
  void makeEnable();
  void makeUnable();

  QPushButton *buttonFrom(pair<int, int> coord);
  Ui::Scrabble *ui;
  ScrabbleFunc *scrabble;
  std::map<QPushButton *, std::pair<int, int> > pos;
  vector<QLabel *> scoreLabels;
  Keyboard *keyboard;
  Vocabulary *vocabulary;
  std::pair<int, int> newCell;
  bool enterWord;
  vector<pair<int, int> > word;
  QPushButton *okButton, *cancelButton;
};

