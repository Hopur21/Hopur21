#ifndef CSPERSON_H
#define CSPERSON_H

#include <string>
#include <listaccess.h>
using namespace std;

class CSPerson
{
    private:
        string name;
        string gender;
        int birthYear;
        int deathYear;
        //ListAccess lA;

    public:
        CSPerson();
        void addPerson();
        void printPerson();
};

#endif // CSPERSON_H
