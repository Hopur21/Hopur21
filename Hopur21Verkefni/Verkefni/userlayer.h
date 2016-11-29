#ifndef USERLAYER_H
#define USERLAYER_H

#include "cspersonservice.h"
#include <iostream>
using namespace std;

class UserLayer
{
    private:
        CSPersonService CSPS;
    public:
        UserLayer();
        void addPerson();
};

#endif // USERLAYER_H
