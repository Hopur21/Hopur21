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

bool Service::addNewComputerToList(const string name,const int designYear, const int buildYear, const string type, const bool created)
{
    Computer newComputer;
    if(_computerService.addNewComputerToList(newComputer, name, designYear, buildYear, type, created))
    {
        _dbCon.addComputer(newComputer);
        return true;
    }
    return false;
}

bool Service::removePersonFromList(const string id)
{
    /*if (_cSPersonService.removePersonFromList(id))
    {
        return true;
    }*/
    return false;
}

vector<CSPerson> Service::getComputerScientistList()
{
    _dbCon.getComputerScientists(_computerScientists);
    return _computerScientists;
}
vector <string> Service::getComputerTypesList()
{
    // Not finished
    //Get list from DB

    return _computerTypes;
}
vector<Computer> Service::getComputerList()
{
    updateComputerList();
    return _computerList;
}
void Service::updateComputerList()
{
    _dbCon.getComputers(_computerList);
}






//Þau föll sem er ekki búið að fara yfir fyrir (aðlaga) Viku2



void Service::sortListAlphabetically()
{
    //_cSPersonService.sortByName();
}

void Service::sortListAlphabeticallyASC()
{
    //_cSPersonService.sortByNameASC();
}

void Service::sortListByGender()
{
    //_cSPersonService.sortByGender();
}

void Service::sortListByDeathYear()
{
    //_cSPersonService.sortByDeathYear();
}

void Service::sortListByBirthYear()
{
    //_cSPersonService.sortByBirthYear();
}

void Service::sortListByBirthYearASC()
{
    //_cSPersonService.sortByBirthYearASC();
}

void Service::sortListByAge()
{
    //_cSPersonService.sortByAge();
}

vector<CSPerson> Service::searchByName(const string searchString)
{
    vector <CSPerson> searchByName;// = _cSPersonService.searchByName(searchString);
    return searchByName;
}

vector<CSPerson> Service::searchByYearOfBirth(const string searchString)
{
    vector <CSPerson> searchByYOB;// = _cSPersonService.searchByYearOfBirth(searchString);
    return searchByYOB;
}

vector<CSPerson> Service::searchByYearOfDeath(const string searchString)
{
    vector <CSPerson> searchByYOD;// = _cSPersonService.searchByYearOfDeath(searchString);
    return searchByYOD;
}


