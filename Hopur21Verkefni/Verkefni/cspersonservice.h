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
    //Sets
    void setCompleteList();
    void newPerson();//TODO

    //Gets
    vector<CSPerson> searchByName(const string searchString);
    vector<CSPerson> searchByYearOfBirth(const string searchString);
    vector<CSPerson> searchByYearOfDeath(const string searchString);

    //Sorts
    vector<CSPerson> sortAlphabetically(); // TODO


private:
    vector<CSPerson> _fileKeeper;
    DataLayer _data;

    //Sets
    void newPerson(string name, string gender, int birthYear, int deathYear, string comment);
    void removeNodeFromList(const int index);

    //Gets
    int getIndexOfValueByName(const string name);
    bool validNumber(string number);
    bool checkIfStringSameIgnoreUpper(string orginalString, string searchFor);
};

#endif // CSPERSONSERVICE_H
