#include "scrabble.h"
#include "vocabularytest.h"
#include <QApplication>
#include "bottest.h"
#include "startmenu.h"

int main(int argc, char *argv[])
{
  srand (time (0));
  VocabularyTest vTest;
  QTest::qExec(&vTest);
  BotTest bTest;
  QTest::qExec(&bTest);
  QApplication a(argc, argv);
  Scrabble w(2);
  StartMenu gameMenu;
  QObject::connect(&gameMenu, SIGNAL(startGame()), &w, SLOT(show()));
  gameMenu.show();
  return a.exec();
}
