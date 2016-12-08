#include <iostream>
#include "userlayer.h"
//
#include <iterator>
#include <sstream>
//


using namespace std;

void UserLayer::addPerson()
{
    string gender, comment, birthYear,deathYear, input;
    string name = "";
    char userInput;
    int error_counter = 0;
    bool validity = false;
    // A list of all computers the scientist might have had something to do with
    vector<Computer> list = _service.getComputerList();

    // If user inputs no input an error message occurs
    do
    {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        if(name == constants::EMPTY_STRING)
        {
            invalidInput();
        }
    }while(name == constants::EMPTY_STRING);

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
        if(input == constants::GENDER_MALE)
        {
            gender = "Male";
            break;
        }
        else if(input == constants::GENDER_FEMALE)
        {
            gender = "Female";
            break;
        }
        else if(input == constants::GENDER_OTHER)
        {
            gender = "Other";
            break;
        }
        error_counter++;
    }while(input != constants::GENDER_MALE || input != constants::GENDER_FEMALE || input != constants::GENDER_OTHER);

    // Birth year validation
    cout << "Enter the year of birth: ";
    cin >> birthYear;
    birthYear = birthYearValidation(birthYear);
    cout << "Enter the year this person died, (0 if this person is still alive): ";
    cin >> deathYear;

    // No need to validate if person is still alive.
    if(deathYear != constants::ALIVE)
    {
        deathYear = deathYearValidation(birthYear, deathYear);
    }
    cout << "What is this person's greatest achievement: ";
    cin.ignore();
    getline(cin, comment);
    cout << endl;

    error_counter = 0;
    do
    {
        if(error_counter == 0)
        {
            cout << "Did this person contribute to designing or creating a computer?" << endl;
            cout << "Enter y for yes, n for no." << endl;
        }
        else
        {
            invalidInput();
            cout << "Enter y for yes, n for no." << endl;
        }
        cin >> userInput;

        switch(userInput)
        {
            case 'y':
            case 'Y':
                userInput = 'y';
                validity = true;
                break;
            case 'n':
            case 'N':
                validity = true;
                break;
            default:
                invalidInput();
                break;
        }

    }while(validity != true);

    // Prints the options of computers the user can associate with a scientist
    if(userInput == 'y')
    {
        /*if(list.size() == 0)
        {
            cout << "List of computers is empty." << endl;
        }
        else
        {*/
            for(unsigned int i=0; i<list.size(); i++)
            {
                  cout << i << "  " << list.at(i).getName() << endl;
            }


            vector<int> vectorOfInts;
            validity = false;
            int sizeOfList = list.size();

            do
            {
                cout << "Enter one or more numbers with spaces between them: " << endl;

                //while()



            }while(validity == false);

            //}
        //}
    }


    if(_service.addNewPersonToList(name, gender, birthYear, deathYear, comment))
    {
        cout << "The person has been added successfully." << endl;
        cout << endl;

    }
    else
    {
        cout << "Something went wrong." << endl;
    }

}

void UserLayer::addComputer()
{
    string name, type;
    string designYear, buildYear;
    int intDesignYear, intBuildYear;
    bool created = false;
    bool validity = false;
    char yesOrNo;

    cout << "What is the name of the computer: ";
    do
    {
        cin.ignore();
        getline(cin, name);
        if(name == "")
        {
            invalidInput();
        }
    }while(name == "");

    do
    {
        cout << "When was the computer designed? Enter a year: ";
        cin >> designYear;

        if(!checkNumberValidity(designYear))
        {
            intDesignYear = stoi(designYear);
            validity = true;
            break;
        }
        else
        {
            invalidInput();
        }
    }while(validity != true);

    cout << "What is the computer type: ";
    cin.ignore();
    getline(cin, designYear);

    cout << "What is the computer type: ";
    // TODO DISPLAY A LIST OF POSSIBLE TYPES!!!
    type = "mammathin";
    cout << endl;

    validity = false;

    do
    {
        cout << "Was this computer created?" << endl;
        cout << "Enter y for yes, n for no." << endl;
        cin >> yesOrNo;

        switch(yesOrNo)
        {
            case 'y':
            case 'Y':
                created = true;
                validity = true;
                break;
            case 'n':
            case 'N':
                created = false;
                validity = true;
                break;
            default:
                invalidInput();
                break;
        }

    }while(validity != true);

    if(created == true)
    {

        validity = false;
        do
        {
            cout << "When was the computer created? Enter a year: ";
            cin >> buildYear;

            if(!checkNumberValidity(buildYear))
            {
                intBuildYear = stoi(buildYear);
                validity = true;
            }
            else
            {
                invalidInput();
            }
        }while(validity != true);
    }
    else
    {
        intBuildYear = 0;
    }


    if(!(_service.addNewComputerToList(name, intDesignYear, intBuildYear, type, created)))
    {
        cout << "Computer added successfully." << endl;
        cout << endl;
    }
    else
    {
        cout << "Something went wrong." << endl;
    }
}

