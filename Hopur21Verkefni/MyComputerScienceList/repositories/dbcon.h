#ifndef DBCON_H
#define DBCON_H
#include <QSqlDatabase>
#include <QtSql>
#include "models/csperson.h"
#include "models/computer.h"
#include "models/computerscientisttocomputer.h"

using namespace std;
class DbCon
{
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
        void getComputerTypes(vector<ComputerType>& computerTypes);
        vector<CSPerson> getComputerScientistsTrashCan();
        vector<Computer> getComputerTrashCan();
        bool computerScientistExist(const string& name);
        void searchScientist(vector<CSPerson>& scientist, const string searchFor, const bool removed);
        void searchComputer(vector<Computer>& computer, const string searchFor, const bool removed);
        //Insert
        int addPicture(const string imageName, const QByteArray image);
        bool addComputerType(string computerName);
        bool addCStoComputer(const int cSID,const int compID);
        int addComputerScientist(CSPerson value);
        int addComputer(Computer value);
        //Update
        bool updateComputerScientist(CSPerson& computerScientist);
        bool updateComputer(Computer& computer);
        //Delete
        bool removeComputerScientist(const int& scientistID);
        bool removeComputer(const int& computerID);
        //Restore
        bool restoreComputerScientist(const int& scientistID);
        bool restoreComputer(const int& computerID);
        vector<ComputerScientistToComputer> getCscientistToComps();
private:
        bool _connectionSuccess;
        bool makeConnection();
        QSqlDatabase _db;
        QString _hostname;
        QString _databaseName;
        QString _username;
        QString _password;
        //Sets
        void runSelectForScientist(QSqlQuery& query, vector<CSPerson>& scientist);
        void runSelectForComputers(QSqlQuery& query, vector<Computer>& computers);
        void setDataInPersonVector(vector<CSPerson>& computerScientists, const int id, const string name, const string gender, const int birthYear, const int passedAwayYear, const string comment, const bool isAlive, const int imageID, const string imageName, const QByteArray imageByteArray);
        void setDataInComputerVector(vector<Computer>& computers, const int id, const string name, const int designYear, const int buildYear, const string type,const string typeID, const bool isCreated, const int imageID, const string imageName, const QByteArray imageByteArray);
        void setDataInTypeVector(vector<ComputerType>& computerTypes,int id, string name);
        //Gets
        QString getDateFormat(const string& year);
};

#endif // DBCON_H
