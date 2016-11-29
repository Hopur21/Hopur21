#include "datalayer.h"

#include<iostream> //TODO Henda út

using namespace std;

DataLayer::DataLayer()
{
    /*
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a fi33.\n";
    myfile.close();
    */

    vector<CSPerson> test = readFromFile();

}

//Filename is set in Header file if no name is given.
vector<CSPerson> DataLayer::readFromFile(string fileName)
{
    vector<CSPerson> vectPersons;
    ifstream myFile;
    char delimeter = ';';
    string personName, gender, comment, yearBorn, yearPassedAway;
    try
    {
        myFile.open(fileName);
        while(getline(myFile, personName,delimeter))
        {
            getline(myFile, gender, delimeter);
            getline(myFile, yearBorn, delimeter);
            getline(myFile, yearPassedAway, delimeter);
            getline(myFile, comment, delimeter);
            vectPersons.push_back(CSPerson(personName, gender, stoi(yearBorn), stoi(yearPassedAway), comment));
        }
        myFile.close();
        return vectPersons;
    }
    catch(int e)
    {
        return vectPersons;
    }
}
