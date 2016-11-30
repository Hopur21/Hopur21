#include "userlayer.h"
#include <csperson.h>
#include <iostream>
using namespace std;

UserLayer::UserLayer()
{
    CSPersonService test;
}

void UserLayer::addPerson()
{
    string name, gender, comment;
    int birthYear,deathYear;
    cout << "Enter name: ";
    cin >> name;
    // TODO :IF PERSON EXISTS DISPLAY ERROR MESSAGE
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter the year of birth: ";
    cin >> birthYear;
    cout << "Enter the year of death: ";
    cin >> deathYear;
    cout << "Enter information about the person: ";
    cin >> comment;
    cout << endl;

    //CSPerson newPerson(name, gender, birthYear, deathYear, comment); TODO Lesa inn nýjan Person

    //lA.addToList(newPerson);

}

