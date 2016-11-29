#ifndef CSPERSON_H
#define CSPERSON_H
#include<string>

using namespace std;

class CSPerson
{
    private:
        string _name;
        string _gender;
        int _birthYear;
        int _passedAwayYear;
        string _comment;

    public:
        CSPerson();

        CSPerson(const string name, const string gender, const int birthYear, const int deathYear, const string comment);

        //Gets
        string getName()const {return _name;};
        string getGender()const {return _gender;};
        int getBirthyear()const {return _birthYear;};
        int getPassedAwayYear()const {return _passedAwayYear;};
        string getComments()const {return _comment;};

        //Sets
        void setName(const string name){_name = name;};
        void setGender(const string gender){_gender = gender;};
        void setBirthYear(const int birthyear){_birthYear = birthyear;};
        void setPassedAwayYear(const int year){_passedAwayYear = year;};
        void setComment(const string comment){_comment = comment;};
};

#endif // CSPERSON_H
