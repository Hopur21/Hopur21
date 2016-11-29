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
<<<<<<< HEAD

=======
        void addPerson();
        void printPerson();
        CSPerson(string name, string gender, int birthYear, int deathYear, string comment);
>>>>>>> 380808f6980f8422c5f29af9df9fab07b2db839d

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
