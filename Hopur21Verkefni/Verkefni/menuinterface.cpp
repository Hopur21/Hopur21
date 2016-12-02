#include "menuinterface.h"
#include <iostream>
using namespace std;

const string DISPLAY_LIST = "1";
const string ADD_PERSON = "2";
const string SEARCH_PERSON = "3";
const string REMOVE_PERSON = "4";
const string EXIT = "5";

const string SORT_ALPHABET = "1";
const string SORT_BY_YEAR_OF_BIRTH = "2";
const string SORT_BY_YEAR_OF_DEATH = "3";
const string SORT_BY_AGE = "4";
const string GO_BACK = "0";


void MenuInterface::invalidInput()
{
    cout << "Your input was invalid, please try again." << endl;
}

void MenuInterface::welcomeBanner()
{
    cout << endl;
    cout << "       ********************************************" << endl;
    cout << "       *  WELCOME TO THE COMPUTER SCIENTIST LIST  *" << endl;
    cout << "       ********************************************" << endl;
    cout << endl;
}

void MenuInterface::DisplayMenu()
{
    string choice;

    welcomeBanner();
    cout << endl;
    cout << "| 1 | Display the complete list" << endl;
    cout << "| 2 | Add a computer scientist to the list" << endl;
    cout << "| 3 | Search the list for a computer scientist" << endl;
    cout << "| 4 | Remove a computer scientist from the list" << endl;
    cout << "| 5 | Exit the program" << endl;
    cout << "Enter your choice here: ";
    cin >> choice;
    cout << endl;

    if(choice == DISPLAY_LIST || choice == ADD_PERSON || choice == SEARCH_PERSON || choice ==REMOVE_PERSON)
    {
        processChoice(choice);
    }
    else
    {
        invalidInput();
        DisplayMenu();
    }
}

void MenuInterface::processChoice(const string choice)
{
    string choiceSub;
    // Here the input from the main menu is processed
    if(choice == DISPLAY_LIST)
    {
        cout << "| 1 | Sort computer scientists by alphabetical order" << endl;
        cout << "| 2 | Sort computer scientists by year of birth" << endl;
        cout << "| 3 | Sort computer scientists by year of death" << endl;
        cout << "| 4 | Sort computer scientists by age" << endl;
        cout << "| 0 | Go back" << endl;
        cout << "Enter your choice here: ";
        cin >> choiceSub;
        cout << endl;

        if(choiceSub == SORT_ALPHABET)
        {
            _uL.sortListAlphabetically();
        }
        else if(choiceSub == SORT_BY_YEAR_OF_BIRTH)
        {
            _uL.sortListByBirthYear();
        }
        else if(choiceSub == SORT_BY_YEAR_OF_DEATH)
        {
            // call sort ...
            _uL.sortListByDeathYear();
        }
        else if(choiceSub == SORT_BY_AGE)
        {
            _uL.sortListByAge();
        }
        else if(choiceSub == GO_BACK)
        {
            DisplayMenu();
        }
        else
        {
            invalidInput();
            DisplayMenu();
        }
    }

    else if(choice == ADD_PERSON)
    {
        _uL.addPerson();
    }

    else if(choice == SEARCH_PERSON)
    {
        _uL.searchForAPerson();
    }

    else if(choice == REMOVE_PERSON)
    {
        return;
    }
}
