#pragma once
#include "mainHeader.h"
#include "scrabble.h"
#include "maindatabase.h"
#include "changeusersform.h"

namespace Ui {
class StartMenu;
}

class StartMenu : public QWidget
{
  Q_OBJECT

public:
  explicit StartMenu(QWidget *parent = 0);
  ~StartMenu();


void paintEvent(QPaintEvent *);


signals:
  void startSimpleGame();
  void startAgainstAndroid();

private slots:
    void againstAndroid();
    void singleGame();
    void endOfAndroidSessison();
    void endOfSimpleSession();
    void forceExit();
    void showPLayers();
    void closeUsersForm();

private:
  bool isPlayingNow;
  Ui::StartMenu *ui;
  Scrabble *game;
  MainDataBase *db;
  ChangeUsersForm *uList;
};


