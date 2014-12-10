#include "maindatabase.h"

MainDataBase::MainDataBase(QString name)
{
    openDataBase(name);
}

User MainDataBase::getUser(QString name)
{
    if (db.isOpen())
    {
        QSqlQuery query;


        QString strQuery = QString("SELECT * FROM ScrabbleDataBase WHERE name ='%1'").arg(name);
        bool result = query.exec(strQuery);
        QSqlRecord record = query.record();

        qDebug() << "getUser " << result;
        assert(result);

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
            return User(name, loseCount, winCount, sBoard, usersCS, botsCS);
        }
        addUser(name);
        return getUser(name);
    }
}

vector<QString> MainDataBase::getAllUsers()
{
    vector <QString> results;
    results.clear();
    if (db.isOpen())
    {
        QSqlQuery query;
        QString strQuery = QString("SELECT * FROM ScrabbleDataBase");
        bool result = query.exec(strQuery);
        QSqlRecord record = query.record();

        qDebug() << result;
        assert(result);

        while (query.next())
        {
            QString name = query.value(record.indexOf("name")).toString();
            results.push_back(name);
        }
    }
    return results;
}

MainDataBase::~MainDataBase()
{
    db.close();
}

void MainDataBase::addUser(QString name)
{
    if (db.isOpen())
    {
        QSqlQuery query;     
        bool result = query.exec(QString("INSERT INTO ScrabbleDataBase(name, loseCount, winCount, currentBoard"
                                         ", usersCurrentScore, botsCurrentScore)"
                                         "values('%1', '%2', '%3', '%4', '%5', '%6')").arg(name, 0, 0, "", 0, 0));
        assert(result);
    }
}

void MainDataBase::openDataBase(QString name)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(name);
    if (!db.isOpen())
    {        
        if (!db.open())
        {
            assert(false);
        }
    }

    if (!db.tables().contains("ScrabbleDataBase"))
    {        
        QSqlQuery query;
        QString strQuery = "CREATE table ScrabbleDataBase ("
                           "name VARCHAR(100) PRIMARY KEY,"
                           "loseCount integer,"
                           "winCount integer,"
                            "currentBoard VARCHAR(100),"
                            "usersCurrentScore integer,"
                            "botsCurrentScore integer);";
        bool result = query.exec(strQuery);
        assert(result);     
    }
}
