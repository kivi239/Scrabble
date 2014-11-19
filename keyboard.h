#pragma once
#include <QWidget>
#include <map>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

class Keyboard : public QWidget
{
  Q_OBJECT
public:
  explicit Keyboard(QWidget *parent = 0);
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
