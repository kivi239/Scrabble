#pragma once
#include <QWidget>
#include <map>
#include <QHBoxLayout>
#include <QPushButton>

class Keyboard : public QWidget
{
  Q_OBJECT
public:
  explicit Keyboard(QWidget *parent = 0);

signals:

public slots:


private:
  void generate();
  QHBoxLayout **layouts;
};
