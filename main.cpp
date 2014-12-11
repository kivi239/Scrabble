#include "scrabble.h"
#include "vocabularytest.h"
#include "dtabasetest.h"
#include <QApplication>
#include "bottest.h"
#include "startmenu.h"

int main(int argc, char *argv[])
{
  Q_INIT_RESOURCE(MyRes);
  srand (time (0));
 /*
  VocabularyTest vTest;  
  QTest::qExec(&vTest);
  BotTest bTest;
  QTest::qExec(&bTest);
  DtaBaseTest dTest;
  QTest::qExec(&dTest);
 */

  QApplication a(argc, argv);
  //Scrabble w(2, true);
  StartMenu gameMenu;
  gameMenu.show();
  a.exit();
  exit(a.exec());
}
