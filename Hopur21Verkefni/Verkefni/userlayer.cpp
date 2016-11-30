#include "userlayer.h"
#include <csperson.h>
#include <iostream>
using namespace std;

const string GENDER_MALE = "1";
const string GENDER_FEMALE = "2";
const string GENDER_OTHER = "3";
const string DEAD = "0";
const char SPACE = ' ';


void invalidInput();

UserLayer::UserLayer()
{
    CSPersonService test;
}

void UserLayer::addPerson()
{

    string name, gender, comment;
    string birthYear,deathYear;

    // input and counter is for the gender input
    string input;
    int error_counter = 0;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    // TODO :IF PERSON EXISTS DISPLAY ERROR MESSAGE

    do
    {
        input = "";
        if(error_counter > 0)
        {
            cout << endl;
            invalidInput();
            cout << endl;
        }

        cout << "Select gender: " << endl;
        cout << endl;
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

    // Birth year validation
    birthYearValidation(birthYear);

    cout << "Enter the year of death, 0 if this person is still alive: ";
    cin >> deathYear;
    cout << "What is this person's greatest achievement: ";
    cin >> comment;
    cout << endl;
    cout << "This person has now been added to your list." << endl;
    cout << endl;

    //CSPerson newPerson(name, gender, birthYear, deathYear, comment); TODO Lesa inn nýjan Person

    //lA.addToList(newPerson);

}

bool UserLayer::checkNumberValidity(string userInput)
{
    // numberTest becomes zero if the user input is invalid.
    int numberTest = atoi(userInput.c_str());
    if(numberTest <= 0  || numberTest >= 3000)
    {
        return true;
    }

    return false;
}

void UserLayer::birthYearValidation(string birthYear)
{
    bool birthYearValidation = true;
    while(birthYearValidation)
    {
        cout << "Enter the year of birth: ";
        cin >> birthYear;
        if(checkNumberValidity(birthYear))
        {
            cout << endl;
            cout << "Invalid input, try again." << endl;
            cout << endl;
        }
        else
        {
            birthYearValidation = false;
        }
    }
}

void UserLayer::printList()
{
    vector<CSPerson> completeList = _CSPS.getCompleteList();

    int sizeOfList = completeList.size();

    if(sizeOfList == 0)
    {
        cout << "List is empty." << endl;
        return;
    }


    for(int i=0;i<sizeOfList;i++)
    {
        string name = completeList.at(i).getName();
        string gender = completeList.at(i).getGender();
        string stringBirthYear = to_string(completeList.at(i).getBirthYear());
        string stringPassedAway = to_string(completeList.at(i).getPassedAwayYear());
        string info = completeList.at(i).getComments() ;

        cout << endl;
        cout <<   "NAME                            GENDER    YEAR OF BIRTH    YEAR OF DEATH" << endl;
        cout <<   "------------------------------------------------------------------------"<< endl;
        cout << name.append(32 - name.length(), SPACE);
        cout << gender.append(10 - gender.length(), SPACE);
        cout << stringBirthYear.append(17 - stringBirthYear.length(), SPACE);

        if(stringPassedAway != DEAD)
        {
            cout << stringPassedAway.append(17- stringPassedAway.length(), SPACE);
        }
        else
        {
            string alive = "Alive";
            cout << alive.append(17 - alive.length(), SPACE);
        }
        cout << endl;
        cout << endl;
        cout << info << endl;
        cout <<   "------------------------------------------------------------------------"<< endl;
        cout << endl;
    }
}



