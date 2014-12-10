#pragma once
#include "mainHeader.h"
#include <QWidget>
#include "QListWidget"

namespace Ui {
class ChangeUsersForm;
}

class ChangeUsersForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeUsersForm(vector <QString> &users, QWidget *parent = 0);
    ~ChangeUsersForm();

signals:
    void exitForm();
    void player(QString);

private slots:
    void pressedUser(QListWidgetItem* x);

private:
    Ui::ChangeUsersForm *ui;
};

