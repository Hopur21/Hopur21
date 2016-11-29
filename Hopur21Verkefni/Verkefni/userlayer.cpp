#include "userlayer.h"

UserLayer::UserLayer()
{

}

void UserLayer::addPerson()
{
    CSPerson person;
    cout << "Enter name: ";
    cin >> person.name;
    // TODO :IF PERSON EXISTS DISPLAY ERROR MESSAGE
    cout << endl;
    cout << "Enter gender: ";
    cin >> person.gender;
    cout << endl;
    cout << "Enter the year of birth: ";
    cin >> person.birthYear;
    cout << endl;
    cout << "Enter the year of death: ";
    cin >> person.deathYear;

    //lA.addToList(newPerson);

}

void UserLayer::printPerson()
{
    cout << "Name:          " << name << endl;
    cout << "Gender:        " << gender << endl;
    cout << "Year of birth: " << birthYear << endl;
    cout << "Year of death: " << deathYear << endl;
}
