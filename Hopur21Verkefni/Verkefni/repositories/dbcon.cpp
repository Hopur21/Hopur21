#include "dbcon.h"

#include <iostream> //henda
#include<string> //henda

using namespace std;
DbCon::DbCon()
{
    _hostname = "nocando.is";
    _databaseName = "harlausniris_computer_scientist";
    _username = "compTolva";
    _password = "HR.rjomi.2016";
    _connectionSuccess = makeConnection();

    if(!_connectionSuccess)
        cout << "Connection tókst EKKI" << endl;
    addPerson("Ada Lovelace");
}
DbCon::DbCon(const QString& hostname, const QString& database, const QString& username, const QString& password)
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
void DbCon::setDataInPersonVector(vector<CSPerson>& computerScientists, const int id, const string name, const string gender, const int birthYear, const int passedAwayYear, const string comment, const bool isAlive)
{
    CSPerson scientist(id,name,gender,birthYear,passedAwayYear,comment, isAlive);
    computerScientists.push_back(scientist);
}


//Querys
void DbCon::getComputerScientists(vector<CSPerson>& computerScientists)
{
    QSqlQuery query("SELECT ID, name, YEAR(birth_year) AS birth_year, YEAR(death_year) AS death_year, gender, comment, is_alive FROM computer_scientists ORDER BY name");
    //int idName = query.record().indexOf("name");
    while (query.next())
    {   //Get the index of the column we are going to find and save our current data into the variable.
       QString id = query.value(query.record().indexOf("ID")).toString();
       QString name = query.value(query.record().indexOf("name")).toString();
       QString birthYear = query.value(query.record().indexOf("birth_year")).toString();
       QString deathYear = query.value(query.record().indexOf("death_year")).toString();
       QString gender = query.value(query.record().indexOf("gender")).toString();
       QString comment = query.value(query.record().indexOf("comment")).toString();
       QString isAlive = query.value(query.record().indexOf("is_alive")).toString();
       //cout << name.toStdString() << endl;
       //cout << idName << endl;
       //qDebug() << name;
       setDataInPersonVector(computerScientists, id.toInt(), name.toStdString(), gender.toStdString(), birthYear.toInt(), deathYear.toInt(), comment.toStdString(), isAlive.toInt());
    }
}
bool DbCon::addPerson(const QString& name)
{
   // you should check if args are ok first...
    QSqlQuery query("SELECT * FROM computer_scientists");
    int idName = query.record().indexOf("birth_year");
    //query.record();
    //query.exec();
    while (query.next())
    {
       QString name = query.value(1).toString();
       //cout << name.toStdString() << endl;
       //cout << idName << endl;
       //qDebug() << name;
    }

   return query.exec();//Returns bool if we were successful.
}
