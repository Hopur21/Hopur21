#ifndef LISTACCESS_H
#define LISTACCESS_H

#include <iostream>
#include <csperson.h>
#include <vector>

using namespace std;

class ListAccess
{
    private:
        vector<CSPerson> listOfCSPersons;
    public:
        void addToList(CSPerson p);
};

#endif // LISTACCESS_H
