#include "cspersonservice.h"
CSPersonService::CSPersonService()
{
    //Test
    DataLayer _data;
}

void CSPersonService::newPerson(string name, string gender, int birthYear, int deathYear, string comment)
{
    CSPerson newP = CSPerson (name, gender, birthYear, deathYear, comment);
}
