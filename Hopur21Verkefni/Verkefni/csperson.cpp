#include <iostream>
#include <string>
#include "csperson.h"

using namespace std;

CSPerson::CSPerson()
{

}

void CSPerson::addPerson()
{
    cout << "Enter name: ";
    cin >> name;
    cout << endl;
    cout << "Enter gender: ";
    cin >> gender;
    cout << endl;
    cout << "Enter the year of birth: ";
    cin >> birthYear;
    cout << endl;
    cout << "Enter the year of death: ";
    cin >> deathYear;

}

void CSPerson::printPerson()
{
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Year of birth: " << birthYear << endl;
    cout << "Year of death: " << deathYear << endl;
}
