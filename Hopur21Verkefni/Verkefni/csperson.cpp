#include <iostream>
#include <string>
#include "csperson.h"

using namespace std;

void CSPerson::addPerson()
{
    CSPerson newPerson;
    cout << "Enter name: ";
    cin >> newPerson.name;
    cout << endl;
    cout << "Enter gender: ";
    cin >> newPerson.gender;
    cout << endl;
    cout << "Enter the year of birth: ";
    cin >> newPerson.birthYear;
    cout << endl;
    cout << "Enter the year of death: ";
    cin >> newPerson.deathYear;

}

void CSPerson::printPerson()
{
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Year of birth: " << birthYear << endl;
    cout << "Year of death: " << deathYear << endl;
}
