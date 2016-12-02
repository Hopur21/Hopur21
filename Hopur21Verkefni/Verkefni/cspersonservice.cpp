#include "cspersonservice.h"

//Bool variablers are used in sorting to decide the order of sorting, DESCending and ASCending
bool sortByNameDESC(const CSPerson &lhs, const CSPerson &rhs) { return lhs.getName() < rhs.getName(); }
bool sortByNameASCC(const CSPerson &lhs, const CSPerson &rhs) { return lhs.getName() > rhs.getName(); }
bool sortByGenderDESC(const CSPerson &lhs, const CSPerson &rhs) { return lhs.getGender() < rhs.getGender(); }
bool sortByDeathYearASCC(const CSPerson &lhs, const CSPerson &rhs) {return lhs.getPassedAwayYear() > rhs.getPassedAwayYear(); }
bool sortByBirthYearDESC(const CSPerson &lhs, const CSPerson &rhs) {return lhs.getBirthYear() < rhs.getBirthYear(); }
bool sortByBirthYearASCC(const CSPerson &lhs, const CSPerson &rhs) {return lhs.getBirthYear() > rhs.getBirthYear(); }
bool sortByAgeASCC(const CSPerson &lhs, const CSPerson &rhs)
{
    CSPerson tempLeft = lhs;//Copy our const into a temp variable, so we can work with our int value and get the age.
    CSPerson tempRight = rhs;
    return tempLeft.getAge() > tempRight.getAge();
}

CSPersonService::CSPersonService()
{
    _fileKeeper = _data.readFromFile();
}

bool CSPersonService::addNewPersonToList(const string name,const string gender, string birthYear, string deathYear,const string comment)
{
    //We will set years to 0 if they are not valid.
    int tempBirthYear = 0, tempDeathYear = 0;
    if(validNumber(birthYear)) //If number is valid
    {
        tempBirthYear = stoi(birthYear);
        //tempBirthYear = birthYear;
    }
    if(validNumber(deathYear))
    {
        tempDeathYear = stoi(deathYear);
        //tempDeathYear = deathYear;
    }
    //Save our new person in our vector
    _fileKeeper.push_back(CSPerson (name, gender, tempBirthYear, tempDeathYear, comment));
    _data.writeToFile(_fileKeeper);// Write our updated vector to file
    return true;//Return true that we made it
}
//We take in id as a string to avoid strange letters/input
bool CSPersonService::removePersonFromList(const string id)
{
    size_t index = 0;
    try
    {
        index = stoi(id);
        index--; //Off by one
    }
    catch(int e)
    {
        return false;
    }
    if(index < _fileKeeper.size())
    {
        removeNodeFromList(index);
        return true;//Return true that we successfully removed the person
    }
    return false;
}
bool CSPersonService::editPersonFromList(const string oldID, CSPerson person)
{
    size_t index = 0;
    try
    {
        index = stoi(oldID);
        index--; //Off by one
    }
    catch(int e)
    {
        return false;
    }
    if(index < _fileKeeper.size())
    {
        _fileKeeper[index] = person;
        _data.writeToFile(_fileKeeper);
        return true;//Return true that we successfully edited the person
    }
    return false;
}

int CSPersonService::getIndexOfValueByName(const string name)
{
    for(size_t i = 0; i < _fileKeeper.size(); i++)
    {
        if(name == _fileKeeper[i].getName())
        {
            return i;
        }
    }
    return -1;//Return value less then 0
}
void CSPersonService::removeNodeFromList(const int index)
{
    _fileKeeper.erase(_fileKeeper.begin() + index);
    _data.writeToFile(_fileKeeper);
}

//Search by name, find every value that we find and return all of those values in a vector
vector<CSPerson> CSPersonService::searchByName(const string searchString)
{
    vector<CSPerson> tempVector;
    for(size_t i = 0; i < _fileKeeper.size(); i++)
    {
        if(checkIfStringSameIgnoreUpper(_fileKeeper[i].getName(), searchString))
        {
            tempVector.push_back(_fileKeeper[i]);
        }
    }
    return tempVector;
}

bool CSPersonService::validNumber(string number)
{
    int inputNumber = 0;
    try
    {
        inputNumber = atoi(number.c_str());//Try to convert string to int
    }
    catch(int e)
    {
        return false;
    }
    if(inputNumber > 0  || inputNumber < 3000)//If the year is beetween 1 - 2999
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<CSPerson> CSPersonService::searchByYearOfBirth(const string searchString)
{
    vector<CSPerson> tempVector;
    if(validNumber(searchString))
    {
        for(size_t i = 0; i < _fileKeeper.size(); i++)
        {
            string temp = to_string(_fileKeeper[i].getBirthYear());
            if(checkIfStringSameIgnoreUpper(temp, searchString))
            {
                tempVector.push_back(_fileKeeper[i]);
            }
        }
    }
    return tempVector;
}

vector<CSPerson> CSPersonService::searchByYearOfDeath(const string searchString)
{
    vector<CSPerson> tempVector;
    if(validNumber(searchString))
    {
        for(size_t i = 0; i < _fileKeeper.size(); i++)
        {
            string temp = to_string(_fileKeeper[i].getPassedAwayYear());
            if(checkIfStringSameIgnoreUpper(temp, searchString))
            {
                tempVector.push_back(_fileKeeper[i]);
            }
        }
    }
    return tempVector;
}

//Returns true if string2 is a part of string1, no matter upper or lower case.
bool CSPersonService::checkIfStringSameIgnoreUpper(string orginalString, string searchFor)
{
    //Make sure both strings are the same case
    transform(orginalString.begin(), orginalString.end(),orginalString.begin(), ::tolower);
    transform(searchFor.begin(), searchFor.end(),searchFor.begin(), ::tolower);
    if(orginalString.find(searchFor) != string::npos)//If string.find is not size_t max size
    {
        return true;
    }
    else
    {
        return false;
    }
}


//Sorts

void CSPersonService::sortByName()
{
    sort(_fileKeeper.begin(), _fileKeeper.end(), sortByNameDESC);
    _data.writeToFile(_fileKeeper);//Write our change to the file
}
void CSPersonService::sortByNameASC()
{
    sort(_fileKeeper.begin(), _fileKeeper.end(), sortByNameASCC);
    _data.writeToFile(_fileKeeper);
}
void CSPersonService::sortByGender()
{
    sort(_fileKeeper.begin(), _fileKeeper.end(), sortByGenderDESC);
    _data.writeToFile(_fileKeeper);
}
void CSPersonService::sortByDeathYear()
{
    sort(_fileKeeper.begin(), _fileKeeper.end(), sortByDeathYearASCC);
    _data.writeToFile(_fileKeeper);
}
void CSPersonService::sortByBirthYear()
{
    sort(_fileKeeper.begin(), _fileKeeper.end(), sortByBirthYearDESC);
    _data.writeToFile(_fileKeeper);
}
void CSPersonService::sortByBirthYearASC()
{
    sort(_fileKeeper.begin(), _fileKeeper.end(), sortByBirthYearASCC);
    _data.writeToFile(_fileKeeper);
}
void CSPersonService::sortByAge()
{
    sort(_fileKeeper.begin(), _fileKeeper.end(), sortByAgeASCC);
    _data.writeToFile(_fileKeeper);
}
