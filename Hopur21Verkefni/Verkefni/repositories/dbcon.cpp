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
    QString connection;
    connection = _db.connectionName();
    _db.close();
    _db = QSqlDatabase();
    _db.removeDatabase(connection);
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
void DbCon::setDataInComputerVector(vector<Computer>& computers, const int id, const string name, const int designYear, const int buildYear, const string type,const string typeID, const bool isCreated)
{
    Computer computer(id, name, designYear, buildYear, type, typeID, isCreated);
    computers.push_back(computer);
}
/*void DbCon::setDataInTypeVector(vector<Computer>& computers, const string name)
{
    Computer computer(name);
    computers.push_back(computer);
}*/
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
bool DbCon::removeComputer(const int& computerID)
{
    bool success = false;

    //if(!success){qDebug() << "removeComputerScientist error:  " << query.lastError();}
    return success;
}
//Insert Querys
int DbCon::addComputerScientist(const CSPerson value)
{
    //TODO - validate input.
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO computer_scientists(name, birth_year, death_year, is_alive, gender, comment) VALUES (:name, :birthYear, :deathYear, :isAlive, :gender, :comment)");
    query.bindValue(":name", QString::fromStdString(value.getName()));
    query.bindValue(":birthYear", getDateFormat(to_string(value.getBirthYear())));
    query.bindValue(":deathYear", getDateFormat(to_string(value.getPassedAwayYear())));
    query.bindValue(":isAlive", value.getIsAlive());
    query.bindValue(":gender", QString::fromStdString(value.getGender()));
    query.bindValue(":comment", QString::fromStdString(value.getComments()));
    success = query.exec();//Returns true/false if we made it
    if(!success){qDebug() << "addComputerScientist error:  " << query.lastError();}
    QVariant returnID = query.lastInsertId();
    return returnID.toInt();
}
int DbCon::addComputer(const Computer value)
{
    //TODO - validate input.
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO computers(name, design_year, build_year, is_created, type_ID) VALUES (:name, :designYear, :buildYear, :isCreated, :type)");
    query.bindValue(":name", QString::fromStdString(value.getName()));
    query.bindValue(":designYear", getDateFormat(to_string(value.getDesignYear())));
    query.bindValue(":buildYear", getDateFormat(to_string(value.getBuildYear())));
    query.bindValue(":isCreated", value.getIsCreated());
    query.bindValue(":type", QString::fromStdString(value.getTypeID()));
    success = query.exec();//Returns true/false if we made it
    if(!success){qDebug() << "addComputerScientist error:  " << query.lastError();}
    QVariant returnID = query.lastInsertId();
    return returnID.toInt();
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
bool DbCon::updateComputer(const int& id, const string& name, const int& designYear, const int& buildYear, const string& type, const bool isCreated)
{
    //TODO: Validation
    bool success = false;
    QSqlQuery query;
    query.prepare("UPDATE computer_scientists SET name=(:name), design_year=(:designYear), build_year=(:buildYear), type_ID=(:type), is_created=(:isCreated) WHERE ID=(:id)");
    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":designYear", getDateFormat(to_string(designYear)));
    query.bindValue(":buildYear", getDateFormat(to_string(buildYear)));
    query.bindValue(":isCreated", isCreated);
    query.bindValue(":type", QString::fromStdString(type));
    query.bindValue(":id", QString::fromStdString(to_string(id)));
    success = query.exec();
    if(!success){qDebug() << "updateComputerScientist error:  " << query.lastError();}
    return success;
}
//Select Querys
void DbCon::getComputersConnectedToCS(vector<Computer>& compuerList,const int scientistID)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT c.ID, c.name, YEAR(c.design_year) AS design_year, YEAR(c.build_year) AS build_year, c.type_ID,(SELECT name FROM type WHERE ID = type_ID) AS type, c.is_created FROM computer_scientists_computers csc JOIN computers c ON (csc.computer_ID=c.ID) WHERE csc.computer_scientist_ID = (:scientistID);");
    query.bindValue(":scientistID", scientistID);
    while (query.next())
    {
        if(success == false)//If we made it here the query was a success, no need to set it to true for every single loop
        {
            success = true;
        }
        //Get the index of the column we are going to find and save our current data into the variable.
       QString id = query.value(query.record().indexOf("ID")).toString();
       QString name = query.value(query.record().indexOf("name")).toString();
       QString designYear = query.value(query.record().indexOf("design_year")).toString();
       QString buildYear = query.value(query.record().indexOf("build_year")).toString();
       QString type = query.value(query.record().indexOf("type")).toString();
       QString typeID = query.value(query.record().indexOf("type_ID")).toString();
       QString isCreated = query.value(query.record().indexOf("is_created")).toString();
       compuerList.clear();
       setDataInComputerVector(compuerList, id.toInt(), name.toStdString(), designYear.toInt(), buildYear.toInt(), type.toStdString(),typeID.toStdString(), isCreated.toInt());
    }
    if(!success){qDebug() << "getComputersConnectedToSC error:  " << query.lastError();}
}
void DbCon::getCSConntedToComputer(vector<CSPerson>& CSList,const int computerID)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT cs.ID, cs.name, YEAR(cs.birth_year) AS birth_year, YEAR(cs.death_year) AS death_year, cs.gender, cs.comment, cs.is_alive FROM computer_scientists_computers csc JOIN computer_scientists cs ON (csc.computer_scientist_ID=cs.ID) WHERE csc.computer_ID = (:computerID);");
    query.bindValue(":scientistID", computerID);
    while (query.next())
    {
        if(success == false)
        {
            success = true;
        }
       QString id = query.value(query.record().indexOf("ID")).toString();
       QString name = query.value(query.record().indexOf("name")).toString();
       QString birthYear = query.value(query.record().indexOf("birth_year")).toString();
       QString deathYear = query.value(query.record().indexOf("death_year")).toString();
       QString gender = query.value(query.record().indexOf("gender")).toString();
       QString comment = query.value(query.record().indexOf("comment")).toString();
       QString isAlive = query.value(query.record().indexOf("is_alive")).toString();
       setDataInPersonVector(CSList, id.toInt(), name.toStdString(), gender.toStdString(), birthYear.toInt(), deathYear.toInt(), comment.toStdString(), isAlive.toInt());
    }
    if(!success){qDebug() << "addComputerScientist error:  " << query.lastError();}
}

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
void DbCon::getComputers(vector<Computer>& computers)
{
    bool success = false;
       QSqlQuery query("SELECT ID, name, YEAR(design_year) AS design_year, YEAR(build_year) AS build_year, is_created, (SELECT name FROM type WHERE ID = type_ID) AS type, type_ID FROM computers ORDER BY name;");
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
          QString designYear = query.value(query.record().indexOf("design_year")).toString();
          QString buildYear = query.value(query.record().indexOf("build_year")).toString();
          QString type = query.value(query.record().indexOf("type")).toString();
          QString typeID = query.value(query.record().indexOf("type_ID")).toString();
          QString isCreated = query.value(query.record().indexOf("is_created")).toString();
          //cout << name.toStdString() << endl;
          //cout << idName << endl;
          //qDebug() << name;
          setDataInComputerVector(computers, id.toInt(), name.toStdString(), designYear.toInt(), buildYear.toInt(), type.toStdString(),typeID.toStdString(), isCreated.toInt());
       }
       if(!success){qDebug() << "addComputer error:  " << query.lastError();}
}
/*void DbCon::getType(vector<Computer>& computers)
{
    bool success = false;
    QSqlQuery query("SELECT name FROM computers ORDER BY name");
        if(success == false)
        {
            success = true;
        }
        QString name = query.value(query.record().indexOf("name")).toString();
        setDataInTypeVector(computers, name.toStdString());
}*/
bool DbCon::computerScientistExist(const string& name)
{
    bool foundValdo = false;
    QSqlQuery query;
    query.prepare("SELECT name FROM computer_scientists WHERE name = (:name)");
    query.bindValue(":name", QString::fromStdString(name));
    if (query.exec())
    {
       if (query.next())
       {
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
