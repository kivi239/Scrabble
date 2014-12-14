#pragma once
#include "mainHeader.h"
#include <QWidget>
#include "QListWidget"
#include "createusers.h"

namespace Ui {
class ChangeUsersForm;
}

class ChangeUsersForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeUsersForm(QWidget *parent = 0);
    ~ChangeUsersForm();
    void paintEvent(QPaintEvent *);
    void addUsers(vector <QString> &users);

signals:
    void exitForm();
    void player(QString);

private slots:
    void pressedUser(QListWidgetItem* x);
    void createU();
    void addUser(QString);

private:
    Ui::ChangeUsersForm *ui;
    set<QString> myUsers;
    createUsers *cUsers;
};

