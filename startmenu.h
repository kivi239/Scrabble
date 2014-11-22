#pragma once
#include "mainHeader.h"

namespace Ui {
class StartMenu;
}

class StartMenu : public QWidget
{
  Q_OBJECT

public:
  explicit StartMenu(QWidget *parent = 0);
  ~StartMenu();


void paintEvent(QPaintEvent *);


signals:
  void startGame();

private:
  Ui::StartMenu *ui;
};


