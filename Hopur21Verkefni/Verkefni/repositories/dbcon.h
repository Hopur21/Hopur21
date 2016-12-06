#ifndef DBCON_H
#define DBCON_H
#include <QSqlDatabase>
#include<QtSql>
using namespace std;
class DbCon
{
private:
    bool _connectionSuccess;
    QSqlDatabase _db;
    QString _hostname;
    QString _databaseName;
    QString _username;
    QString _password;

    bool makeConnection();

public:
    DbCon();//Constructors to set our own hostname and such.
    DbCon(const QString hostname, const QString database, const QString username, const QString password);
    ~DbCon();  //Destructor
};


#endif // DBCON_H
