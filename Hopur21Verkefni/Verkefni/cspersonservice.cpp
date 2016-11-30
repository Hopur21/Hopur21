#include "cspersonservice.h"

#include<iostream>
using namespace std;
CSPersonService::CSPersonService()
{
    _fileKeeper = _data.readFromFile();
}

void CSPersonService::addNewPersonToList(const string name,const string gender, int birthYear, int deathYear,const string comment)
{
    int tempBirthYear = 0, tempDeathYear = 0;
    if(validNumber(to_string(birthYear))) //If number is valid
    {
        tempBirthYear = birthYear;
    }
    if(validNumber(to_string(deathYear)))
    {
        tempDeathYear = deathYear;
    }

    _fileKeeper.push_back(CSPerson (name, gender, tempBirthYear, tempDeathYear, comment));
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
    return -1;
}
void CSPersonService::removeNodeFromList(const int index)
{
    _fileKeeper.erase(_fileKeeper.begin() + index +1); //+1 = off by one
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

//Returns true/false if the string2 is in string1, no matter upper or lower case.
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
