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


        /* frá Dabs
        string getName() const
            {
                return _name;
            }

            int getAge() const
            {
                return _age;
            }
         */
};

#endif // CSPERSON_H
