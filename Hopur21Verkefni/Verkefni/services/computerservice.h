#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include <vector>
#include <algorithm>//Used for sort
#include "models/computer.h"

class ComputerService
{
public:
    ComputerService();

    //Sets
    void setCompleteList();
    bool addNewComputerToList(Computer& newComputer, const string name,const int designyear, const int buildyear, const string type ,const bool created);
    bool removeComputerFromList(const string id);

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
    //Sets
    void removeNodeFromList(const int index);

    //Gets
    int getIndexOfValueByName(const string name);
    bool validNumber(string number);
    bool checkIfStringSameIgnoreUpper(string orginalString, string searchFor);

    //Sorts
};

#endif // COMPUTERSERVICE_H
