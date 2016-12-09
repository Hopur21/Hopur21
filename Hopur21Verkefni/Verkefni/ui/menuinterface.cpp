#include <iostream>
#include "menuinterface.h"

#ifdef _WIN32
    #include <windows.h>
#endif

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
    //if program is run on Windows then the banner is displayed in color
    #ifdef _WIN32
        //sets color of font to pink
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 13);

    //system("CLS");
    if(_firstTimeBooting == constants::FIRST_TIME)
    {
        cout << endl;
        cout << "       ********************************************" << endl;
        cout << "       *   WELCOME TO THE COMPUTER SCIENCE LIST   *" << endl;
        cout << "       ********************************************" << endl;
        cout << endl;

        SetConsoleTextAttribute(hConsole, 15); //set back to black background and white text
        _firstTimeBooting = 1; //just something else than 0
    }
    else
    {
        cout << endl;
        cout << "       ********************************************" << endl;
        cout << "       *           COMPUTER SCIENCE LIST          *" << endl;
        cout << "       ********************************************" << endl;
        cout << endl;

        SetConsoleTextAttribute(hConsole, 15); //set back to black background and white text
    }

    //if program is run on Apple the banner displays white as normal
    #else
    //system("CLS");
    if(_firstTimeBooting == constants::FIRST_TIME)
    {
        cout << endl;
        cout << "       ********************************************" << endl;
        cout << "       *   WELCOME TO THE COMPUTER SCIENCE LIST   *" << endl;
        cout << "       ********************************************" << endl;
        cout << endl;
        _firstTimeBooting = 1; //just something else than 0
    }
    else
    {
        cout << endl;
        cout << "       ********************************************" << endl;
        cout << "       *           COMPUTER SCIENCE LIST          *" << endl;
        cout << "       ********************************************" << endl;
        cout << endl;
    }
    #endif
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
        cout << "| 5 | View the computer trashcan" << endl;
        cout << "| 6 | View the scientist trashcan" << endl;
        cout << "| Q | Exit the program" << endl;
        cout << "Enter your choice here: ";
        cin >> choice;
        cout << endl;

        if(choice == constants::DISPLAY_LIST || choice == constants::ADD || choice == constants::SEARCH || choice == constants::REMOVE)
        {
            processChoice(choice);
        }
        else if(choice == constants::COMPUTER_TRASH)
        {
            _userLayer.viewComputerTrashCan();
        }
        else if(choice == constants::SCIENTIST_TRASH)
        {
            _userLayer.viewComputerScientistTrashCan();
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

void MenuInterface::processChoice(const string choice)
{

    string subMenuChoice = "";
    bool valid = false;

    while(valid == false)
    {
        cout << endl;
        cout << "Choose either:" << endl;
        cout << "| 1 | Computer " << endl;
        cout << "| 2 | Scientist " << endl;
        cout << "| 0 | Go back" << endl;
        cin >> subMenuChoice;

        if(subMenuChoice == constants::GO_BACK)
        {
            return;
        }
        if(subMenuChoice == constants::COMPUTER || subMenuChoice == constants::SCIENTIST)
        {
            valid = true;
        }
        else
        {
            invalidInput();
        }
    }

    int subMenuInt = stoi(subMenuChoice);
    int choiceInt = stoi(choice);
    banner();

    // Computer operations
    if(subMenuInt == constants::INT_COMPUTER)
    {
        switch (choiceInt)
        {
        case 1:
            displayComputers();
            break;
        case 2:
            _userLayer.searchForAComputer();
            break;
        case 3:
            // User gets a choice between:
            // 1. adding a computer
            // 2. adding a computer type
            _userLayer.computerChoice();
            break;
        case 4:
            _userLayer.removeComputerFromList();
            break;
        default:
            invalidInput();
            break;
        }
    }

    // Scientist operations
    else if(subMenuInt == constants::INT_SCIENTIST)
    {
        switch (choiceInt)
        {
        case 1:
            displayScientists();
            break;
        case 2:
            _userLayer.searchForAPerson();
            break;
        case 3:
            _userLayer.addPerson();
            break;
        case 4:
            _userLayer.removePersonFromList();
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
    _userLayer.printCompleteListOfComputers();

    cout << "| 1 | Sort computers by alphabetical order" << endl;
    cout << "| 2 | Sort computers by descending alphabetical order" << endl;
    cout << "| 3 | Sort by year of build" << endl;
    cout << "| 4 | Sort by year of design" << endl;
    cout << "| 5 | Sort by type of computer" << endl;
    cout << "| 6 | View more info on a computer" << endl;
    cout << "| 0 | Go back" << endl;
    cout << "Enter your choice here: ";
    cin >> sortOption;
    cout << endl;

    if(sortOption == constants::SORT_ALPHABET)
    {
        banner();
        _userLayer.sortComputerListAlphabetically();
    }
    else if(sortOption == constants::SORT_DESCENDING_ALPHABET)
    {
        banner();
        _userLayer.sortComputerListAlphabeticallyDESC();
    }
    else if(sortOption == constants::SORT_BY_BUILDYEAR)
    {
        banner();
        _userLayer.sortComputerListByBuildYear();
    }
    else if(sortOption == constants::SORT_BY_DESIGNYEAR)
    {
        banner();
        _userLayer.sortComputerListByDesignYear();
    }
    else if(sortOption == constants::SORT_BY_TYPE)
    {
       banner();
       _userLayer.sortComputerListByType();
    }
    else if(sortOption == constants::MORE_INFO)
    {
        _userLayer.printListMoreInfoComputer();
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
    _userLayer.printCompleteList();
    cout << "| 1 | Sort computer scientists by alphabetical order" << endl;
    cout << "| 2 | Sort computer scientists by descending alphabetical order" << endl;
    cout << "| 3 | Sort computer scientists by year of birth" << endl;
    cout << "| 4 | Sort computer scientists by ascending year of birth" << endl;
    cout << "| 5 | Sort computer scientists by year of death" << endl;
    cout << "| 6 | Sort computer scientists by age" << endl;
    cout << "| 7 | Sort computer scientists by gender" << endl;
    cout << "| 8 | Display the computers the scientist contributed to" << endl;
    cout << "| 0 | Go back" << endl;
    cout << "Enter your choice here: ";
    cin >> sortOption;
    cout << endl;

    if(sortOption == constants::SORT_ALPHABET)
    {
        banner();
        _userLayer.sortScientistListAlphabetically();
    }
    else if(sortOption == constants::SORT_BY_YEAR_OF_BIRTH)
    {
        banner();
        _userLayer.sortScientistListByBirthYear();
    }
    else if(sortOption == constants::SORT_BY_YEAR_OF_DEATH)
    {
        banner();
        _userLayer.sortScientistListByDeathYear();
    }
    else if(sortOption == constants::SORT_BY_AGE)
    {
        banner();
        _userLayer.sortScientistListByAge();
    }
    else if(sortOption == constants::SORT_DESCENDING_ALPHABET)
    {
        banner();
        _userLayer.sortScientistListAlphabeticallyDESC();
    }
    else if(sortOption == constants::SORT_BY_ASCENDING_YEAR_OF_BIRTH)
    {
        banner();
        _userLayer.sortScientistListByBirthYearASC();
    }
    else if(sortOption == constants::SORT_BY_GENDER)
    {
        banner();
        _userLayer.sortScientistListByGender();
    }
    else if(sortOption == constants::COMPUTERS_SCIENTIST_CONTRIBUTED_TO)
    {
        banner();
        _userLayer.displayListOfComputersScientistContributedTo();
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
