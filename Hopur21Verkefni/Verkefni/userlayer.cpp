#include "userlayer.h"
#include <csperson.h>
#include <iostream>
using namespace std;

const string SEARCH_BY_NAME = "1";
const string SEARCH_BY_YEAR_OF_BIRTH = "2";
const string SEARCH_BY_YEAR_OF_DEATH = "3";

const string GENDER_MALE = "1";
const string GENDER_FEMALE = "2";
const string GENDER_OTHER = "3";
const string ALIVE = "0";
const char SPACE = ' ';

void invalidInput(); //Gefur villuskilaboð ef notandi slær inn tölu sem er ekki valmöguleiki

UserLayer::UserLayer()
{
    CSPersonService test;
}

void UserLayer::addPerson()
{
    string name, gender, comment, birthYear,deathYear, input;
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

        printGenderMenu();

        cin >> input;
        if(input == GENDER_MALE)
        {
            gender = "Male";
            break; //Þarf þessi breaks?
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
        error_counter++;
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

void UserLayer::printGenderMenu()
{
    cout << "Select gender: " << endl << endl;
    cout << "| 1 | Male" << endl;
    cout << "| 2 | Female" << endl;
    cout << "| 3 | Other" << endl;
    cout << "Enter your choice here: ";
}

bool UserLayer::checkNumberValidity(string userInput)
{
    // numberTest becomes zero if the user input is invalid.
    int numberTest = 0;
    try
    {
        numberTest = atoi(userInput.c_str());
    }
    catch(int e)
    {
        return false;
    }
    if(numberTest <= 0  || numberTest >= 3000)//Vantar komment
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
            invalidInput();
        }
        else
        {
            birthYearValidation = false;
        }
    }
}

void UserLayer::printList(vector<CSPerson> list)
{
    int sizeOfList = list.size();

    if(sizeOfList == 0)
    {
        cout << "List is empty." << endl;
        return; //á að hætta í forritinu hér?
    }

    for(int i=0;i<sizeOfList;i++)
    {
        string name = list.at(i).getName();
        string gender = list.at(i).getGender();
        string stringBirthYear = to_string(list.at(i).getBirthYear());
        string stringPassedAway = to_string(list.at(i).getPassedAwayYear());
        string info = list.at(i).getComments() ;

        cout << endl;
        cout <<   "NAME                            GENDER    YEAR OF BIRTH    YEAR OF DEATH" << endl;
        cout <<   "------------------------------------------------------------------------"<< endl;
        cout << endl;
        cout << name.append(32 - name.length(), SPACE);
        cout << gender.append(10 - gender.length(), SPACE);
        cout << stringBirthYear.append(17 - stringBirthYear.length(), SPACE);

        if(stringPassedAway != ALIVE)
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
        cout << endl;
        cout <<   "------------------------------------------------------------------------"<< endl;
        cout << endl;
    }
}

void UserLayer::sortListAlphabetically()
{
    //vector <CSPerson> sortedList = _CSPServ.sortAlphabetically();
    //SORT
    //printList();
}

void UserLayer::searchForAPerson()
{
    string userInput, searchString;

    do
    {
        cout << "| 1 | Search by name" << endl;
        cout << "| 2 | Search by year of year of birth" << endl;
        cout << "| 3 | Search by year of year of death" << endl;
        cout << "Enter your choice here: ";
        //viljum við hafa Go Back option hérna til að hætta við leit?

        cin >> userInput;
        if(userInput == SEARCH_BY_NAME || userInput == SEARCH_BY_YEAR_OF_BIRTH || userInput == SEARCH_BY_YEAR_OF_DEATH)
        {
            break;
        }
        invalidInput();

    }while(userInput != SEARCH_BY_NAME || userInput != SEARCH_BY_YEAR_OF_BIRTH || userInput != SEARCH_BY_YEAR_OF_DEATH);

    cout << "Enter the search string : "; //þetta er sjúklega tölvunarfræðileg setning, ekki viss um að fólk almennt viti hvað search string er??
    cin.ignore();
    getline(cin, searchString);

    cout << "SEARCHSTRING " << searchString;

    if(userInput == SEARCH_BY_NAME)
    {
        printList(_CSPServ.searchByName(searchString));
    }
    else if(userInput == SEARCH_BY_YEAR_OF_BIRTH)
    {
        printList(_CSPServ.searchByYearOfBirth(searchString));
    }
    else if(userInput == SEARCH_BY_YEAR_OF_DEATH)
    {
        printList(_CSPServ.searchByYearOfDeath(searchString));
    }
}
