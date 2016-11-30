#ifndef CSPERSONSERVICE_H
#define CSPERSONSERVICE_H

#include "csperson.h"
#include "datalayer.h"

class CSPersonService
{
public:
    CSPersonService();
    vector<CSPerson> getCompleteList(){return _fileKeeper;};

    // TODO bæta við lesa inn skrá frá notenda
    void setCompleteList();

    void newPerson();

private:

    DataLayer _data;
    vector<CSPerson> _fileKeeper;
    void newPerson(string name, string gender, int birthYear, int deathYear, string comment);
};

#endif // CSPERSONSERVICE_H
