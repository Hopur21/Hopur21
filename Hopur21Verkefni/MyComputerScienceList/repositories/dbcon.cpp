#include "dbcon.h"

DbCon::DbCon()
{
    _hostname = "nocando.is";
    _databaseName = "harlausniris_computer_scientist";
    _username = "compTolva";
    _password = "Eixc3~17";
    _connectionSuccess = makeConnection();
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
void DbCon::setDataInPersonVector(vector<CSPerson>& computerScientists, const int id, const string name, const string gender, const int birthYear, const int passedAwayYear, const string comment, const bool isAlive, const int imageID, const string imageName, const QByteArray imageByteArray)
{
    CSPerson scientist(id,name,gender,birthYear,passedAwayYear,comment, isAlive, imageID, imageByteArray, imageName);
    computerScientists.push_back(scientist);
}

void DbCon::setDataInComputerVector(vector<Computer>& computers, const int id, const string name, const int designYear, const int buildYear, const string type,const string typeID, const bool isCreated, const int imageID, const string imageName, const QByteArray imageByteArray)
{
    Computer computer(id, name, designYear, buildYear, type, typeID, isCreated, imageID, imageByteArray, imageName);
    computers.push_back(computer);
}

void DbCon::setDataInTypeVector(vector<ComputerType>& computerTypes,int id, string name)
{
    ComputerType myType;
    myType.setTypeValues(name,id);
    computerTypes.push_back(myType);
}

QString DbCon::getDateFormat(const string& year)
{
    return QString::fromStdString(year + "-00-00");
}

//Restore
bool DbCon::restoreComputerScientist(const int& scientistID)
{
    bool success = false;
    QSqlQuery query;
    try
    {
        query.prepare("UPDATE computer_scientists SET removed='0' WHERE ID=(:scientistID)");
        query.bindValue(":scientistID", scientistID);
        success = query.exec();
    }
    catch(int e)
    {
        //{qDebug() << "restoreComputerScientist error:  " << query.lastError();}
    }
    return success;
}

bool DbCon::restoreComputer(const int& computerID)
{
    bool success = false;
    QSqlQuery query;
    try
    {
        query.prepare("UPDATE computers SET removed ='0' WHERE ID =(:computerID)");
        query.bindValue(":computerID", computerID);
        success = query.exec();
    }
    catch(int e)
    {
        //{qDebug() << "restoreComputerScientist error:  " << query.lastError();}
    }
    return success;
}

//Remove Querys
bool DbCon::removeComputerScientist(const int& scientistID)
{
    bool success = false;
    QSqlQuery query;
    try
    {
        query.prepare("UPDATE computer_scientists SET removed='1' WHERE ID=(:scientistID)");
        query.bindValue(":scientistID", scientistID);
        success = query.exec();
    }
    catch(int e)
    {
        //{qDebug() << "removeComputerScientist error:  " << query.lastError();}
    }
    return success;
}

bool DbCon::removeComputer(const int& computerID)
{
    bool success = false;
    QSqlQuery query;
    try
    {
        query.prepare("UPDATE computers SET removed ='1' WHERE ID =(:computerID)");
        query.bindValue(":computerID", computerID);
        success = query.exec();
    }
    catch(int e)
    {
        //{qDebug() << "removeComputerScientist error:  " << query.lastError();}
    }
    return success;
}

//Insert Querys
bool DbCon::addComputerType(const string typeName)
{
    bool success = false;
    QSqlQuery query;
    try
    {
        query.prepare("INSERT INTO type(name) VALUES (:typeName)");
        query.bindValue(":typeName", QString::fromStdString(typeName));
        success = query.exec();
    }
    catch(int e)
    {
        //{qDebug() << "addCStoComputer error:  " << query.lastError();}
    }
    return success;
}

bool DbCon::addCStoComputer(const int cSID,const int compID)
{
    bool success = false;
    QSqlQuery query;
    try
    {
        query.prepare("INSERT INTO computer_scientists_computers(computer_scientist_ID,computer_ID) VALUES (:cSID, :compID)");
        query.bindValue(":cSID", cSID);
        query.bindValue(":compID", compID);
        success = query.exec();
    }
    catch(int e)
    {
        qDebug() << "addCStoComputer error:  " << query.lastError();
    }
    query.lastError();
    query.lastQuery();
    return success;
}

int DbCon::addPicture(const string imageName, const QByteArray image)
{
    QSqlQuery query;
    query.prepare("INSERT INTO img_table(file_name, img_data) VALUES (:file_name, :img_data)");
    query.bindValue(":file_name", QString::fromStdString(imageName));
    query.bindValue(":img_data",image);
    query.exec();
    QVariant returnID = query.lastInsertId();
    return returnID.toInt();
}

int DbCon::addComputerScientist(CSPerson value)
{
    bool success;
    QSqlQuery query;
    query.prepare("INSERT INTO computer_scientists(name, birth_year, death_year, is_alive, gender, comment, img_ID) VALUES (:name, :birthYear, :deathYear, :isAlive, :gender, :comment, :img_ID)");
    query.bindValue(":name", QString::fromStdString(value.getName()));
    query.bindValue(":birthYear", getDateFormat(to_string(value.getBirthYear())));
    query.bindValue(":deathYear", getDateFormat(to_string(value.getPassedAwayYear())));
    query.bindValue(":isAlive", value.getIsAlive());
    query.bindValue(":gender", QString::fromStdString(value.getGender()));
    query.bindValue(":comment", QString::fromStdString(value.getComments()));
    query.bindValue(":img_ID", value.getImageID());
    success = query.exec();
    if(!success){qDebug() << "addComputerScientist error:  " << query.lastError();}
    QVariant returnID = query.lastInsertId();
    //qDebug() << query.lastQuery();
    return returnID.toInt();
}

int DbCon::addComputer(Computer value)
{
    QSqlQuery query;
    query.prepare("INSERT INTO computers(name, design_year, build_year, is_created, type_ID, img_ID) VALUES (:name, :designYear, :buildYear, :isCreated, :type, :img_ID)");
    query.bindValue(":name", QString::fromStdString(value.getName()));
    query.bindValue(":designYear", getDateFormat(to_string(value.getDesignYear())));
    query.bindValue(":buildYear", getDateFormat(to_string(value.getBuildYear())));
    query.bindValue(":isCreated", value.getIsCreated());
    query.bindValue(":img_ID", value.getImageID());
    query.bindValue(":type", QString::fromStdString(value.getTypeID()));
    query.exec();
    //if(!success){qDebug() << "addComputer error:  " << query.lastError();}
    QVariant returnID = query.lastInsertId();
    return returnID.toInt();
}

//Update Querys
bool DbCon::updateComputerScientist(CSPerson& computerScientist)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("UPDATE computer_scientists SET name=(:name), birth_year=(:birthYear), death_year=(:deathYear), gender=(:gender), comment=(:comment), is_alive=(:isAlive) WHERE ID=(:id)");
    query.bindValue(":name", QString::fromStdString(computerScientist.getName()));
    query.bindValue(":birthYear", getDateFormat(to_string(computerScientist.getBirthYear())));
    query.bindValue(":deathYear", getDateFormat(to_string(computerScientist.getPassedAwayYear())));
    query.bindValue(":isAlive", computerScientist.getIsAlive());
    query.bindValue(":gender", QString::fromStdString(computerScientist.getGender()));
    query.bindValue(":comment", QString::fromStdString(computerScientist.getComments()));
    query.bindValue(":id", QString::fromStdString(to_string(computerScientist.getID())));
    success = query.exec();
    //if(!success){qDebug() << "updateComputerScientist error:  " << query.lastError();}
    return success;
}

