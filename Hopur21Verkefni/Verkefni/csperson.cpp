#include <csperson.h>
#include <iostream>
#include <string>


using namespace std;

CSPerson::CSPerson(){};

void CSPerson::addPerson()
{
    CSPerson newPerson;
    cout << "Enter name: ";
    cin >> newPerson.name;
    // TODO :IF PERSON EXISTS DISPLAY ERROR MESSAGE
    cout << endl;
    cout << "Enter gender: ";
    cin >> newPerson.gender;
    cout << endl;
    cout << "Enter the year of birth: ";
    cin >> newPerson.birthYear;
    cout << endl;
    cout << "Enter the year of death: ";
    cin >> newPerson.deathYear;

   // lA.addToList(newPerson);

}

void CSPerson::printPerson()
{
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Year of birth: " << birthYear << endl;
    cout << "Year of death: " << deathYear << endl;
}
