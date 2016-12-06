#include "datalayer.h"
const char DELIMETER = ';';

//Filename is set in Header file if no name is given.
vector<CSPerson> DataLayer::readFromFile(string fileName)
{
    vector<CSPerson> vectPersons;
    ifstream myFile;

    string personName, gender, comment, yearBorn, yearPassedAway, sortChosen;
    try
    {
        myFile.open(fileName);
        while(getline(myFile, personName,DELIMETER))
        {
            getline(myFile, gender, DELIMETER);
            getline(myFile, yearBorn, DELIMETER);
            getline(myFile, yearPassedAway, DELIMETER);
            getline(myFile, comment, DELIMETER);

            //Erase newline infront of the string if there is one.
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
    ofstream myFile(fileName, std::ios_base::trunc); //discard the contents of the file before each write
    try
    {
        for(size_t i = 0; i < vectPersons.size(); i++)
        {
            myFile << vectPersons[i].getName() << DELIMETER;
            myFile << vectPersons[i].getGender() << DELIMETER;
            myFile << vectPersons[i].getBirthYear() << DELIMETER;
            myFile << vectPersons[i].getPassedAwayYear() << DELIMETER;
            myFile << vectPersons[i].getComments() << DELIMETER;
        }
        myFile.close();
    }
    catch(int e)
    {

    }
}
