#pragma once

#include <QWidget>

namespace Ui {
class StartMenu;
}

class StartMenu : public QWidget
{
  Q_OBJECT

public:
  explicit StartMenu(QWidget *parent = 0);
  ~StartMenu();

signals:
  void startGame();

private:
  Ui::StartMenu *ui;
};