bool DbCon::updateComputer(Computer& computer)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("UPDATE computer_scientists SET name=(:name), design_year=(:designYear), build_year=(:buildYear), type_ID=(:type), is_created=(:isCreated) WHERE ID=(:id)");
    query.bindValue(":name", QString::fromStdString(computer.getName()));
    query.bindValue(":designYear", getDateFormat(to_string(computer.getDesignYear())));
    query.bindValue(":buildYear", getDateFormat(to_string(computer.getBuildYear())));
    query.bindValue(":isCreated", computer.getIsCreated());
    query.bindValue(":type", QString::fromStdString(computer.getType()));
    query.bindValue(":id", QString::fromStdString(to_string(computer.getID())));
    success = query.exec();
    //if(!success){qDebug() << "updateComputer error:  " << query.lastError();}
    return success;
}

//Select Querys
vector<ComputerScientistToComputer> DbCon::getCscientistToComps()
{
    vector<ComputerScientistToComputer> ourData;
    bool success = false;
    QSqlQuery query("select computer_scientist_ID, computer_ID from computer_scientists_computers;");
    while (query.next())
    {
        // If we made it here the query was a success
        // no need to set it to true for every single loop
        if(success == false)
        {
            success = true;
        }
        ComputerScientistToComputer temp;
        QString csID = query.value(query.record().indexOf("computer_scientist_ID")).toString();
        QString compID = query.value(query.record().indexOf("computer_ID")).toString();
        temp.setCompID(compID.toInt());
        temp.setCSID(csID.toInt());
        ourData.push_back(temp);
    }
    return ourData;
}

