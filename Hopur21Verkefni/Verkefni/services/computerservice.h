#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include <vector>
#include <algorithm>//Used for sort
#include "models/computer.h"

class ComputerService
{
public:
    ComputerService();
    //Gets
    vector<Computer> searchByName(const string searchString);
    vector<Computer> searchByYear(const string searchString);
    vector<Computer> searchByType(const string searchString);
    //Sorts
    void sortByName(vector<Computer>& computerList);
    void sortByNameDESC(vector<Computer>& computerList);
    void sortByDesignYear(vector<Computer>& computerList);
    void sortByBuildYear(vector<Computer>& computerList);
    void sortByType(vector<Computer>& computerList);
    void sortWasBuilt(vector<Computer>& computerList);
private:

};

#endif // COMPUTERSERVICE_H
