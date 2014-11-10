#include "scrabble.h"
#include "vocabularytest.h"
#include <QApplication>
#include "bottest.h"

int main(int argc, char *argv[])
{
  srand (time (0));
  VocabularyTest vTest;
  QTest::qExec(&vTest);
  BotTest bTest;
  QTest::qExec(&bTest);
  QApplication a(argc, argv);
  Scrabble w(2);
  w.show();

  return a.exec();
}
