#ifndef DBCON_H
#define DBCON_H
#include <QSqlDatabase>
#include <QtSql>
#include "models/csperson.h"
#include "models/computer.h"

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
    void runSelectForScientist(QSqlQuery& query, vector<CSPerson>& scientist);
    void runSelectForComputers(QSqlQuery& query, vector<Computer>& computers);
    void setDataInPersonVector(vector<CSPerson>& computerScientists, const int id, const string name, const string gender, const int birthYear, const int passedAwayYear, const string comment, const bool isAlive);
    void setDataInComputerVector(vector<Computer>& computers, const int id, const string name, const int designYear, const int buildYear, const string type,const string typeID, const bool isCreated);
    void setDataInTypeVector(vector<string>& computerTypes, const string name);
    //Gets
    QString getDateFormat(const string& year);

public:
    DbCon();//Constructors to set our own hostname and such.
    DbCon(const QString& hostname, const QString& database, const QString& username, const QString& password);
    ~DbCon();  //Destructor

    //Gets
    bool connectionSuccessful(){return _connectionSuccess;}
    //Select
    vector<Computer> getComputersConnectedToCS(const int scientistID);
    vector<CSPerson> getCSConntedToComputer(const int computerID);
    void getComputerScientists(vector<CSPerson>& computerScientists);
    void getComputers(vector<Computer>& computers);
    void getComputerTypes(vector<string>& computerTypes);
    vector<CSPerson> getComputerScientistsTrashCan();
    vector<Computer> getComputerTrashCan();
    bool computerScientistExist(const string& name);
    void searchScientist(vector<CSPerson>& scientist, const string searchFor);
    void searchComputer(vector<Computer>& computer, const string searchFor);
    //Insert
    bool addComputerType(const string computerName);
    bool addCStoComputer(const int cSID,const int compID);
    int addComputerScientist(const CSPerson value);
    int addComputer(const Computer value);
    //Update
    bool updateComputerScientist(CSPerson& computerScientist);
    bool updateComputer(Computer& computer);
    //Delete
    bool removeComputerScientist(const int& scientistID);
    bool removeComputer(const int& computerID);

};


#endif // DBCON_H
