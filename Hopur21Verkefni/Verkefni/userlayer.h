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
        void birthYearValidation(string birthYear);
        void printGenderMenu();
    public:
        UserLayer();
        void addPerson();
        void sortListAlphabetically();
        void sortListByGender();
        void sortListByDeathYear();
        void sortListByBirthYear();
        void searchForAPerson();
};

#endif // USERLAYER_H
