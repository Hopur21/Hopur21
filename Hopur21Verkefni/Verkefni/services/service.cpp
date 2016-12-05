#include "service.h"

Service::Service()
{

}

bool Service::addNewPersonToList(const string name,const string gender, const string birthYear, const string deathYear,const string comment)
{
    return _cSPersonService.addNewPersonToList(name, gender,birthYear, deathYear, comment);
}

bool Service::removePersonFromList(const string id)
{
    return _cSPersonService.removePersonFromList(id);
}

vector<CSPerson> Service::getCompleteList()
{
    return _cSPersonService.getCompleteList();
}

void Service::sortListAlphabetically()
{
    _cSPersonService.sortByName();
}

void Service::sortListAlphabeticallyASC()
{
    _cSPersonService.sortByNameASC();
}

void Service::sortListByGender()
{
    _cSPersonService.sortByGender();
}

void Service::sortListByDeathYear()
{
    _cSPersonService.sortByDeathYear();
}

void Service::sortListByBirthYear()
{
    _cSPersonService.sortByBirthYear();
}

void Service::sortListByBirthYearASC()
{
    _cSPersonService.sortByBirthYearASC();
}

void Service::sortListByAge()
{
    _cSPersonService.sortByAge();
}

vector<CSPerson> Service::searchByName(const string searchString)
{
    _cSPersonService.searchByName(searchString);
}

vector<CSPerson> Service::searchByYearOfBirth(const string searchString)
{
    _cSPersonService.searchByYearOfBirth(searchString);
}

vector<CSPerson> Service::searchByYearOfDeath(const string searchString)
{
    _cSPersonService.searchByYearOfDeath(searchString);
}





