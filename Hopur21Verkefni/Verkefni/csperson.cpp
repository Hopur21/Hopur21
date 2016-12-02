#include <csperson.h>

CSPerson::CSPerson(string name, string gender, int birthYear, int passedAwayYear, string comment)
{
   _name = name;
   _gender = gender;
   _birthYear = birthYear;
   _passedAwayYear = passedAwayYear;
   _comment = comment;
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
    const int ALIVE = 0;
    int age = 0;
    if(_passedAwayYear == ALIVE)
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
