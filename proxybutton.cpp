#include "proxybutton.h"
#include <QPainter>

ProxyButton::ProxyButton(QWidget *parent) :
  QPushButton(parent)
{

}

void ProxyButton::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/peachColor.png").scaled(size()));

  QWidget::paintEvent(e);
}

