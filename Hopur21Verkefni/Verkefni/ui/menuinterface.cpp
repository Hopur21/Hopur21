#include <iostream>
#include "menuinterface.h"

using namespace std;

MenuInterface::MenuInterface()
{
    _firstTimeBooting = 0;
}

void MenuInterface::invalidInput()
{
    cout << endl;
    cout << "Your input was invalid, please try again." << endl;
    cout << endl;
}

void MenuInterface::banner()
{
    //system("CLS");
    if(_firstTimeBooting == constants::FIRST_TIME)
    {
        cout << endl;
        cout << "       ********************************************" << endl;
        cout << "       *  WELCOME TO THE COMPUTER SCIENTIST LIST  *" << endl;
        cout << "       ********************************************" << endl;
        cout << endl;
        _firstTimeBooting = 1;//just something else than 0
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

        if(choice == constants::DISPLAY_LIST || choice == constants::ADD || choice == constants::SEARCH || choice == constants::REMOVE)
        {
            processChoice(choice);
        }
        else if(choice == "Q" || choice == "q")
        {
            char choice;
            cout << "Are you sure you want to quit the program?" << endl;
            cout << "Enter y for yes, and n for no: ";
            cin >> choice;
            if(choice != 'y' && choice != 'Y')
            {
                cout << endl;
                DisplayMenu();
            }
            else
            {
                cout << endl;
                return;
            }
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
        cout << "| 1 | A computer " << endl;
        cout << "| 2 | A scientist " << endl;

        cin >> subMenuChoice;

        if(subMenuChoice == constants::COMPUTER || subMenuChoice == constants::SCIENTIST)
        {
            return subMenuChoice;
        }
        else
        {
            cout << endl;
            invalidInput();
            cout << endl;
        }
    }while(subMenuChoice != constants::COMPUTER || subMenuChoice != constants::SCIENTIST);

    return subMenuChoice;
}

void MenuInterface::processChoice(const string choice)
{
    string subMenuChoice = subMenu();
    int choiceInt = stoi(choice);
    banner();

    // Computer operations
    if(subMenuChoice == constants::COMPUTER)
    {
        switch (choiceInt)
        {
        case 1:
            displayComputers();
            break;
        case 2:
            _uL.searchForAComputer();
            break;
        case 3:
            banner();
            _uL.addComputer();
        break;
        case 4:
            // Remove a computer
            break;
        default:
            invalidInput();
            break;
        }
    }

    // Scientist operations
    else if(subMenuChoice == constants::SCIENTIST)
    {
        switch (choiceInt)
        {
        case 1:
            displayScientists();
            break;
        case 2:
            _uL.searchForAPerson();
            break;
        case 3:
            _uL.addPerson();
        break;
        case 4:
            _uL.removePersonFromList();
            break;
        default:
            // This should never run
            invalidInput();
            break;
        }
    }
    else
    {
        // This should never run
        cout << "Something went wrong" << endl;
    }
}

void MenuInterface::displayComputers()
{
    string sortOption;
    _uL.printCompleteListOfComputers();

    cout << "| 1 | Sort computers by alphabetical order" << endl;
    cout << "| 2 | Sort computers by descending alphabetical order" << endl;
    cout << "| 3 | Sort by year of build" << endl;
    cout << "| 4 | Sort by year of design" << endl;
    cout << "| 5 | Sort by type of computer" << endl;
    cout << "| 6 | To view more info on a computer" << endl;
    cout << "| 0 | Go back" << endl;
    cout << "Enter your choice here: ";
    cin >> sortOption;
    cout << endl;

    if(sortOption == constants::SORT_ALPHABET)
    {
       // banner();

        _cS.sortByName();
    }
    else if(sortOption == constants::SORT_ASCENDING_ALPHABET)
    {
       // banner();
        _cS.sortByNameDESC();
    }
    else if(sortOption == constants::SORT_BY_BUILDYEAR)
    {
       // banner();
        _cS.sortByBuildYear();
    }
    else if(sortOption == constants::SORT_BY_DESIGNYEAR)
    {
       // banner();
        _cS.sortByDesignYear();
    }
    else if(sortOption == constants::SORT_BY_TYPE)
    {
       // banner();
        //_cS.sortByType();
    }
    else if(sortOption == constants::MORE_INFO)
    {
        _uL.printListMoreInfoComputer();
    }

    else if(sortOption == constants::GO_BACK)
    {
        banner();
    }
    else
    {
        banner();
        invalidInput();
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

    if(sortOption == constants::SORT_ALPHABET)
    {
        banner();
        _uL.sortListAlphabetically();
    }
    else if(sortOption == constants::SORT_BY_YEAR_OF_BIRTH)
    {
        banner();
        _uL.sortListByBirthYear();
    }
    else if(sortOption == constants::SORT_BY_YEAR_OF_DEATH)
    {
        banner();
        _uL.sortListByDeathYear();
    }
    else if(sortOption == constants::SORT_BY_AGE)
    {
        banner();
        _uL.sortListByAge();
    }
    else if(sortOption == constants::SORT_ASCENDING_ALPHABET)
    {
        banner();
        _uL.sortListAlphabeticallyASC();
    }
    else if(sortOption == constants::SORT_BY_ASCENDING_YEAR_OF_BIRTH)
    {
        banner();
        _uL.sortListByBirthYearASC();
    }
    else if(sortOption == constants::SORT_BY_GENDER)
    {
        banner();
        _uL.sortListByGender();
    }
    else if(sortOption == constants::GO_BACK)
    {
        banner();
    }
    else
    {
        banner();
        invalidInput();
    }
}
