#include "service.h"

Service::Service()
{
    updateAllLists();
}

bool Service::addNewPersonToList(const vector<int> computerConnectionID,const string name,const string gender, const string birthYear, const string deathYear,const string comment)
{
    CSPerson newPerson;
    int newPersonID;
    newPerson.setName(name);
    newPerson.setGender(gender);
    newPerson.setBirthYear(stoi(birthYear));
    newPerson.setPassedAwayYear(stoi(deathYear));
    if(deathYear != constants::ALIVE) {
        newPerson.setIsAlive(false);
    } else {
        newPerson.setIsAlive(true);
    }
    newPerson.setComment(comment);
    newPersonID = _dbCon.addComputerScientist(newPerson);
    for(unsigned int i = 0; i < computerConnectionID.size(); i++)
    {
        _dbCon.addCStoComputer(newPersonID,computerConnectionID[i]);
    }
    updateComputerScientistList();
    return true;
}


bool Service::addNewComputerToList(const vector<int> scientistConnectionID, const string name, const int designYear, const int buildYear, const string typeRealID, const bool created)
{
    Computer newComputer;
    int newComputerID = 0;
    newComputer.setName(name);
    newComputer.setDesignYear(designYear);
    newComputer.setBuildYear(buildYear);
    newComputer.setTypeID(typeRealID);
    newComputer.setCreated(created);
    newComputerID = _dbCon.addComputer(newComputer);
    //Assign computer to computer scientists
    for(unsigned int i = 0; i < scientistConnectionID.size(); i++)
    {
        _dbCon.addCStoComputer(scientistConnectionID[i],newComputerID);
    }
    updateComputerList();
    return true;
}

bool Service::removePersonFromList(const string id)
{
    if(!validNumber(id))
    {
        return false;
    }
    return _dbCon.removeComputerScientist(stoi(id));
}

bool Service::removeComputerFromList(const string id)
{
    if(!validNumber(id))
    {
        return false;
    }
    return _dbCon.removeComputer(stoi(id));
}
vector<CSPerson> Service::getScientistConntedToComputers(const int computerID)
{
    return _dbCon.getCSConntedToComputer(computerID);
}
vector<Computer> Service::getComputersConntedToCS(const int computerScientistID)
{
    return _dbCon.getComputersConnectedToCS(computerScientistID);
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
bool Service::validNumber(string number)
{
    try
    {
        stoi(number);
        return true;
    }
    catch(int e)
    {
        return false;
    }
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
vector<CSPerson> Service::searchComputerScientist(const string searchString)
{
    vector <CSPerson> searchCS;
    _dbCon.searchScientist(searchCS,searchString);
    return searchCS;
}
vector<Computer> Service::searchComputer(const string searchString)
{
    vector<Computer> searchComputer;
    _dbCon.searchComputer(searchComputer, searchString);
    return searchComputer;
}
