#ifndef USERLAYER_H
#define USERLAYER_H

#include "services/cspersonservice.h"
#include <iostream>
using namespace std;

class UserLayer
{
    private:
        CSPersonService _CSPServ;
        void printList(vector<CSPerson> list);
        void printListMoreInfo(vector<CSPerson> list);
        bool checkNumberValidity(string userInput);
        string birthYearValidation(string birthYear);
        string deathYearValidation(string birthYear, string deathYear);
        void adjustForSpaces(int i);
        void printGenderMenu();

    public:
        UserLayer();
        void addPerson();
        void removePersonFromList();
        void sortListAlphabetically();
        void sortListAlphabeticallyASC();
        void sortListByGender();
        void sortListByDeathYear();
        void sortListByBirthYear();
        void sortListByBirthYearASC();
        void sortListByAge();
        void searchForAPerson();
        void printCompleteList();
        void invalidInput();
};

#endif // USERLAYER_H