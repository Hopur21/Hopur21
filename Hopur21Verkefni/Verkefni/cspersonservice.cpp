#include "cspersonservice.h"

#include<iostream>
using namespace std;
CSPersonService::CSPersonService()
{
    _fileKeeper = _data.readFromFile();
    searchByName("Gol");
}

void CSPersonService::newPerson(string name, string gender, int birthYear, int deathYear, string comment)
{
    CSPerson newP = CSPerson (name, gender, birthYear, deathYear, comment);
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