void UserLayer::removePersonFromList()
{
    printCompleteList();
    string personToRemove;
    cout << "Enter the number of the person that is to be removed or 0 to go back: ";
    cin >> personToRemove;
    if(personToRemove == constants::GO_BACK)
    {
        return;
    }
    _service.removePersonFromList(personToRemove);
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
    if(numberTest <= 0  || numberTest >= 3000)//If number is beetween 1 - 2999
    {
        return true;
    }

    return false;
}

string UserLayer::birthYearValidation(string birthYear)
{
    bool birthYearValidation = true;
    int error_counter = 0;
    while(birthYearValidation)
    {
        if(error_counter > 0)
        {
            cout << "Enter the year of birth: ";
            cin >> birthYear;
        }
        if(checkNumberValidity(birthYear))
        {
            invalidInput();
        }
        else
        {
            birthYearValidation = false;
            return birthYear;
        }
        error_counter++;
    }
    return "ERROR";
}

string UserLayer::deathYearValidation(string birthYear, string deathYear)
{
    bool deathYearValidation = true;
    int error_counter = 0;
    while(deathYearValidation)
    {
        if(error_counter > 0)
        {
            cout << "Enter the year of death: ";
            cin >> deathYear;
        }
        if(checkNumberValidity(deathYear) || birthYear >= deathYear)
        {
            invalidInput();
        }

        else
        {
            deathYearValidation = false;
            return deathYear;
        }
        error_counter++;
    }
    return "ERROR";
}

void UserLayer::printListOfComputers(vector<Computer> list)
{
    // TODO gera svipað og fyrir neðan   :D
}

void UserLayer::printListOfScientists(vector<CSPerson> list)
{
    int sizeOfList = list.size();
    if(sizeOfList == 0)
    {
        cout << "List is empty." << endl;
        cout << endl;
        return;
    }

    cout <<   "#     NAME                            GENDER     YOB     YOD      AGE" << endl;
    cout <<   "------------------------------------------------------------------------------"<< endl;
    for(int i=0;i<sizeOfList;i++)
    {
        string name = list.at(i).getName();
        string gender = list.at(i).getGender();
        string stringBirthYear = to_string(list.at(i).getBirthYear());
        string stringPassedAway = to_string(list.at(i).getPassedAwayYear());
        int age = list.at(i).getAge();


        // adjustForSpaces adjusts the spaces between the
        // number and name of the scientist according to the size of the value i in the for loop
        adjustForSpaces(i);

        cout << name.append(32 - name.length(), constants::SPACE);
        cout << gender.append(11 - gender.length(), constants::SPACE);
        cout << stringBirthYear.append(8 - stringBirthYear.length(), constants::SPACE);

        if(stringPassedAway != constants::ALIVE)
        {
            cout << stringPassedAway.append(9 - stringPassedAway.length(), constants::SPACE);
            cout << age;
        }
        else
        {
            cout << "Alive";
            cout << "    " << age;

        }
        cout << endl;
    }
    cout <<   "------------------------------------------------------------------------" << endl;
    cout <<   "Year of birth = YOB , Year of death = YOD" << endl << endl;

}


