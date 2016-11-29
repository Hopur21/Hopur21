#ifndef CSPERSON_H
#define CSPERSON_H
#include "userlayer.h"
#include <iostream>
#include <string>


using namespace std;

class CSPerson
{
    private:
        string _name;
        string _gender;
        int _birthYear;
        int _deathYear;
        string _comment;
        UserLayer uL;

    public:
        CSPerson();
<<<<<<< HEAD
        CSPerson(string name, string gender, int birthYear, int deathYear, string comment);

=======
>>>>>>> f88331df252f3a2115c3926a786eca266839a200

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
