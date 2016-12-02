#include "menuinterface.h"
#include <iostream>
using namespace std;

const string DISPLAY_LIST = "1";
const string SEARCH_PERSON = "2";
const string ADD_PERSON = "3";
const string REMOVE_PERSON = "4";


const string SORT_ALPHABET = "1";
const string SORT_BY_YEAR_OF_BIRTH = "2";
const string SORT_BY_YEAR_OF_DEATH = "3";
const string SORT_BY_AGE = "4";
const string GO_BACK = "0";

const int FIRST_TIME = 0;


void MenuInterface::invalidInput()
{
    cout << "Your input was invalid, please try again." << endl;
}

void MenuInterface::banner()
{
    system("CLS");
    if(firstTimeBooting == FIRST_TIME)
    {
        cout << endl;
        cout << "       ********************************************" << endl;
        cout << "       *  WELCOME TO THE COMPUTER SCIENTIST LIST  *" << endl;
        cout << "       ********************************************" << endl;
        cout << endl;
        firstTimeBooting = 1;//just something else than 0
    }
    else
    {
        cout << endl;
        cout << "       ********************************************" << endl;
        cout << "       *          COMPUTER SCIENTIST LIST         *" << endl;
        cout << "       ********************************************" << endl;
        cout << endl;
    }

}

void MenuInterface::DisplayMenu()
{
    string choice;
    cout << endl;
    cout << "| 1 | Display the complete list" << endl;
    cout << "| 2 | Search the list for a computer scientist" << endl;
    cout << "| 3 | Add a computer scientist to the list" << endl;
    cout << "| 4 | Remove a computer scientist from the list" << endl;
    cout << "| Q | Exit the program" << endl;
    cout << "Enter your choice here: ";
    cin >> choice;
    cout << endl;

    if(choice == DISPLAY_LIST || choice == ADD_PERSON || choice == SEARCH_PERSON || choice ==REMOVE_PERSON)
    {
        processChoice(choice);
    }
    else if(choice == "Q" || choice == "q")
    {
        return;
    }
    else
    {
        invalidInput();
        banner();
        DisplayMenu();
    }
}

void MenuInterface::processChoice(const string choice)
{
    banner();
    string choiceSub;
    // Here the input from the main menu is processed
    if(choice == DISPLAY_LIST)
    {
        _uL.printCompleteList();
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
            banner();
            _uL.sortListAlphabetically();
            DisplayMenu();
        }
        else if(choiceSub == SORT_BY_YEAR_OF_BIRTH)
        {
            banner();
            _uL.sortListByBirthYear();
            DisplayMenu();
        }
        else if(choiceSub == SORT_BY_YEAR_OF_DEATH)
        {
            banner();
            _uL.sortListByDeathYear();
            DisplayMenu();
        }
        else if(choiceSub == SORT_BY_AGE)
        {
            banner();
            _uL.sortListByAge();
            DisplayMenu();
        }
        else if(choiceSub == GO_BACK)
        {
            banner();
            DisplayMenu();
        }
        else
        {
            banner();
            invalidInput();
            DisplayMenu();
        }
    }

    else if(choice == ADD_PERSON)
    {
        banner();
        _uL.addPerson();
        DisplayMenu();
    }

    else if(choice == SEARCH_PERSON)
    {
        banner();
        _uL.searchForAPerson();
        DisplayMenu();
    }

    else if(choice == REMOVE_PERSON)
    {
        banner();
        _uL.removePersonFromList();
        DisplayMenu();
    }
}
