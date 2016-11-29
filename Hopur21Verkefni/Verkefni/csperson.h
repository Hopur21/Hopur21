#ifndef CSPERSON_H
#define CSPERSON_H

#include <string>
#include <listaccess.h>
using namespace std;

class CSPerson
{
    private:
        string _name;
        string _gender;
        int _birthYear;
        int _deathYear;
        string _comment;
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