vector<Computer> DbCon::getComputersConnectedToCS(const int scientistID)
{
    vector<Computer> compuerList;
    bool success = false;
    compuerList.clear();
    QSqlQuery query;
    query.prepare("SELECT c.ID, c.name, YEAR(c.design_year) AS design_year, YEAR(c.build_year) AS build_year, c.type_ID,(SELECT name FROM type WHERE ID = type_ID) AS type, c.is_created, c.img_ID, im.file_name AS image_name, im.img_data FROM computer_scientists_computers csc JOIN computers c ON (csc.computer_ID=c.ID) LEFT JOIN img_table im ON(c.img_ID=im.ID) WHERE csc.computer_scientist_ID =(:scientistID);");
    query.bindValue(":scientistID", scientistID);
    query.exec();
    while (query.next())
    {
        // If we made it here the query was a success
        // no need to set it to true for every single loop
        if(success == false)
        {
            success = true;
        }
        runSelectForComputers(query,compuerList);
    }
    return compuerList;
}

vector<CSPerson> DbCon::getCSConntedToComputer(const int computerID)
{
    vector<CSPerson> CSList;
    bool success = false;
    CSList.clear();
    QSqlQuery query;
    query.prepare("SELECT cs.ID, cs.name,YEAR(cs.birth_year) AS birth_year, YEAR(cs.death_year) AS death_year, cs.gender, cs.comment, cs.is_alive, cs.img_ID,im.file_name AS image_name, im.img_data FROM computer_scientists cs JOIN computer_scientists_computers csc ON (csc.computer_scientist_ID=cs.ID) LEFT JOIN img_table im ON(cs.img_ID=im.ID)WHERE csc.computer_ID = :computerID");
    query.bindValue(":computerID", computerID);
    query.exec();
    while (query.next())
    {
        if(success == false)
        {
            success = true;
        }
        runSelectForScientist(query, CSList);
    }
    return CSList;
}

