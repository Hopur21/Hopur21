#ifndef CSPERSONSERVICE_H
#define CSPERSONSERVICE_H
#include <algorithm>
#include "csperson.h"
#include "datalayer.h"

class CSPersonService
{
public:
    CSPersonService();
    vector<CSPerson> getCompleteList(){return _fileKeeper;}

    // TODO bæta við lesa inn skrá frá notenda
    // TODO Gera edit á user

    //Sets
    void setCompleteList();
    void newPerson();//TODO

    //Gets
    vector<CSPerson> searchByName(const string searchString);
    vector<CSPerson> searchByYearOfBirth(const string searchString);
    vector<CSPerson> searchByYearOfDeath(const string searchString);

    //Sorts
    vector<CSPerson> sortAlphabetically(); // TODO: Raða eftir miðnafni


private:
    vector<CSPerson> _fileKeeper;
    DataLayer _data;

    //Sets
    void addNewPersonToList(const string name,const string gender, int birthYear, int deathYear,const string comment);
    void removeNodeFromList(const int index);

    //Gets
    int getIndexOfValueByName(const string name);
    bool validNumber(string number);
    bool checkIfStringSameIgnoreUpper(string orginalString, string searchFor);
};

#endif // CSPERSONSERVICE_H
