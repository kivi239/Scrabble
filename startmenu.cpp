#include "startmenu.h"
#include "ui_startmenu.h"
#include <QPainter>

StartMenu::StartMenu(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::StartMenu),
  game(nullptr)
{
  ui->setupUi(this);
  connect(ui->startGameButton, SIGNAL(clicked()), SIGNAL(startSimpleGame()));
  connect(ui->startGameButton, SIGNAL(clicked()), SLOT(hide()));
  connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(forceExit()));
  connect(ui->againstAndroid, SIGNAL(clicked()), SIGNAL(startAgainstAndroid()));
  connect(ui->againstAndroid, SIGNAL(clicked()), SLOT(hide()));
  connect(this, SIGNAL(startAgainstAndroid()), this, SLOT(againstAndroid()));
  connect(this, SIGNAL(startSimpleGame()), this, SLOT(singleGame()));
}

StartMenu::~StartMenu()
{
  delete game;
  delete ui;
}

void StartMenu::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/background.jpg").scaled(size()));
  QWidget::paintEvent(e);
}

void StartMenu::againstAndroid()
{
  game = new Scrabble(2, true);
  this->hide();
  connect(game, SIGNAL(endOfGame()), this, SLOT(endOfAndroidSessison()));
  game->show();
}

void StartMenu::singleGame()
{
  game = new Scrabble(2, false);
  this->hide();
  connect(game, SIGNAL(endOfGame()), this, SLOT(endOfSimpleSession()));
  game->show();
}

void StartMenu::endOfAndroidSessison()
{
  game->hide();
  delete game;
  game = nullptr;
  this->show();
}

void StartMenu::endOfSimpleSession()
{
  game->hide();
  delete game;
  game = nullptr;
  this->show();
}

void StartMenu::forceExit()
{
  delete game;
  delete ui;
  QApplication::exit();
}
