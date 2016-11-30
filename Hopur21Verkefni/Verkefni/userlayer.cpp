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

    // input and counter is for the gender
    string input = 0;
    int counter = 0;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Name: " << name << endl;
    // TODO :IF PERSON EXISTS DISPLAY ERROR MESSAGE


    const string male = "1";
    const string female = "2";
    const string other = "3";

    do
    {
        input = "";
        if(counter > 0)
        {
            cout << "Invalid input, try again." << endl;
        }

        cout << "Select gender: " << endl;

        cout << "Enter 1 for male" << endl;
        cout << "Enter 2 for female" << endl;
        cout << "Enter 3 for other" << endl;

        cin >> input;
        if(input == male)
        {
            gender = "male";
            break;
        }
        else if(input == female)
        {
            gender = "female";
            break;
        }
        else if(input == other)
        {
            gender = "other";
            break;
        }
        counter ++;

    }while(input != male || input != female || input != other);

    // counter is reset for next iteration.
    counter = 0;

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

