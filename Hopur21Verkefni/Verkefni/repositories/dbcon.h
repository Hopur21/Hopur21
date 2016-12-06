#ifndef DBCON_H
#define DBCON_H
#include <QSqlDatabase>
#include<QtSql>
#include"models/csperson.h"
#include"models/computer.h"

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

    //Sets
    void setDataInPersonVector(vector<CSPerson>& computerScientists, const int id, const string name, const string gender, const int birthYear, const int passedAwayYear, const string comment, const bool isAlive);
    //Gets

public:
    DbCon();//Constructors to set our own hostname and such.
    DbCon(const QString& hostname, const QString& database, const QString& username, const QString& password);
    ~DbCon();  //Destructor

    //Gets
    bool connectionSuccessful(){return _connectionSuccess;}
    bool addPerson(const QString& name); //Test

    void getComputerScientists(vector<CSPerson>& computerScientists);
};


#endif // DBCON_H
