#include "models/csperson.h"

CSPerson::CSPerson(const int id, const string name, const string gender, const int birthYear, const int passedAwayYear, const string comment, const bool isAlive,const int imageID,const QByteArray imageByteArray,const string imageName)
{
    _id = id;
    _name = name;
    _gender = gender;
    _birthYear = birthYear;
    _passedAwayYear = passedAwayYear;
    _comment = comment;
    _isAlive = isAlive;
    //If imageID is not negative (which is default value)
    if(imageID >=0)
    {
        setImageInfo(imageID, imageByteArray,imageName);
    }
}
void CSPerson::setImageInfo(int imageID,QByteArray imageByteArray, string imageName)
{
    _myImage.setImageValues(imageByteArray,imageName,imageID);
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
