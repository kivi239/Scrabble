#include "mainHeader.h"
#include <QtSql>
#include "user.h"

class MainDataBase
{
public:
    MainDataBase(QString name);
    User getUser(string name);
    ~MainDataBase();

private:
    void addUser(QString name);
    void openDataBase(QString name);
    QSqlDatabase db;
};

