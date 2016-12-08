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

        void updateComputerList();
        void updateComputerScientistList();

    public:
        Service();

        //Sets
        bool addNewPersonToList(const vector<int> computerConnectionID, const string name,const string gender, const string birthYear, const string deathYear,const string comment);
        bool addNewComputerToList(const vector<int> scientistConnectionID,const string name,const int designyear, const int buildyear, const string type, const bool created);
        bool removePersonFromList(const string id);

        //Gets
        vector <string> getComputerTypesList();
        vector<CSPerson> getComputerScientistList();
        vector<Computer> getComputerList();

        vector<CSPerson> searchByName(const string searchString);
        vector<CSPerson> searchByYearOfBirth(const string searchString);
        vector<CSPerson> searchByYearOfDeath(const string searchString);

        vector<Computer> searchComputerByName(const string searchString);
        vector<Computer> searchComputerByType(const string searchString);
        vector<Computer> searchComputerByYear(const string searchString);


        void sortListAlphabetically();
        void sortListAlphabeticallyASC();
        void sortListByGender();
        void sortListByDeathYear();
        void sortListByBirthYear();
        void sortListByBirthYearASC();
        void sortListByAge();


};

#endif // SERVICE_H