void UserLayer::printListMoreInfo(vector<CSPerson> list)
{
    int sizeOfList = list.size();

    if(sizeOfList == 0)
    {
        cout << "List is empty." << endl;
        return; //á að hætta í forritinu hér?
    }

    cout <<   "#     NAME                            GENDER     YOB     YOD      AGE" << endl;
    cout <<   "------------------------------------------------------------------------------"<< endl;
    for(int i=0;i<sizeOfList;i++)
    {
        string name = list.at(i).getName();
        string gender = list.at(i).getGender();
        string stringBirthYear = to_string(list.at(i).getBirthYear());
        string stringPassedAway = to_string(list.at(i).getPassedAwayYear());
        string info = list.at(i).getComments();
        int age = list.at(i).getAge();


        // adjustForSpaces adjusts the spaces according to the size of the value i in the for loop
        adjustForSpaces(i);

        cout << name.append(32 - name.length(), constants::SPACE);
        cout << gender.append(11 - gender.length(), constants::SPACE);
        cout << stringBirthYear.append(8 - stringBirthYear.length(), constants::SPACE);

        if(stringPassedAway != constants::ALIVE)
        {
            cout << stringPassedAway.append(9 - stringPassedAway.length(), constants::SPACE);
            cout << age;
        }
        else
        {
            cout << "Alive";
            cout << "    " << age;

        }
        cout << endl;
        cout << endl;
        cout << info << endl;
    }
    cout <<   "------------------------------------------------------------------------" << endl << endl;
    cout <<   "Year of birth = YOB , Year of death = YOD" << endl;
}

void UserLayer::printCompleteList()
{
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortListAlphabetically()
{
    _service.sortListAlphabetically();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortListAlphabeticallyASC()
{
    _service.sortListAlphabeticallyASC();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortListByGender()
{
    _service.sortListByGender();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortListByDeathYear()
{
    _service.sortListByDeathYear();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortListByBirthYear()
{
    _service.sortListByBirthYear();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortListByBirthYearASC()
{
    _service.sortListByBirthYearASC();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortListByAge()
{
    _service.sortListByAge();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::searchForAPerson()
{
    string userInput, searchString;

    do
    {
        cout << "| 1 | Search by name" << endl;
        cout << "| 2 | Search by year of year of birth" << endl;
        cout << "| 3 | Search by year of year of death" << endl;
        cout << "| 0 | Go back" << endl;
        cout << "Enter your choice here: ";
        //viljum við hafa Go Back option hérna til að hætta við leit?

        cin >> userInput;
        if(userInput == constants::GO_BACKSTRING)
        {
            return;
        }
        if(userInput == constants::SEARCH_BY_NAME || userInput == constants::SEARCH_BY_YEAR_OF_BIRTH || userInput == constants::SEARCH_BY_YEAR_OF_DEATH)
        {
            break;
        }
        invalidInput();

    }while(userInput != constants::SEARCH_BY_NAME || userInput != constants::SEARCH_BY_YEAR_OF_BIRTH || userInput != constants::SEARCH_BY_YEAR_OF_DEATH);

    cout << "Who are we searching for : ";
    cin.ignore();
    getline(cin, searchString);

    if(userInput == constants::SEARCH_BY_NAME)
    {
        printListMoreInfo(_service.searchByName(searchString));
    }
    else if(userInput == constants::SEARCH_BY_YEAR_OF_BIRTH)
    {
        printListMoreInfo(_service.searchByYearOfBirth(searchString));
    }
    else if(userInput == constants::SEARCH_BY_YEAR_OF_DEATH)
    {
        printListMoreInfo(_service.searchByYearOfDeath(searchString));
    }
}



//Gefur villuskilaboð ef notandi slær inn rangan valkost
void UserLayer::invalidInput()
{
    cout << "Your input was invalid, please try again." << endl;
}

void UserLayer::adjustForSpaces(int i)
{
    i = i+1;
    if(i < 10)
    {
        cout << i << ".    ";
    }
    else if(i>= 10 && i <100)
    {
        cout << i << ".   ";
    }
    else if(i>= 100 && i <1000)
    {
        cout << i << ".  ";
    }
    else if(i>= 1000 && i <10000)
    {
        cout << i << ". ";
    }
}
