#include "mainHeader.h"
#include <QtSql>
#include "user.h"

class MainDataBase
{
public:
    MainDataBase();
    User *getUser(string name);
    void addUser(QString name);

private:
    void openDataBase(QSqlDatabase &db);
    QSqlDatabase myDataBase;
};

