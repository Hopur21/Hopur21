#ifndef CSPERSON_H
#define CSPERSON_H
#include<string>
#include <ctime>
#include "utilities/constants.h"

using namespace std;

class CSPerson
{
    private:
        bool _isAlive;
        string _name;
        string _gender;
        string _comment;
        int _id;
        int _birthYear;
        int _passedAwayYear;
        int getCurrentYear();

    public:
        CSPerson(){}
        CSPerson(const int id, const string name, const string gender, const int birthYear, const int passedAwayYear, const string comment, const bool isAlive);

        //Gets
        string getName()const {return _name;}
        string getGender()const {return _gender;}
        int getBirthYear()const {return _birthYear;}
        int getPassedAwayYear()const {return _passedAwayYear;}
        int getID(){return _id;}
        int getAge();
        bool getIsAlive()const {return _isAlive;}

        string getComments()const {return _comment;}

        //Sets
        void setName(const string name){_name = name;}
        void setGender(const string gender){_gender = gender;}
        void setBirthYear(const int birthyear){_birthYear = birthyear;}
        void setPassedAwayYear(const int year){_passedAwayYear = year;}
        void setComment(const string comment){_comment = comment;}
        void setID(const int ID){_id = ID;}
        void setIsAlive(const bool isAlive){_isAlive = isAlive;}
};

#endif // CSPERSON_H
