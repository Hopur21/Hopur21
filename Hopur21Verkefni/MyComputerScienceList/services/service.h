#ifndef SERVICE_H
#define SERVICE_H
#include <vector>
#include "models/computer.h"
#include "models/csperson.h"
#include "repositories/dbcon.h"
#include <string>

class Service
{
    public:
        Service();
        //Sets
        bool addNewPersonToList(const vector<int> computerConnectionID, const string name,const string gender, const string birthYear, const string deathYear,const string comment, string imageName = "", QByteArray image = NULL);
        bool addNewComputerToList(const vector<int> scientistConnectionID,const string name,const int designyear, const int buildyear, const string typeRealID, const bool created, string imageName = "", QByteArray image = NULL);
        bool addComputerType(const string typeName);
        bool restorePersonToList(const int id);
        bool restoreComputerToList(const int id);
        bool removePersonFromList(const string id);
        bool removeComputerFromList(const string id);
        void updateAllLists();
        void updateComputerList();
        void updateComputerScientistList();
        void updateComputerTypesList();
        bool onlyAddPicturetoDB(const string picName, QByteArray picture);
        //Gets
        vector <ComputerType> getComputerTypesList(){return _computerTypes;}
        vector<CSPerson> getComputerScientistList(const string filter);
        vector<Computer> getComputerList(const string filter);
        vector<CSPerson> getScientistConntedToComputers(const int computerID);
        vector<Computer> getComputersConntedToCS(const int computerScientistID);
        vector<CSPerson> getComputerScientistTrash(const string filter);
        vector<Computer> getComputerTrash(const string filter);
        //Search
        vector<CSPerson> searchComputerScientist(const string searchString);
        vector<Computer> searchComputer(const string searchString);
        vector<ComputerScientistToComputer> getCSandCompConnection();

    private:
        vector<CSPerson> _computerScientists;
        vector<Computer> _computerList;
        vector <ComputerType> _computerTypes;
        DbCon _dbCon;
        bool validNumber(string number);

};

#endif // SERVICE_H
