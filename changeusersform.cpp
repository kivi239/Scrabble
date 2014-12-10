#include "changeusersform.h"
#include "ui_changeusersform.h"

ChangeUsersForm::ChangeUsersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeUsersForm)
{
    ui->setupUi(this);
    connect(ui->exitButton, SIGNAL(clicked()), this, SIGNAL(exitForm()));
    connect(ui->listWidget, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(pressedUser(QListWidgetItem*)));
}

ChangeUsersForm::~ChangeUsersForm()
{
    delete ui;
}

void ChangeUsersForm::addUsers(vector<QString> &users)
{
    for (int i = 0; i < (int)users.size(); ++i)
        if (myUsers.find(users[i]) == myUsers.end())
        {
            myUsers.insert(users[i]);
            ui->listWidget->addItem(users[i]);
        }
}

void ChangeUsersForm::pressedUser(QListWidgetItem *x)
{
    QString tmp = x->text();
    emit player(tmp);
}
