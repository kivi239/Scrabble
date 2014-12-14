#include <QResizeEvent>
#include "fieldbutton.h"

FieldButton::FieldButton(QWidget *parent) :
  QPushButton(parent)
{
  QSizePolicy p(QSizePolicy::Preferred, QSizePolicy::Preferred);
  p.setHeightForWidth(true);
  setSizePolicy(p);
  setStyleSheet("background-color: rgb(255, 228, 225);");
}

int FieldButton::heightForWidth(int w) const
{
  return w;
}