void DbCon::getComputerScientists(vector<CSPerson>& computerScientists)
{
    bool success = false;
    computerScientists.clear();//Clear the vector
    QSqlQuery query("SELECT cs.ID, cs.name, YEAR(cs.birth_year) AS birth_year, YEAR(cs.death_year) AS death_year, cs.gender, cs.comment,cs.is_alive , cs.img_ID, im.file_name AS image_name, im.img_data FROM computer_scientists cs LEFT JOIN img_table im ON(cs.img_ID=im.ID) WHERE cs.removed = 0 ORDER BY name");
    //int idName = query.record().indexOf("name");
    while (query.next())
    {
        if(success == false)//If we made it here the query was a success, no need to set it to true for every single loop
        {
            success = true;
        }
        runSelectForScientist(query, computerScientists);
    }
    //if(!success){qDebug() << "getComputerScientists error:  " << query.lastError();}
}
void DbCon::getComputers(vector<Computer>& computers)
{
    computers.clear();
    bool success = false;
       QSqlQuery query("SELECT c.ID, c.name, YEAR(c.design_year) AS design_year, YEAR(c.build_year) AS build_year, c.is_created, (SELECT name FROM type WHERE ID = c.type_ID) AS type, c.type_ID , c.img_ID, im.file_name AS image_name, im.img_data  FROM computers c LEFT JOIN img_table im ON(c.img_ID=im.ID) WHERE removed = 0 ORDER BY name;");
       //int idName = query.record().indexOf("name");
       while (query.next())
       {
           if(success == false)//If we made it here the query was a success, no need to set it to true for every single loop
           {
               success = true;
           }
           runSelectForComputers(query,computers);
       }
       //if(!success){qDebug() << "getComputers error:  " << query.lastError();}
}
void DbCon::getComputerTypes(vector<ComputerType>& computerTypes)
{
    computerTypes.clear();
    bool success = false;
    QSqlQuery query("SELECT ID,name FROM type ORDER BY name");
    while (query.next())
    {
       if(success == false)
       {
           success = true;
       }
       QString name = query.value(query.record().indexOf("name")).toString();
       QString id = query.value(query.record().indexOf("id")).toString();
       setDataInTypeVector(computerTypes,id.toInt(), name.toStdString());
    }
    //if(!success){qDebug() << "getComputerTypes error:  " << query.lastError();}
}
vector<CSPerson> DbCon::getComputerScientistsTrashCan()
{
    vector<CSPerson> computerScientistTrashCan;
    bool success = false;
    QSqlQuery query("SELECT cs.ID, cs.name, YEAR(cs.birth_year) AS birth_year, YEAR(cs.death_year) AS death_year, cs.gender, cs.comment,cs.is_alive , cs.img_ID, im.file_name AS image_name, im.img_data FROM computer_scientists cs LEFT JOIN img_table im ON(cs.img_ID=im.ID) WHERE cs.removed = 1 ORDER BY name;");
    while (query.next())
    {
        if(success == false)
        {
            success = true;
        }
        runSelectForScientist(query, computerScientistTrashCan);
    }
    //if(!success){qDebug() << "getTrashCan error:  " << query.lastError();}
    return computerScientistTrashCan;
}
vector<Computer> DbCon::getComputerTrashCan()
{
    vector<Computer> computerTrashCan;
    bool success = false;
    QSqlQuery query("SELECT c.ID, c.name, YEAR(c.design_year) AS design_year, YEAR(c.build_year) AS build_year, c.is_created, (SELECT name FROM type WHERE ID = c.type_ID) AS type, c.type_ID , c.img_ID, im.file_name AS image_name, im.img_data  FROM computers c LEFT JOIN img_table im ON(c.img_ID=im.ID) WHERE removed = 1 ORDER BY name;");
    while (query.next())
    {
        if(success == false)
        {
            success = true;
        }
        runSelectForComputers(query, computerTrashCan);
    }
    //if(!success){qDebug() << "getTrashCan error:  " << query.lastError();}
    return computerTrashCan;
}

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
//Search
void DbCon::searchScientist(vector<CSPerson>& scientist, const string searchFor, const bool removed)
{
    scientist.clear();
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT cs.ID, cs.name, YEAR(cs.birth_year) AS birth_year, YEAR(cs.death_year) AS death_year, cs.gender, cs.comment,cs.is_alive , cs.img_ID, im.file_name AS image_name, im.img_data FROM computer_scientists cs LEFT JOIN img_table im ON(cs.img_ID=im.ID) WHERE (cs.name LIKE '%' :searchFor '%' OR cs.death_year LIKE '%' :searchFor '%' OR cs.birth_year LIKE '%' :searchFor '%' OR cs.gender LIKE '%' :searchFor '%') AND cs.removed = (:removed) ORDER BY name");
    query.bindValue(":searchFor", QString::fromStdString(searchFor));
    query.bindValue(":removed", removed);
    query.exec();
    while (query.next())
    {
        if(success == false)//If we made it here the query was a success, no need to set it to true for every single loop
        {
            success = true;
        }
        runSelectForScientist(query, scientist);
    }
    //if(!success){qDebug() << "getComputerScientists error:  " << query.lastError();}
}
void DbCon::searchComputer(vector<Computer>& computer, const string searchFor, const bool removed)
{
    computer.clear();
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT c.ID, c.name, YEAR(c.design_year) AS design_year, YEAR(c.build_year) AS build_year, c.is_created, t.name AS type, c.type_ID , c.img_ID, im.file_name AS image_name, im.img_data FROM computers c JOIN type t ON(t.ID=c.type_ID) LEFT JOIN img_table im ON(c.img_ID=im.ID)WHERE (c.name LIKE '%' :searchFor '%' OR c.design_year LIKE '%' :searchFor '%' OR c.build_year LIKE '%' :searchFor '%' OR t.name LIKE '%' :searchFor '%') AND c.removed = (:removed) ORDER BY name");
    query.bindValue(":searchFor", QString::fromStdString(searchFor));
    query.bindValue(":removed", removed);
    query.exec();
    while (query.next())
    {
        if(success == false)
        {
            success = true;
        }

        runSelectForComputers(query,computer);
    }
    //if(!success){qDebug() << "getComputers error:  " << query.lastError();}
}
void DbCon::runSelectForScientist(QSqlQuery& query, vector<CSPerson>& scientist)
{
   //Get the index of the column we are going to find and save our current data into the variable.
   QString id = query.value(query.record().indexOf("ID")).toString();
   QString name = query.value(query.record().indexOf("name")).toString();
   QString birthYear = query.value(query.record().indexOf("birth_year")).toString();
   QString deathYear = query.value(query.record().indexOf("death_year")).toString();
   QString gender = query.value(query.record().indexOf("gender")).toString();
   QString comment = query.value(query.record().indexOf("comment")).toString();
   QString isAlive = query.value(query.record().indexOf("is_alive")).toString();
   QString imageID = query.value(query.record().indexOf("img_ID")).toString();
   QString imageName = query.value(query.record().indexOf("image_name")).toString();
   QByteArray  imageData = query.value(query.record().indexOf("img_data")).toByteArray();
   setDataInPersonVector(scientist, id.toInt(), name.toStdString(), gender.toStdString(), birthYear.toInt(), deathYear.toInt(), comment.toStdString(), isAlive.toInt(), imageID.toInt(), imageName.toStdString(),imageData);
}
void DbCon::runSelectForComputers(QSqlQuery& query, vector<Computer>& computers)
{
   //Get the index of the column we are going to find and save our current data into the variable.
   QString id = query.value(query.record().indexOf("ID")).toString();
   QString name = query.value(query.record().indexOf("name")).toString();
   QString designYear = query.value(query.record().indexOf("design_year")).toString();
   QString buildYear = query.value(query.record().indexOf("build_year")).toString();
   QString type = query.value(query.record().indexOf("type")).toString();
   QString typeID = query.value(query.record().indexOf("type_ID")).toString();
   QString isCreated = query.value(query.record().indexOf("is_created")).toString();
   QString imageID = query.value(query.record().indexOf("img_ID")).toString();
   QString imageName = query.value(query.record().indexOf("image_name")).toString();
   QByteArray  imageData = query.value(query.record().indexOf("img_data")).toByteArray();
   setDataInComputerVector(computers, id.toInt(), name.toStdString(), designYear.toInt(), buildYear.toInt(), type.toStdString(),typeID.toStdString(), isCreated.toInt(), imageID.toInt(), imageName.toStdString(),imageData);
}
