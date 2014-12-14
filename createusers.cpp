#include "createusers.h"
#include "ui_createusers.h"
#include <QPainter>

createUsers::createUsers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createUsers)
{
    ui->setupUi(this);
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(hide()));
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(sendUser()));
}

createUsers::~createUsers()
{
    delete ui;
}

void createUsers::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/peachColor.png").scaled(size()));

  QWidget::paintEvent(e);
}

void createUsers::sendUser()
{
    QString userName = ui->nameEdit->toPlainText();
    bool fl = false;
    for (int i = 0; i < userName.size(); ++i)
        if (userName[i].toLatin1() != ' ')
            fl = true;
    if (fl){
        ui->nameEdit->setText("");
        emit newUser(userName);
    }
}
