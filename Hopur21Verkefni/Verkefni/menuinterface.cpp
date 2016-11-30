#include "menuinterface.h"
#include <iostream>
using namespace std;

const string DISPLAY_LIST = "1";
const string ADD_PERSON = "2";
const string SEARCH_PERSON = "3";
const string REMOVE_PERSON = "4";
const string EXIT = "5";

const string SEARCH_ALPHABET = "1";
const string SEARCH_BY_YEAR_OF_BIRTH = "2";
const string SEARCH_BY_YEAR_OF_DEATH = "3";

void MenuInterface::DisplayMenu()
{
    string choice;
    cout << endl;
    cout << "       ********************************************" << endl;
    cout << "       *  WELCOME TO THE COMPUTER SCIENTIST LIST  *" << endl;
    cout << "       ********************************************" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter 1 to: Display the complete list " << endl;
    cout << "Enter 2 to: Add a computer scientist to the list " << endl;
    cout << "Enter 3 to: Search the list for a computer scientist " << endl;
    cout << "Enter 4 to: Remove a computer scientist from the list" << endl;
    cout << "Enter 5 to: Exit the program " << endl;
    cin >> choice;


    if(choice == DISPLAY_LIST || choice == ADD_PERSON || choice == SEARCH_PERSON || choice ==REMOVE_PERSON)
    {
        processChoice(choice);
    }
    else
    {
        cout << endl;
        cout << "Your input was invalid, please try again." << endl;
        DisplayMenu();
    }
}

void MenuInterface::processChoice(const string choice)
{
    string choiceSub;
    // Here the input from the main menu is processed
    if(choice == DISPLAY_LIST)
    {
        cout << "Enter 1 to: Sort computer scientists by alphabetical order." << endl;
        cout << "Enter 2 to: Sort computer scientists by year of birth." << endl;
        cout << "Enter 3 to: Sort computer scientists by year of death." << endl;

        cin >> choiceSub;
        if(choiceSub == SEARCH_ALPHABET)
        {
            // call sort function
        }
        else if(choiceSub == SEARCH_BY_YEAR_OF_BIRTH)
        {
            // call sort function
        }
        else if(choiceSub == SEARCH_BY_YEAR_OF_DEATH)
        {
            // call sort ...
        }
        else
        {
            cout << "Your input was invalid, please try again." << endl;
            DisplayMenu();
        }
    }

    else if(choice == ADD_PERSON)
    {
        _uL.addPerson();
    }

    else if(choice == SEARCH_PERSON)
    {
        //search list for CS
    }

    else if(choice == REMOVE_PERSON)
    {
        return;
    }

}
