#include "scrabble.h"
#include "vocabularytest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  VocabularyTest vTest;
  QTest::qExec(&vTest);
  QApplication a(argc, argv);
  Scrabble w(2);
  w.show();

  return a.exec();
}
