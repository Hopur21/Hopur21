#ifndef DATALAYER_H
#define DATALAYER_H
#include<fstream>
#include<vector>
#include<string>
#include"csperson.h"

using namespace std;

class DataLayer
{
public:
    DataLayer();

    void writeToFile(const vector<CSPerson>& vectPersons, const string fileName = "Computer_Scientist.txt");
    vector<CSPerson> readFromFile(const string fileName = "Computer_Scientist.txt");
};

#endif // DATALAYER_H
