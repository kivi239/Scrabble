#include "startmenu.h"
#include "ui_startmenu.h"
#include <QPainter>

StartMenu::StartMenu(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::StartMenu),
  game(nullptr),
  db(new MainDataBase("ProjectGame.sqlite"))
{

  isPlayingNow = false;
  ui->setupUi(this);
  playerName = "Guest";
  vector <QString> allUsers = db->getAllUsers();
  if (allUsers.size())
      playerName = allUsers[0];
  mainUser = db->getUser(playerName);

  changeLabel();

  connect(ui->startGameButton, SIGNAL(clicked()), SIGNAL(startSimpleGame()));
  connect(ui->startGameButton, SIGNAL(clicked()), SLOT(hide()));
  connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(forceExit()));
  connect(ui->againstAndroid, SIGNAL(clicked()), SIGNAL(startAgainstAndroid()));
  connect(ui->againstAndroid, SIGNAL(clicked()), SLOT(hide()));
  connect(this, SIGNAL(startAgainstAndroid()), this, SLOT(againstAndroid()));
  connect(this, SIGNAL(startSimpleGame()), this, SLOT(singleGame()));
  connect(ui->changePlayer, SIGNAL(clicked()), this, SLOT(showPLayers()));
}

StartMenu::~StartMenu()
{
  delete game;
  delete ui;
}

void StartMenu::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
//  painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/background.jpg").scaled(size()));
  painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/mainBackground.jpg").scaled(size()));

  QWidget::paintEvent(e);
}

void StartMenu::againstAndroid()
{
  if (isPlayingNow)
      return;
  isPlayingNow = true;
  game = new Scrabble(2, true);
  //this->hide();
  connect(game, SIGNAL(endOfGame()), this, SLOT(endOfAndroidSessison()));
  game->show();
}

void StartMenu::singleGame()
{
  if (isPlayingNow)
      return;
  isPlayingNow = true;
  game = new Scrabble(2, false);
  //this->hide();
  connect(game, SIGNAL(endOfGame()), this, SLOT(endOfSimpleSession()));
  game->show();
}

void StartMenu::endOfAndroidSessison()
{  
  game->close();
  delete game;
  game = nullptr;
  this->show();
  isPlayingNow = false;
}

void StartMenu::endOfSimpleSession()
{  
  game->close();
  delete game;
  game = nullptr;
  this->show();
  isPlayingNow = false;
}

void StartMenu::forceExit()
{
  delete game;
  delete uList;
  delete ui;
  this->close();
}

void StartMenu::showPLayers()
{
    //db->getUser("anton");
    //db->getUser("toha");
    vector <QString> allUsers = db->getAllUsers();
    if (uList == nullptr)
        uList = new ChangeUsersForm();
    uList->addUsers(allUsers);
    connect(uList, SIGNAL(exitForm()), this, SLOT(closeUsersForm()));
    connect(uList, SIGNAL(player(QString)), this, SLOT(changePlayer(QString)));
    //this->hide();
    uList->show();
}

void StartMenu::closeUsersForm()
{
    this->show();
    uList->hide();
}


void StartMenu::changePlayer(QString x)
{
    QString newS = x;
    mainUser = db->getUser(newS);
    closeUsersForm();
    changeLabel();
}

void StartMenu::changeLabel()
{
    ui->label->setText("Welcome, " + mainUser.getFullName());
}

