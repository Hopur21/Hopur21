#include "dbcon.h"

DbCon::DbCon()
{
    _hostname = "nocando.is";
    _databaseName = "harlausniris_computer_scientist";
    _username = "compTolva";
    _password = "HR.rjomi.2016";
    _connectionSuccess = makeConnection();

    //testFunction("Ada Lovelace");
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
//Other functions
void DbCon::setDataInPersonVector(vector<CSPerson>& computerScientists, const int id, const string name, const string gender, const int birthYear, const int passedAwayYear, const string comment, const bool isAlive)
{
    CSPerson scientist(id,name,gender,birthYear,passedAwayYear,comment, isAlive);
    computerScientists.push_back(scientist);
}
QString DbCon::getDateFormat(const string& year)
{
    return QString::fromStdString(year + "-00-00");
}

//Remove Querys
bool DbCon::removeComputerScientist(const int& scientistID)
{
    bool success = false;

    //if(!success){qDebug() << "removeComputerScientist error:  " << query.lastError();}
    return success;
}

//Insert Querys
bool DbCon::addComputerScientist(const string& name, const int& birthYear, const int& deathYear, const bool isAlive, const string& gender, const string& comment)
{
    //TODO - validate input.
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO computer_scientists(name, birth_year, death_year, is_alive, gender, comment) VALUES (:name, :birthYear, :deathYear, :isAlive, :gender, :comment)");
    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":birthYear", getDateFormat(to_string(birthYear)));
    query.bindValue(":deathYear", getDateFormat(to_string(deathYear)));
    query.bindValue(":isAlive", isAlive);
    query.bindValue(":gender", QString::fromStdString(gender));
    query.bindValue(":comment", QString::fromStdString(comment));
    success = query.exec();//Returns true/false if we made it
    if(!success){qDebug() << "addComputerScientist error:  " << query.lastError();}
    return success;
}
//Update Querys
bool DbCon::updateComputerScientist(const int& id, const string& name, const int& birthYear, const int& deathYear, const bool isAlive, const string& gender, const string& comment)
{
    //TODO: Validation
    bool success = false;
    QSqlQuery query;
    query.prepare("UPDATE computer_scientists SET name=(:name), birth_year=(:birthYear), death_year=(:deathYear), gender=(:gender), comment=(:comment), is_alive=(:isAlive) WHERE ID=(:id)");
    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":birthYear", getDateFormat(to_string(birthYear)));
    query.bindValue(":deathYear", getDateFormat(to_string(deathYear)));
    query.bindValue(":isAlive", isAlive);
    query.bindValue(":gender", QString::fromStdString(gender));
    query.bindValue(":comment", QString::fromStdString(comment));
    query.bindValue(":id", QString::fromStdString(to_string(id)));
    success = query.exec();
    if(!success){qDebug() << "updateComputerScientist error:  " << query.lastError();}
    return success;
}
//Select Querys
void DbCon::getComputerScientists(vector<CSPerson>& computerScientists)
{
    bool success = false;
    QSqlQuery query("SELECT ID, name, YEAR(birth_year) AS birth_year, YEAR(death_year) AS death_year, gender, comment, is_alive FROM computer_scientists ORDER BY name");
    //int idName = query.record().indexOf("name");
    while (query.next())
    {
        if(success == false)//If we made it here the query was a success, no need to set it to true for every single loop
        {
            success = true;
        }
        //Get the index of the column we are going to find and save our current data into the variable.
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
    if(!success){qDebug() << "addComputerScientist error:  " << query.lastError();}
}
bool DbCon::computerScientistExist(const int& id)
{
    bool foundValdo = false;
    QSqlQuery query;
    query.prepare("SELECT name FROM computer_scientists WHERE ID = (:id)");
    query.bindValue(":id", id);
    if (query.exec())
    {
       if (query.next())
       {
           qDebug() << "made it.";
           foundValdo = true;
       }
    }
    return foundValdo;
}
bool DbCon::testFunction(const QString& name)
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
