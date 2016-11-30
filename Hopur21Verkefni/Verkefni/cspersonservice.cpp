#include "cspersonservice.h"
CSPersonService::CSPersonService()
{
    _fileKeeper = _data.readFromFile();
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
