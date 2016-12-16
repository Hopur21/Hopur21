#ifndef SERVICE_H
#define SERVICE_H
#include <vector>
#include "models/computer.h"
#include "models/csperson.h"
#include "models/computerscientisttocomputer.h"
#include "services/computerservice.h"
#include "services/cspersonservice.h"
#include "repositories/dbcon.h"
#include <string>

class Service
{
    private:
        vector<CSPerson> _computerScientists;
        vector<Computer> _computerList;
        vector <ComputerType> _computerTypes;
        vector<ComputerScientistToComputer> _connection;

        DbCon _dbCon;
        ComputerService _computerService;
        CSPersonService _cSPersonService;

        bool validNumber(string number);

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
        vector<ComputerScientistToComputer> getCSandCompConnection();
        //Search
        vector<CSPerson> searchComputerScientist(const string searchString);
        vector<Computer> searchComputer(const string searchString);
        /*
        //Scientist Sorts
        void sortScientistListAlphabetically();
        void sortScientistListAlphabeticallyDESC();
        void sortScientistListByGender();
        void sortScientistListByDeathYear();
        void sortScientistListByBirthYear();
        void sortScientistListByBirthYearASC();
        void sortScientistListByAge();
        //Computer Sorts
        void sortComputerListAlphabetically();
        void sortComputerListAlphabeticallyDESC();
        void sortComputertListByBuildYear();
        void sortComputerListByDesignYear();
        void sortComputerListByType();
        void sortComputerListWasBuilt();
        */

};

#endif // SERVICE_H
