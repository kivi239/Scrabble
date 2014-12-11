#pragma once
#include <QWidget>
#include "mainHeader.h"

namespace Ui {
class createUsers;
}

class createUsers : public QWidget
{
    Q_OBJECT

public:
    explicit createUsers(QWidget *parent = 0);
    ~createUsers();

signals:
    void newUser(QString);

private slots:
    void sendUser();

private:
    Ui::createUsers *ui;
};


