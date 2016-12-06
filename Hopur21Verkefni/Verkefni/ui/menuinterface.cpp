#include "menuinterface.h"
#include <iostream>
using namespace std;

const string DISPLAY_LIST = "1";
const string ADD = "3";
const string SEARCH = "2";
const string REMOVE = "4";

const string SORT_ALPHABET = "1";
const string SORT_ASCENDING_ALPHABET = "2";
const string SORT_BY_YEAR_OF_BIRTH = "3";
const string SORT_BY_ASCENDING_YEAR_OF_BIRTH = "4";
const string SORT_BY_YEAR_OF_DEATH = "5";
const string SORT_BY_AGE = "6";
const string SORT_BY_GENDER = "7";
const string GO_BACK = "0";

const int FIRST_TIME = 0;

const string COMPUTER = "1";
const string SCIENTIST = "2";


void MenuInterface::invalidInput()
{
    cout << endl;
    cout << "Your input was invalid, please try again." << endl;
    cout << endl;
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

    while(choice != "Q" || choice != "q")
    {


        cout << "| 1 | Display either a computer or a scientist" << endl;
        cout << "| 2 | Search the list" << endl;
        cout << "| 3 | Add to the list" << endl;
        cout << "| 4 | Remove from the list" << endl;
        cout << "| Q | Exit the program" << endl;
        cout << "Enter your choice here: ";
        cin >> choice;
        cout << endl;

        if(choice == DISPLAY_LIST || choice == ADD || choice == SEARCH || choice == REMOVE)
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
}

string MenuInterface::subMenu()
{
    string subMenuChoice;
    do
    {
        cout << endl;
        cout << "Choose either:" << endl;
        cout << "1) A computer " << endl;
        cout << "2) A scientist " << endl;

        cin >> subMenuChoice;

        if(subMenuChoice == COMPUTER || subMenuChoice == SCIENTIST)
        {
            return subMenuChoice;
        }
        else
        {
            cout << endl;
            invalidInput();
            cout << endl;
        }
    }while(subMenuChoice != COMPUTER || subMenuChoice != SCIENTIST);

    return subMenuChoice;
}

void MenuInterface::processChoice(const string choice)
{
    string subMenuChoice = subMenu();
    int choiceInt = stoi(choice);
    banner();

    // Computer operations
    if(subMenuChoice == COMPUTER)
    {
        switch (choiceInt)
        {
        case 1:
            //Display computer
            break;
        case 2:
            // Search for a computer"
            break;
        case 3:
            // Add a computer
        break;
        case 4:
            // Remove a computer
            break;
        default:
            // This should never run
            invalidInput();
            break;
        }
    }

    // Scientist operations
    else if(subMenuChoice == SCIENTIST)
    {
        switch (choiceInt)
        {
        case 1:
            banner();
            displayScientists();
            break;
        case 2:
            banner();
            _uL.searchForAPerson();
            break;
        case 3:
            banner();
            _uL.addPerson();
        break;
        case 4:
            banner();
            _uL.removePersonFromList();
            break;
        default:
            // This should never run
            invalidInput();
            break;
        }
    }
}

void MenuInterface::displayScientists()
{
    string sortOption;
    _uL.printCompleteList();
    cout << "| 1 | Sort computer scientists by alphabetical order" << endl;
    cout << "| 2 | Sort computer scientists by ascending alphabetical order" << endl;
    cout << "| 3 | Sort computer scientists by year of birth" << endl;
    cout << "| 4 | Sort computer scientists by ascending year of birth" << endl;
    cout << "| 5 | Sort computer scientists by year of death" << endl;
    cout << "| 6 | Sort computer scientists by age" << endl;
    cout << "| 7 | Sort computer scientists by gender" << endl;
    cout << "| 0 | Go back" << endl;
    cout << "Enter your choice here: ";
    cin >> sortOption;
    cout << endl;

    if(sortOption == SORT_ALPHABET)
    {
        banner();
        _uL.sortListAlphabetically();
    }
    else if(sortOption == SORT_BY_YEAR_OF_BIRTH)
    {
        banner();
        _uL.sortListByBirthYear();
    }
    else if(sortOption == SORT_BY_YEAR_OF_DEATH)
    {
        banner();
        _uL.sortListByDeathYear();
    }
    else if(sortOption == SORT_BY_AGE)
    {
        banner();
        _uL.sortListByAge();
    }
    else if(sortOption == SORT_ASCENDING_ALPHABET)
    {
        banner();
        _uL.sortListAlphabeticallyASC();
    }
    else if(sortOption == SORT_BY_ASCENDING_YEAR_OF_BIRTH)
    {
        banner();
        _uL.sortListByBirthYearASC();
    }
    else if(sortOption == SORT_BY_GENDER)
    {
        banner();
        _uL.sortListByGender();
    }
    else if(sortOption == GO_BACK)
    {
        banner();
    }
    else
    {
        banner();
        invalidInput();
    }
}


