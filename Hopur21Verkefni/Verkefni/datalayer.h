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

    vector<CSPerson> readFromFile(string fileName = "Computer_Scientist.txt");
};

#endif // DATALAYER_H
