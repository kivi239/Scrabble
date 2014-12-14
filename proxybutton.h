#ifndef PROXYBUTTON_H
#define PROXYBUTTON_H

#include <QPushButton>

class ProxyButton : public QPushButton
{
  Q_OBJECT
public:
  explicit ProxyButton(QWidget *parent = 0);
  void paintEvent(QPaintEvent *e);

signals:

public slots:

};

#endif // PROXYBUTTON_H
