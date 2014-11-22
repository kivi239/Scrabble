#pragma once
#include <QObject>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "maindatabase.h"


class DtaBaseTest : public QObject
{
    Q_OBJECT
public:
    explicit DtaBaseTest(QObject *parent = 0);

private slots:

    void init()
    {
        db = new MainDataBase("TestTest.sqlite");
    }

    void addUser()
    {
        User user1 = db->getUser("Dnton");
        User user2 = db->getUser("AAA");
        User user3 = db->getUser("ccc");

    }

    void cleanup()
    {
        delete db;
    }

private:
    MainDataBase *db;
};

