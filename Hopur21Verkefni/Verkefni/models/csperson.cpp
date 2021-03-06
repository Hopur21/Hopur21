#include "models/csperson.h"

CSPerson::CSPerson(const int id, const string name, const string gender, const int birthYear, const int passedAwayYear, const string comment, const bool isAlive)
{
    _id = id;
    _name = name;
    _gender = gender;
    _birthYear = birthYear;
    _passedAwayYear = passedAwayYear;
    _comment = comment;
    _isAlive = isAlive;
}

int CSPerson::getCurrentYear()
{
    time_t timeNow = time(0);
    tm *ltm = localtime(&timeNow);
    int year = ltm->tm_year + 1900;
    return year;
}

int CSPerson::getAge()
{

    int age = 0;
    if(_passedAwayYear == stoi(constants::ALIVE))
    {
        age = getCurrentYear() - _birthYear;
    }
    else if(_passedAwayYear <= _birthYear)
    {
        return age;
    }
    else
    {
        age = _passedAwayYear - _birthYear;
    }
    return age;
}
