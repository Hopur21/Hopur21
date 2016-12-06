#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include <vector>
#include "models/computer.h"
#include "repositories/datalayer.h"

class ComputerService
{
public:
    ComputerService();
    vector<Computer> getCompleteList(){return _fileKeeper;}

    //Sets
    void setCompleteList();
    bool addNewComputerToList(const string name,const int designyear, const int buildyear, const string type ,const bool created);
    bool removeComputerFromList(const string id);
    //bool editComputerFromList(const string oldID, Computer computer);
    void sortByName();
    void sortByNameDESC();
    void sortByDesignYear();
    void sortByBuildYear();
    void sortByCreatedYear();

    //Gets
    vector<Computer> searchByName(const string searchString);
    vector<Computer> searchByDesignYear(const string searchString);
    vector<Computer> searchByBuildYear(const string searchString);
    vector<Computer> searchByType(const string searchString);


private:
    vector<Computer> _fileKeeper;
    //DataLayer _data;

    //Sets
    void removeNodeFromList(const int index);

    //Gets
    int getIndexOfValueByName(const string name);
    bool validNumber(string number);
    bool checkIfStringSameIgnoreUpper(string orginalString, string searchFor);

    //Sorts
};

#endif // COMPUTERSERVICE_H
