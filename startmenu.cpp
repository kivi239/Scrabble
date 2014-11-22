#include "startmenu.h"
#include "ui_startmenu.h"
#include <QPainter>

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

void StartMenu::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/background.jpg").scaled(size()));
    QWidget::paintEvent(e);
}
