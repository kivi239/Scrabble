#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <QWidget>

namespace Ui {
class Scrabble;
}

class Scrabble : public QWidget
{
  Q_OBJECT

public:
  explicit Scrabble(QWidget *parent = 0);
  ~Scrabble();

private:
  Ui::Scrabble *ui;
};

#endif // SCRABBLE_H
