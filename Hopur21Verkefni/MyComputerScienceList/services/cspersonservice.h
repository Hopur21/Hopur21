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
        /*
        void sortByName(vector<CSPerson>& computerScientists);
        void sortByNameDESC(vector<CSPerson>& computerScientists);
        void sortByGender(vector<CSPerson>& computerScientists);
        void sortByDeathYear(vector<CSPerson>& computerScientists);
        void sortByBirthYear(vector<CSPerson>& computerScientists);
        void sortByBirthYearASC(vector<CSPerson>& computerScientists);
        void sortByAge(vector<CSPerson>& computerScientists);
        */
        //Gets
        vector<CSPerson> searchByName(const string searchString);
        vector<CSPerson> searchByYearOfBirth(const string searchString);
        vector<CSPerson> searchByYearOfDeath(const string searchString);

    private:
        //Gets
        bool validNumber(string number);
        bool checkIfStringSameIgnoreUpper(string orginalString, string searchFor);

};

#endif // CSPERSONSERVICE_H
