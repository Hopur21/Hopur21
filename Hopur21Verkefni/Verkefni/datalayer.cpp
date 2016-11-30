#include "datalayer.h"

#include<iostream> //TODO Henda út

using namespace std;

DataLayer::DataLayer()
{
}

//Filename is set in Header file if no name is given.
vector<CSPerson> DataLayer::readFromFile(string fileName)
{
    vector<CSPerson> vectPersons;
    ifstream myFile;
    const char delimeter = ';';
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

            //Erease newline infront of the string if there is one.
            if(personName[0] == '\n')
            {
                personName.erase(0,1);
            }
            if(gender[0] == '\n')
            {
                gender.erase(0,1);
            }
            if(yearBorn[0] == '\n')
            {
                yearBorn.erase(0,1);
            }
            if(yearPassedAway[0] == '\n')
            {
                yearPassedAway.erase(0,1);
            }
            if(comment[0] == '\n')
            {
                comment.erase(0,1);
            }
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
//Filename is set in the header file if no name is given
void DataLayer::writeToFile(const vector<CSPerson>& vectPersons, const string fileName)
{
    const char delimeter = ';';
    ofstream myFile(fileName, std::ios_base::trunc); //discard the contents of the stream when opening
    try
    {
        for(size_t i = 0; i < vectPersons.size(); i++)
        {
            myFile << vectPersons[i].getName() << delimeter;
            myFile << vectPersons[i].getGender() << delimeter;
            myFile << vectPersons[i].getBirthYear() << delimeter;
            myFile << vectPersons[i].getPassedAwayYear() << delimeter;
            myFile << vectPersons[i].getComments() << delimeter;

        }

        myFile.close();
    }
    catch(int e)
    {

    }
}
