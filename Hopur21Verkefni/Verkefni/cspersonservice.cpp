#include "cspersonservice.h"
CSPersonService::CSPersonService()
{
    _fileKeeper = _data.readFromFile();
}

void CSPersonService::newPerson(string name, string gender, int birthYear, int deathYear, string comment)
{
    CSPerson newP = CSPerson (name, gender, birthYear, deathYear, comment);
}
