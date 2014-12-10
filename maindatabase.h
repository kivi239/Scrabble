#pragma once
#include "mainHeader.h"
#include <QtSql>
#include "user.h"

class MainDataBase
{
public:
    MainDataBase(QString name);
    User getUser(QString name);
    vector<QString> getAllUsers();
    ~MainDataBase();

private:
    void addUser(QString name);
    void openDataBase(QString name);
    QSqlDatabase db;
};

