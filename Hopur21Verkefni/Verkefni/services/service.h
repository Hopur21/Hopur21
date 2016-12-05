#ifndef SERVICE_H
#define SERVICE_H
#include "services/computerservice.h"
#include "services/cspersonservice.h"

class Service
{
    private:
        ComputerService _computerService;
        CSPersonService _cSPersonService;

    public:
        Service();
        bool addNewPersonToList(const string name,const string gender, const string birthYear, const string deathYear,const string comment);
        bool removePersonFromList(const string id);
        vector<CSPerson> getCompleteList();

        vector<CSPerson> searchByName(const string searchString);
        vector<CSPerson> searchByYearOfBirth(const string searchString);
        vector<CSPerson> searchByYearOfDeath(const string searchString);

        //
        void sortListAlphabetically();
        void sortListAlphabeticallyASC();
        void sortListByGender();
        void sortListByDeathYear();
        void sortListByBirthYear();
        void sortListByBirthYearASC();
        void sortListByAge();

        //
};

#endif // SERVICE_H
