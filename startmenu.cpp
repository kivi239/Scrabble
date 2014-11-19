#include "startmenu.h"
#include "ui_startmenu.h"

StartMenu::StartMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartMenu)
{
    ui->setupUi(this);
    connect(ui->startGameButton, SIGNAL(clicked()), SIGNAL(startGame()));
    connect(ui->startGameButton, SIGNAL(clicked()), SLOT(hide()));
    connect(ui->exitButton, SIGNAL(clicked()), SLOT(close()));
}

StartMenu::~StartMenu()
{
    delete ui;
}
