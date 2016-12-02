#ifndef USERLAYER_H
#define USERLAYER_H

#include "cspersonservice.h"
#include <iostream>
using namespace std;

class UserLayer
{
    private:
        CSPersonService _CSPServ;
        void printList(vector<CSPerson> list);
        bool checkNumberValidity(string userInput);
        string birthYearValidation(string birthYear);
        string deathYearValidation(string birthYear, string deathYear);
        void printGenderMenu();

    public:
        UserLayer();
        void addPerson();
        void removePersonFromList();
        void sortListAlphabetically();
        void sortListByGender();
        void sortListByDeathYear();
        void sortListByBirthYear();
        void sortListByAge();
        void searchForAPerson();
<<<<<<< HEAD
        void printCompleteList();
=======
        void invalidInput();
>>>>>>> 7ca110317992c3dc0c410c37dfd19f9a580830bd
};

#endif // USERLAYER_H
