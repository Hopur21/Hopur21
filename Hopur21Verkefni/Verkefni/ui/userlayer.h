#ifndef USERLAYER_H
#define USERLAYER_H
#include <iostream>
#include "services/service.h"
#include "models/csperson.h"
#include "models/computer.h"

using namespace std;

class UserLayer
{
    private:
        Service _service;
        void printList(vector<CSPerson> list);
        void printListMoreInfo(vector<CSPerson> list);
        bool checkNumberValidity(string userInput);
        string birthYearValidation(string birthYear);
        string deathYearValidation(string birthYear, string deathYear);
        void adjustForSpaces(int i);
        void printGenderMenu();

    public:
        UserLayer(){}
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
