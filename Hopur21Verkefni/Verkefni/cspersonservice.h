#ifndef CSPERSONSERVICE_H
#define CSPERSONSERVICE_H
#include <algorithm>
#include "csperson.h"
#include "datalayer.h"
#include <iostream>
#include<string>
using namespace std;

class CSPersonService
{
public:
    CSPersonService();
    vector<CSPerson> getCompleteList(){return _fileKeeper;}

    // TODO bæta við lesa inn skrá frá notenda

    //Sets
    void setCompleteList();
    bool addNewPersonToList(const string name,const string gender, const string birthYear, const string deathYear,const string comment);
    bool removePersonFromList(const string id);
    bool editPersonFromList(const string oldID, CSPerson person);
    void sortByName();
    void sortByNameASC();
    void sortByGender();
    void sortByDeathYear();
    void sortByBirthYear();
    void sortByBirthYearASC();
    void sortByAge();

    //Gets
    vector<CSPerson> searchByName(const string searchString);
    vector<CSPerson> searchByYearOfBirth(const string searchString);
    vector<CSPerson> searchByYearOfDeath(const string searchString);

private:
    vector<CSPerson> _fileKeeper;
    DataLayer _data;

    //Sets
    void removeNodeFromList(const int index);

    //Gets
    int getIndexOfValueByName(const string name);
    bool validNumber(string number);
    bool checkIfStringSameIgnoreUpper(string orginalString, string searchFor);

    //Sorts

};

#endif // CSPERSONSERVICE_H
