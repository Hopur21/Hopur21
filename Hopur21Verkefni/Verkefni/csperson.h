#ifndef CSPERSON_H
#define CSPERSON_H
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
        //UserLayer uL;

    public:
        CSPerson();

        CSPerson(string name, string gender, int birthYear, int deathYear, string comment);


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
