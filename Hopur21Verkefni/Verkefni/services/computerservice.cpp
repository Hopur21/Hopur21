#include "computerservice.h"
#include <iostream> // má henda
using namespace std;    // má henda
ComputerService::ComputerService()
{

}

//Þau föll sem er ekki búið að fara yfir fyrir (aðlaga) Viku2

void ComputerService::setCompleteList()
{
    //TODO
}

bool ComputerService::addNewComputerToList(const string name,const int designyear, const int buildyear, const string type ,const bool created)
{
    cout << "HELLO FROM ADDNEWCOMPUTERTOLIST!";
    return false;
}
bool ComputerService::removeComputerFromList(const string id)
{
    // TODO
    return false;
}

//bool editComputerFromList(const string oldID, Computer computer);
// Viljum við útfæra þetta?

void ComputerService::sortByName()
{
    // TODO
}

void ComputerService::sortByNameDESC()
{
    // TODO
}

void ComputerService::sortByDesignYear()
{
    // TODO
}

void ComputerService::sortByBuildYear()
{
    // TODO
}

void ComputerService::sortByCreatedYear()
{
    // TODO
}

//Gets
vector<Computer> ComputerService::searchByName(const string searchString)
{
    // TODO
    vector <Computer> newComputerService;
    return newComputerService;
}

vector<Computer> ComputerService::searchByDesignYear(const string searchString)
{
    // TODO
    vector <Computer> newComputerService;
    return newComputerService;
}

vector<Computer> ComputerService::searchByBuildYear(const string searchString)
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

