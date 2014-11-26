#pragma once
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include "mainHeader.h"

class Keyboard : public QWidget
{
  Q_OBJECT
public:
  explicit Keyboard(QWidget *parent = 0);
  ~Keyboard();
  void makeEnable();
  void makeUnable();

signals:

public slots:
  void letterPressed();
  char getLetter();

signals:
  void throwSignal();

private:
  void generate();
  QHBoxLayout **layouts;
  QVBoxLayout *layout;
  std::map<QPushButton *, char> buttons;
  char letter;
};
