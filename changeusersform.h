#pragma once
#include "mainHeader.h"
#include <QWidget>

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

private:
    Ui::ChangeUsersForm *ui;
};

