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

