#ifndef USERLAYER_H
#define USERLAYER_H

#include "cspersonservice.h"
#include <iostream>
using namespace std;

class UserLayer
{
    private:
        CSPersonService _CSPS;
    public:
        UserLayer();
        void addPerson();
        bool checkNumberValidity(string userInput);
        void birthYearValidation(string birthYear);
        void printList();

};

#endif // USERLAYER_H
