#include <csperson.h>
#include <iostream>
#include <string>


using namespace std;

CSPerson::CSPerson(){};

CSPerson::CSPerson(string name, string gender, int birthYear, int deathYear, string comment)
{
   _name = name;
   _gender = gender;
   _birthYear = birthYear;
   _deathYear = deathYear;
   _comment = comment;
}

void CSPerson::addPerson()
{
    CSPerson newPerson;
    cout << "Enter name: ";
    cin >> newPerson._name;
    // TODO :IF PERSON EXISTS DISPLAY ERROR MESSAGE
    cout << endl;
    cout << "Enter gender: ";
    cin >> newPerson._gender;
    cout << endl;
    cout << "Enter the year of birth: ";
    cin >> newPerson._birthYear;
    cout << endl;
    cout << "Enter the year of death: ";
    cin >> newPerson._deathYear;

   // lA.addToList(newPerson);

}

void CSPerson::printPerson()
{
    cout << "Name:          " << _name       << endl;
    cout << "Gender:        " << _gender     << endl;
    cout << "Year of birth: " << _birthYear  << endl;
    cout << "Year of death: " << _deathYear  << endl;
}
