#ifndef SERVICE_H
#define SERVICE_H
#include <vector>
#include "services/computerservice.h"
#include "services/cspersonservice.h"
#include "models/computer.h"
#include "models/csperson.h"
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

    public:
        Service();

        //Sets
        bool addNewPersonToList(const string name,const string gender, const string birthYear, const string deathYear,const string comment);
        bool addNewComputerToList(const string name,const int designyear, const int buildyear, const string type, const bool created);
        bool removePersonFromList(const string id);

        //Gets
        vector <string> getComputerTypesList();
        vector<CSPerson> getComputerScientistList();
        vector<Computer> getComputerList();

        vector<CSPerson> searchByName(const string searchString);
        vector<CSPerson> searchByYearOfBirth(const string searchString);
        vector<CSPerson> searchByYearOfDeath(const string searchString);

        void sortListAlphabetically();
        void sortListAlphabeticallyASC();
        void sortListByGender();
        void sortListByDeathYear();
        void sortListByBirthYear();
        void sortListByBirthYearASC();
        void sortListByAge();


};

#endif // SERVICE_H
