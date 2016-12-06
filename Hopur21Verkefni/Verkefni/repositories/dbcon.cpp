#include "dbcon.h"

#include <iostream>
#include<string>

using namespace std;
DbCon::DbCon()
{
    _hostname = "nocando.is";
    _databaseName = "harlausniris_computer_scientist";
    _username = "compTolva";
    _password = "HR.rjomi.2016";
    _connectionSuccess = makeConnection();
}
DbCon::DbCon(const QString hostname, const QString database, const QString username, const QString password)
{
    _hostname = hostname;
    _databaseName = database;
    _username = username;
    _password = password;
    _connectionSuccess = makeConnection();
}
DbCon::~DbCon()
{
    _db.close();
}

bool DbCon::makeConnection()
{
    _db = QSqlDatabase::addDatabase("QMYSQL");
    _db.setHostName(_hostname);
    _db.setDatabaseName(_databaseName);
    _db.setUserName(_username);
    _db.setPassword(_password);

    //Return true if we made the connection, else false.
    return _db.open();
}
