#include "maindatabase.h"

MainDataBase::MainDataBase()
{

}

User *MainDataBase::getUser(string name)
{
    QSqlQuery query;
    QString toQString ="";

    for (int i = 0; i < (int)name.size(); ++i)
        toQString += name[i];

    QString strQuery = QString("SELECT * FROM SrabbleDataBase WHERE name ='%1'").arg(toQString);
    bool result = query.exec(strQuery);
    QSqlRecord record = query.record();

    if (query.size() == 0)
    {
        addUser(toQString);
    }

    strQuery = QString("SELECT * FROM SrabbleDataBase WHERE name ='%1'").arg(toQString);
    result = query.exec(strQuery);
    record = query.record();

    assert(result);
    assert(query.size() != 0);

    while (query.next())
    {
        int loseCount = query.value(record.indexOf("loseCount")).toInt();
        int winCount = query.value(record.indexOf("winCount")).toInt();
        int usersCS = query.value(record.indexOf("usersCurrentScore")).toInt();
        int botsCS = query.value(record.indexOf("botsCurrentScore")).toInt();
        QString board = query.value(record.indexOf("currentBoard")).toString();
        string sBoard = "";
        for (int i = 0; i < (int)board.size(); ++i)
            sBoard += board[i].toLatin1();
        return new User(name, loseCount, winCount, sBoard, usersCS, botsCS);
    }
}

void MainDataBase::addUser(QString name)
{
    if (myDataBase.isOpen())
    {
        QSqlQuery query;
        bool result = query.exec(QString("INSERT INTO SrcabbleDataBase values(NULL,'%1', '%2', '%3', '%4', '%5', '%6')").arg(name, 0, 0, "", 0, 0));
        assert(result);
    }
}

void MainDataBase::openDataBase(QSqlDatabase &db)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("srabble.sqlite");
    if (!db.isOpen())
    {
        if (!db.open())
        {
            assert(false);
        }
    }

    if (!db.contains(QLatin1String("ScrabbleDataBase")))
    {
        QSqlQuery query;
        QString strQuery = "CREATE TABLE ScrabbleDataBase ("
                           "id integer PRIMARY KEY,"
                           "name VARCHAR(100),"
                           "loseCount integer,"
                           "winCount integer,"
                            "currentBoard VARCHAR(100),"
                            "usersCurrentScore integer,"
                            "botsCurrentScore integer);";
        bool result = query.exec(strQuery);
        assert(result);
    }
}
