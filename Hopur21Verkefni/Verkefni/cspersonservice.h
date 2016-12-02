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
    // TODO Gera edit á user

    //Sets
    void setCompleteList();
    bool addNewPersonToList(const string name,const string gender, const string birthYear, const string deathYear,const string comment);
    bool removePersonFromList(const string id);
    void sortByName();// TODO: Raða eftir miðnafni
    void sortByNameASC();
    void sortByGender();
    void sortByGenderASC();
    void sortByDeathYear();
    void sortByDeathYearASC();
    void sortByBirthYear();
    void sortByBirthYearASC();
    void sortByAge();
    void sortByAgeASC();

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
