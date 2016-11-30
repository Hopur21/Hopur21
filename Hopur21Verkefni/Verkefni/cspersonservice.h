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
    void setCompleteList();

    void newPerson();//TODO

private:
    vector<CSPerson> _fileKeeper;
    DataLayer _data;

    //Sets
    void newPerson(string name, string gender, int birthYear, int deathYear, string comment);
    void removeNodeFromList(const int index);

    //Gets
    int getIndexOfValueByName(const string name);
};

#endif // CSPERSONSERVICE_H
