#include "userlayer.h"
#include <csperson.h>
#include <iostream>
using namespace std;

UserLayer::UserLayer()
{

}

void UserLayer::addPerson()
{
    string name, gender, comment;
    int birthYear,deathYear;
    cout << "Enter name: ";
    cin >> name;
    // TODO :IF PERSON EXISTS DISPLAY ERROR MESSAGE
    cout << endl;
    cout << "Enter gender: ";
    cin >> gender;
    cout << endl;
    cout << "Enter the year of birth: ";
    cin >> birthYear;
    cout << endl;
    cout << "Enter the year of death: ";
    cin >> deathYear;
    cout << "Enter information about the person: ";
    cin >> comment;

    //CSPerson newPerson(name, gender, birthYear, deathYear, comment); TODO Lesa inn nýjan Person

    //lA.addToList(newPerson);
}

