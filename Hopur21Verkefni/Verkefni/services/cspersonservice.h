#ifndef CSPERSONSERVICE_H
#define CSPERSONSERVICE_H
#include <algorithm>
#include <vector>
#include "models/csperson.h"
#include "repositories/datalayer.h"
#include "repositories/dbcon.h"

class CSPersonService
{
    public:
        CSPersonService();
        void getCompleteList(vector<CSPerson>& storage){storage = _fileKeeper;}

        //Sets
        void setCompleteList();
        bool addNewPersonToList(const string name,const string gender, const string birthYear, const string deathYear,const string comment);
        bool removePersonFromList(const string id);
        bool editPersonFromList(const string oldID, CSPerson person);
        void sortByName();
        void sortByNameASC();
        void sortByGender();
        void sortByDeathYear();
        void sortByBirthYear();
        void sortByBirthYearASC();
        void sortByAge();

        //Gets
        vector<CSPerson> searchByName(const string searchString);
        vector<CSPerson> searchByYearOfBirth(const string searchString);
        vector<CSPerson> searchByYearOfDeath(const string searchString);

    private:
        vector<CSPerson> _fileKeeper;
        DbCon _dbCon;
        DataLayer _data; //TODO að fjarlægja!

        //Sets
        void removeNodeFromList(const int index);

        //Gets
        int getIndexOfValueByName(const string name);
        bool validNumber(string number);
        bool checkIfStringSameIgnoreUpper(string orginalString, string searchFor);

};

#endif // CSPERSONSERVICE_H
