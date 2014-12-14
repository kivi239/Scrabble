#include "changeusersform.h"
#include "ui_changeusersform.h"
#include <QPainter>

ChangeUsersForm::ChangeUsersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeUsersForm),
    cUsers(nullptr)
{
    ui->setupUi(this);
    connect(ui->exitButton, SIGNAL(clicked()), this, SIGNAL(exitForm()));
    connect(ui->listWidget, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(pressedUser(QListWidgetItem*)));
    connect(ui->createButton, SIGNAL(clicked()), this, SLOT(createU()));
}

ChangeUsersForm::~ChangeUsersForm()
{
    delete ui;
}

void ChangeUsersForm::paintEvent(QPaintEvent *e)
{
  QPainter painter(this);
  painter.drawPixmap(0, 0, QPixmap(":/new/prefix1/peachColor.png").scaled(size()));

  QWidget::paintEvent(e);
}

void ChangeUsersForm::addUsers(vector<QString> &users)
{
    for (int i = 0; i < (int)users.size(); ++i)
        if (myUsers.find(users[i]) == myUsers.end())
        {
            myUsers.insert(users[i]);
            int row = myUsers.size();
            ui->listWidget->insertItem(row, users[i]);
        }
}

void ChangeUsersForm::pressedUser(QListWidgetItem *x)
{
    QString tmp = x->text();
    emit player(tmp);
}

void ChangeUsersForm::createU()
{
    if (!cUsers)
        cUsers = new createUsers();
    connect(cUsers, SIGNAL(newUser(QString)), this, SLOT(addUser(QString)));
    cUsers->show();
}

void ChangeUsersForm::addUser(QString newU)
{
    cUsers->hide();
    this->show();
    if (myUsers.find(newU) == myUsers.end())
    {
            myUsers.insert(newU);
            int row = myUsers.size();
            ui->listWidget->insertItem(row, newU);
    }
}
