#include "scrabble.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Scrabble w;
  w.show();

  return a.exec();
}
