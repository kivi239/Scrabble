#pragma once
#include <QPushButton>

class FieldButton : public QPushButton
{
  Q_OBJECT
public:
  explicit FieldButton(QWidget *parent = 0);
  int heightForWidth(int) const;

};


