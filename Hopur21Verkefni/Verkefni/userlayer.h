#ifndef USERLAYER_H
#define USERLAYER_H

#include "cspersonservice.h"
#include <iostream>
using namespace std;

class UserLayer
{
    private:
        CSPersonService _CSPServ;
    public:
        UserLayer();
        void addPerson();
        bool checkNumberValidity(string userInput);
        void birthYearValidation(string birthYear);
        void printList(vector<CSPerson> list);
        void sortListAlphabetically();
        void searchForAPerson();

};

#endif // USERLAYER_H
