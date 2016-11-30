#include "userlayer.h"
#include <csperson.h>
#include <iostream>
using namespace std;

const string GENDER_MALE = "1";
const string GENDER_FEMALE = "2";
const string GENDER_OTHER = "3";

UserLayer::UserLayer()
{
    CSPersonService test;
}

void UserLayer::addPerson()
{

    string name, gender, comment;
    int birthYear,deathYear;

    // input and counter is for the gender
    string input;
    int error_counter = 0;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Name: " << name << endl;
    // TODO :IF PERSON EXISTS DISPLAY ERROR MESSAGE

    do
    {
        input = "";
        if(error_counter > 0)
        {
            cout << "Invalid input, try again." << endl;
        }

        cout << "Select gender: " << endl;

        cout << "Enter 1 for male" << endl;
        cout << "Enter 2 for female" << endl;
        cout << "Enter 3 for other" << endl;

        cin >> input;
        if(input == GENDER_MALE)
        {
            gender = "Male";
            break;
        }
        else if(input == GENDER_FEMALE)
        {
            gender = "Female";
            break;
        }
        else if(input == GENDER_OTHER)
        {
            gender = "Other";
            break;
        }
        error_counter ++;

    }while(input != GENDER_MALE || input != GENDER_FEMALE || input != GENDER_OTHER);

    // counter is reset for next iteration.
    error_counter = 0;

    cout << "Enter the year of birth: ";
    cin >> birthYear;
    cout << "Enter the year of death, 0 if this person is still alive: ";
    cin >> deathYear;
    cout << "Enter information about the person: ";
    cin >> comment;
    cout << endl;

    //CSPerson newPerson(name, gender, birthYear, deathYear, comment); TODO Lesa inn nýjan Person

    //lA.addToList(newPerson);

}

