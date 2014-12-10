#include "changeusersform.h"
#include "ui_changeusersform.h"

ChangeUsersForm::ChangeUsersForm(vector <QString> &users, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeUsersForm)
{
    ui->setupUi(this);
    for (int i = 0; i < (int)users.size(); ++i)
    {
        ui->listWidget->addItem(users[i]);
    }
    connect(ui->exitButton, SIGNAL(clicked()), this, SIGNAL(exitForm()));
    connect(ui->listWidget, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(pressedUser(QListWidgetItem*)));
    qDebug() << "in";
}

ChangeUsersForm::~ChangeUsersForm()
{
    delete ui;
    qDebug() << "out";
}

void ChangeUsersForm::pressedUser(QListWidgetItem *x)
{
    //emit player(x->text());
}
