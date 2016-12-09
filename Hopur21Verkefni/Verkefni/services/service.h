#ifndef SERVICE_H
#define SERVICE_H
#include <vector>
#include "models/computer.h"
#include "models/csperson.h"
#include "services/computerservice.h"
#include "services/cspersonservice.h"
#include "repositories/dbcon.h"
#include <string>

class Service
{
    private:
        vector<CSPerson> _computerScientists;
        vector<Computer> _computerList;
        vector <string> _computerTypes;

        DbCon _dbCon;
        ComputerService _computerService;
        CSPersonService _cSPersonService;

        bool validNumber(string number);

    public:
        Service();

        //Sets
        bool addNewPersonToList(const vector<int> computerConnectionID, const string name,const string gender, const string birthYear, const string deathYear,const string comment);
        bool addNewComputerToList(const vector<int> scientistConnectionID,const string name,const int designyear, const int buildyear, const string typeRealID, const bool created);
        bool removePersonFromList(const string id);
        bool removeComputerFromList(const string id);
        void updateAllLists();
        void updateComputerList();
        void updateComputerScientistList();
        void updateComputerTypesList();

        //Gets
        vector <string> getComputerTypesList(){return _computerTypes;}
        vector<CSPerson> getComputerScientistList(){return _computerScientists;}
        vector<Computer> getComputerList(){return _computerList;}
        vector<CSPerson> getScientistConntedToComputers(const int computerID);
        vector<Computer> getComputersConntedToCS(const int computerScientistID);
        vector<CSPerson> getComputerScientistTrash();
        vector<Computer> getComputerTrash();
        //Search
        vector<CSPerson> searchComputerScientist(const string searchString);
        vector<Computer> searchComputer(const string searchString);
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

};

#endif // SERVICE_H
