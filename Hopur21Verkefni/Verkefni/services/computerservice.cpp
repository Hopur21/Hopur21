#include "computerservice.h"
//Bool variablers are used in sorting to decide the order of sorting, DESCending and ASCending
bool sortByNameDESCC(const Computer &lhs, const Computer &rhs) { return lhs.getName() > rhs.getName(); }
bool sortByNameASCC(const Computer &lhs, const Computer &rhs) { return lhs.getName() < rhs.getName(); }
bool sortByDesignYearASC(const Computer &lhs, const Computer &rhs) {return lhs.getDesignYear() < rhs.getDesignYear(); }
bool sortByBuiltYearASC(const Computer &lhs, const Computer &rhs) {return lhs.getBuildYear() > rhs.getBuildYear(); }
bool sortByTypeASC(const Computer &lhs, const Computer &rhs) { return lhs.getType() < rhs.getType(); }
bool sortByWasBuiltASC(const Computer &lhs, const Computer &rhs) {return lhs.getIsCreated() > rhs.getIsCreated(); }

ComputerService::ComputerService()
{
}
bool ComputerService::addNewComputerToList(Computer& newComputer, const string name,const int designyear, const int buildyear, const string typeID, const bool created)
{
    // VISTA Í GAGNAGRUNNI
    return true;
}


//Sorts
void ComputerService::sortByName(vector<Computer>& computerList)
{
    sort(computerList.begin(), computerList.end(), sortByNameASCC);
}
void ComputerService::sortByNameDESC(vector<Computer>& computerList)
{
    sort(computerList.begin(), computerList.end(), sortByNameDESCC);
}
void ComputerService::sortByDesignYear(vector<Computer>& computerList)
{
    sort(computerList.begin(), computerList.end(), sortByDesignYearASC);
}
void ComputerService::sortByBuildYear(vector<Computer>& computerList)
{
    sort(computerList.begin(), computerList.end(), sortByBuiltYearASC);
}
void ComputerService::sortByType(vector<Computer>& computerList)
{
    sort(computerList.begin(), computerList.end(), sortByTypeASC);
}
void ComputerService::sortWasBuilt(vector<Computer>& computerList)
{
    sort(computerList.begin(), computerList.end(), sortByWasBuiltASC);
}


//Þau föll sem er ekki búið að fara yfir fyrir (aðlaga) Viku2









void ComputerService::setCompleteList()
{
    //TODO
}


bool ComputerService::removeComputerFromList(const string id)
{
    // TODO
    return false;
}

//bool editComputerFromList(const string oldID, Computer computer);
// Viljum við útfæra þetta?



//Gets
vector<Computer> ComputerService::searchByName(const string searchString)
{
    // TODO
    vector <Computer> newComputerService;
    return newComputerService;
}


vector<Computer> ComputerService::searchByYear(const string searchString)
{
    // TODO
    vector <Computer> newComputerService;
    return newComputerService;
}

vector<Computer> ComputerService::searchByType(const string searchString)
{
    // TODO
    vector <Computer> newComputerService;
    return newComputerService;
}

//Sets
void ComputerService::removeNodeFromList(const int index)
{
    // TODO
}

//Gets
int ComputerService::getIndexOfValueByName(const string name)
{
    // TODO
    return 0;
}

bool ComputerService::validNumber(string number)
{
    // TODO
    return false;
}

bool ComputerService::checkIfStringSameIgnoreUpper(string orginalString, string searchFor)
{
    // TODO
    return false;
}

