#ifndef SCRABBLE_H
#define SCRABBLE_H

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
  explicit Scrabble(QWidget *parent = 0);
  ~Scrabble();
  void generate();

private:
  Ui::Scrabble *ui;
  ScrabbleFunc *scrabble;
  std::map<QPushButton *, std::pair<int, int> > pos;
};

#endif // SCRABBLE_H
