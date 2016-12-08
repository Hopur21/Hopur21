#include "service.h"

Service::Service()
{

}

bool Service::addNewPersonToList(const string name,const string gender, const string birthYear, const string deathYear,const string comment)
{
    if(_cSPersonService.addNewPersonToList(name, gender,birthYear, deathYear, comment))
    {
        return true;
    }
    return false;
}

bool Service::addNewComputerToList(const string name,const int designyear, const int buildyear, const string type, const bool created)
{
    if(_computerService.addNewComputerToList(name, designyear, buildyear, type, created))
    {
        return true;
    }
    return false;
}

bool Service::removePersonFromList(const string id)
{
    if (_cSPersonService.removePersonFromList(id))
    {
        return true;
    }
    return false;
}

vector<CSPerson> Service::getCompleteList()
{
    _cSPersonService.getCompleteList(_fileKeeper);
    return _fileKeeper;
}








//Þau föll sem er ekki búið að fara yfir fyrir (aðlaga) Viku2



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
    vector <CSPerson> searchByName = _cSPersonService.searchByName(searchString);
    return searchByName;
}

vector<CSPerson> Service::searchByYearOfBirth(const string searchString)
{
    vector <CSPerson> searchByYOB = _cSPersonService.searchByYearOfBirth(searchString);
    return searchByYOB;
}

vector<CSPerson> Service::searchByYearOfDeath(const string searchString)
{
    vector <CSPerson> searchByYOD = _cSPersonService.searchByYearOfDeath(searchString);
    return searchByYOD;
}

vector <string> Service::getListOfComputers()
{
    // Not finished
    vector <string> completeListOfComputers;
    return completeListOfComputers;
}
