#include "listaccess.h"
#include <iostream>
using namespace std;

void ListAccess::addToList(CSPerson person)
{
    listOfCSPersons.push_back(person);
}

vector<CSPerson> ListAccess::readFromFile()
{
    // TODO implement.
}

void ListAccess::writeToFile();
{

}
