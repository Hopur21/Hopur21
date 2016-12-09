#include "service.h"

Service::Service()
{
    updateAllLists();
}

bool Service::addNewPersonToList(const vector<int> computerConnectionID,const string name,const string gender, const string birthYear, const string deathYear,const string comment)
{
    if(_cSPersonService.addNewPersonToList(name, gender,birthYear, deathYear, comment))
    {
        return true;
    }
    return false;
}

bool Service::addNewComputerToList(const vector<int> scientistConnectionID,const string name,const int designYear, const int buildYear, const string type, const bool created)
{
    Computer newComputer;
    int computerID = 0;
    if(_computerService.addNewComputerToList(newComputer, name, designYear, buildYear, type, created))
    {
        computerID = _dbCon.addComputer(newComputer);
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
void Service::updateComputerTypesList()
{
    _dbCon.getComputerTypes(_computerTypes);
}
void Service::updateComputerList()
{
    _dbCon.getComputers(_computerList);
}
void Service::updateComputerScientistList()
{
    _dbCon.getComputerScientists(_computerScientists);
}
void Service::updateAllLists()
{
    updateComputerScientistList();
    updateComputerList();
    updateComputerTypesList();
}



//Computer scientist Sorts
void Service::sortScientistListAlphabetically()
{
    _cSPersonService.sortByName(_computerScientists);
}

void Service::sortScientistListAlphabeticallyDESC()
{
    _cSPersonService.sortByNameDESC(_computerScientists);
}

void Service::sortScientistListByGender()
{
    _cSPersonService.sortByGender(_computerScientists);
}

void Service::sortScientistListByDeathYear()
{
    _cSPersonService.sortByDeathYear(_computerScientists);
}

void Service::sortScientistListByBirthYear()
{
    _cSPersonService.sortByBirthYear(_computerScientists);
}

void Service::sortScientistListByBirthYearASC()
{
    _cSPersonService.sortByBirthYearASC(_computerScientists);
}

void Service::sortScientistListByAge()
{
    _cSPersonService.sortByAge(_computerScientists);
}
// Computer Sorts
void Service::sortComputerListAlphabetically()
{
    _computerService.sortByName(_computerList);
}

void Service::sortComputerListAlphabeticallyDESC()
{
    _computerService.sortByNameDESC(_computerList);
}

void Service::sortComputertListByBuildYear()
{
    _computerService.sortByBuildYear(_computerList);
}

void Service::sortComputerListByDesignYear()
{
    _computerService.sortByDesignYear(_computerList);
}

void Service::sortComputerListByType()
{
    _computerService.sortByType(_computerList);
}

void Service::sortComputerListWasBuilt()
{
    _computerService.sortWasBuilt(_computerList);
}





//Þau föll sem er ekki búið að fara yfir fyrir (aðlaga) Viku2





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

vector<Computer> Service::searchComputerByName(const string searchString)
{
    // TODO
    vector <Computer> searchByName; // = _computerService.searchByName;
    return searchByName;
}

vector<Computer> Service::searchComputerByType(const string searchString)
{
    // TODO
    vector <Computer> searchByType; // = _computerService.searchByType
    return searchByType;
}
vector<Computer> Service::searchComputerByYear(const string searchString)
{
    // TODO
    vector <Computer> searchByYear;
    return searchByYear;
}



