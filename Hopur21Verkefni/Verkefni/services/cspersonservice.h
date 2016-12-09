#ifndef CSPERSONSERVICE_H
#define CSPERSONSERVICE_H
#include <algorithm>
#include <vector>
#include "models/csperson.h"

class CSPersonService
{
    public:
        CSPersonService();

        //Sets
        void setCompleteList();
        bool addNewPersonToList(const string name,const string gender, const string birthYear, const string deathYear,const string comment);
        bool removePersonFromList(const string id);
        bool editPersonFromList(const string oldID, CSPerson person);
        void sortByName(vector<CSPerson>& computerScientists);
        void sortByNameDESC(vector<CSPerson>& computerScientists);
        void sortByGender(vector<CSPerson>& computerScientists);
        void sortByDeathYear(vector<CSPerson>& computerScientists);
        void sortByBirthYear(vector<CSPerson>& computerScientists);
        void sortByBirthYearASC(vector<CSPerson>& computerScientists);
        void sortByAge(vector<CSPerson>& computerScientists);

        //Gets
        vector<CSPerson> searchByName(const string searchString);
        vector<CSPerson> searchByYearOfBirth(const string searchString);
        vector<CSPerson> searchByYearOfDeath(const string searchString);

    private:
        //Sets
        void removeNodeFromList(const int index);

        //Gets
        int getIndexOfValueByName(const string name);
        bool validNumber(string number);
        bool checkIfStringSameIgnoreUpper(string orginalString, string searchFor);

};

#endif // CSPERSONSERVICE_H
