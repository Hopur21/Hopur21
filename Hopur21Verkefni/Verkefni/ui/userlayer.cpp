#include <iostream>
#include "userlayer.h"
#include <windows.h>

using namespace std;

void UserLayer::addPerson()
{
    string gender, comment, birthYear, deathYear, input;
    string name = "";
    char userInput;
    int error_counter = 0;
    bool validity = false;
    // A list of all computers the scientist might have had something to do with
    vector <Computer> computerList = _service.getComputerList();
    vector <string> userSelection;
    vector <int> realComputerID;

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
        if(computerList.size() == 0)
        {
            cout << "List of computers is empty." << endl;
        }
        else
        {
            cout << endl;
            cout << "Choose one or more computers" << endl;
            cout << endl;

            for(unsigned int i=0; i < computerList.size(); i++)
            {
                  cout << i+1 << "  " << computerList.at(i).getName() << endl;
            }

            int number = 1;
            validity = false;
            int sizeOfList = computerList.size();
            error_counter = 0;

            do
            {
                cout << "Enter one or more numbers with spaces between them: " << endl;
                cout << "End with a zero. " << endl;
                while(number != 0)
                {
                    try
                    {
                        cin >> number;
                    }
                    catch(int e)
                    {
                        invalidInput();
                    }

                    if(number < 0 || number >= sizeOfList)
                    {
                        invalidInput();
                        error_counter = 1;
                    }
                    else if(number == 0)
                    {
                        validity = true;
                        break;
                    }
                    else if(!isdigit(number))
                    {
                        string selection = computerList.at(number -1).getName();
                        userSelection.push_back(selection);
                    }
                }
            }while(validity == false);
        }
    }

    int realID;
    for(unsigned i = 0; i < userSelection.size() ;i++)
    {
        for(unsigned int j = 0; j < computerList.size(); j++)
        {
            if(userSelection.at(i) == computerList.at(j).getName())
            {
                realID = computerList.at(j).getID();
                realComputerID.push_back(realID);
            }
        }
    }

    if(_service.addNewPersonToList(realComputerID, name, gender, birthYear, deathYear, comment))
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
    vector<string> listOfComputerTypes = _service.getComputerTypesList();
    int intDesignYear, intBuildYear;
    bool created = false;
    bool validity = false;
    bool connectPersons = false;
    char yesOrNo;

    cout << "Enter the name of the computer: ";
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
        cout << "Enter the design year of the computer: ";
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

    cout << "Select the computer type: ";

    for(unsigned int i = 0; i < listOfComputerTypes.size(); i++)
    {
        // This should print a list of computer types
        cout << listOfComputerTypes.at(i);
    }
    // Validation needed
    int inputComputerType;
    cin >> inputComputerType;
    cout << endl;

    validity = false;

    // VILLA Í þessu (þetta loopar veit ekki af hverju cin ætti að stoppa loopuna en gerir það ekki)
/*
    do
    {
        cout << "Was this computer ever built?" << endl;
        cout << "Enter y for yes, n for no." << endl;

        cin >> yesOrNo;

        switch(yesOrNo)
        {
            case 'y':
            case 'Y':
            cout << "EHAHEA";
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

    }while(validity == false);




    if(created == true)
    {

        validity = false;
        do
        {

            buildYear = "";
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
            cout << "Enter the year the computer was built: ";

        }while(validity == false);
    }
    else
    {
        intBuildYear = 0;
    }


    validity = false;
*/

    do
    {
        cout << "Do you want to connect a person or persons to the making of this computer? " << endl;
        cout << "Enter y for yes, n for no." << endl;
        cin >> yesOrNo;

        switch(yesOrNo)
        {
            case 'y':
            case 'Y':
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

    vector<int> realScientistID;
    vector<CSPerson> computerScientistList = _service.getComputerScientistList();
    vector<string> userSelection;
    int sizeOfList = computerScientistList.size();

    if(connectPersons == true)
    {

        for(int i=0; i<sizeOfList; i++)
        {
              cout << i+1 << "  " << computerScientistList.at(i).getName() << endl;
        }

        int number = 1;
        validity = false;

        do
        {
            cout << "Enter one or more numbers with spaces between them: " << endl;
            cout << "End with a zero." << endl;
            while(number != 0)
            {
                try
                {
                    cin >> number;
                }
                catch(int e)
                {
                    invalidInput();
                }

                if(number < 0 || number >= sizeOfList)
                {
                    invalidInput();
                }
                else if(number == 0)
                {
                    validity = true;
                    break;
                }
                else if(!isdigit(number))
                {

                    string selection = computerScientistList.at(number -1).getName();
                    userSelection.push_back(selection);
                }

            }
        }while(validity == false);

        int realID;

        for(unsigned i = 0; i< userSelection.size() ;i++)
        {
            for(unsigned int j = 0; j< computerScientistList.size(); j++)
            {
                if(userSelection.at(i) == computerScientistList.at(j).getName())
                {
                    realID = computerScientistList.at(j).getID();
                    cout << "-------> " << realID << endl;
                    realScientistID.push_back(realID);
                }
            }
        }

    }

    vector<int> tempvectorToIgnoreError;
    if(!(_service.addNewComputerToList(tempvectorToIgnoreError, name, intDesignYear, intBuildYear, type, created)))
    {
        cout << "The computer has been added successfully." << endl;
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
    string name, type;

    int sizeOfList = list.size();
    if(sizeOfList == 0)
    {
        cout << "List of computers is empty." << endl;
        cout << endl;
        return;
    }
    cout <<   "#     NAME                            TYPE                                    " << endl;
    cout <<   "------------------------------------------------------------------------------" << endl;

    for(int i=0;i<sizeOfList;i++)
    {
        name = list.at(i).getName();
        type = list.at(i).getType();

        // adjustForSpaces adjusts the spaces between the
        // number and name of the computer according to the size of the value i in the for loop
        adjustForSpaces(i);

        // sets font in console to RED
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 9);

        cout << name.append(32 - name.length(), constants::SPACE);

        SetConsoleTextAttribute(hConsole, 15); //set back to black background and white text


        cout << type;
        cout << endl;
    }
    cout <<   "------------------------------------------------------------------------" << endl;
}

void UserLayer::printListMoreInfoComputer()
{
    vector <Computer> computerList = _service.getComputerList();
    int id;
    string buildYear, designYear, name;
    bool valid = false;
    int listSize = computerList.size();
    cout << "Enter the id of the computer you want info on: ";
    cin >> id;

    do
    {
        if(id < 0 || id >= listSize || isdigit(id))
        {
            invalidInput();
            cout << "Enter the id of the computer you want info on: ";
            cout << endl;
            cin >> id;
        }
        else
        {
            valid = true;
        }
    }while(valid == false);

    buildYear = to_string(computerList.at(id-1).getBuildYear());
    designYear = to_string(computerList.at(id-1).getDesignYear());
    name = computerList.at(id-1).getName();

    cout << "BUILD YEAR:" << buildYear << "          "<< name <<  "         DESIGN YEAR:" << designYear << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    for(int i=0;i<6;i++)
    {
        cout << "TODO PRENTA UPPLÝSINGAR UM HÖNNUÐI OG SVOLEIÐIS!" << endl;
    }
    cout <<   "------------------------------------------------------------------------------" << endl;
}

void UserLayer::printListOfScientists(vector<CSPerson> list)
{
    int sizeOfList = list.size();
    if(sizeOfList == 0)
    {
        cout << "List of computer scientists is empty." << endl;
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

// COMPUTER CALLS

void UserLayer::printCompleteListOfComputers()
{
    printListOfComputers(_service.getComputerList());
}

// SCIENTIST CALLS

void UserLayer::printCompleteList()
{
    printListOfScientists(_service.getComputerScientistList());
}
//Scientist Sorts
void UserLayer::sortScientistListAlphabetically()
{
    _service.sortScientistListAlphabetically();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortScientistListAlphabeticallyDESC()
{
    _service.sortScientistListAlphabeticallyDESC();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortScientistListByGender()
{
    _service.sortScientistListByGender();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortScientistListByDeathYear()
{
    _service.sortScientistListByDeathYear();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortScientistListByBirthYear()
{
    _service.sortScientistListByBirthYear();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortScientistListByBirthYearASC()
{
    _service.sortScientistListByBirthYearASC();
    printListOfScientists(_service.getComputerScientistList());
}

void UserLayer::sortScientistListByAge()
{
    _service.sortScientistListByAge();
    printListOfScientists(_service.getComputerScientistList());
}
//TODO Computer Sorts
void UserLayer::sortComputerListAlphabetically()
{
    _service.sortComputerListAlphabetically();
    printListOfComputers(_service.getComputerList());
}

void UserLayer::sortComputerListAlphabeticallyDESC()
{
    _service.sortComputerListAlphabeticallyDESC();
    printListOfComputers(_service.getComputerList());
}

void UserLayer::sortComputerListByDesignYear()
{
    _service.sortComputerListByDesignYear();
    printListOfComputers(_service.getComputerList());
}

void UserLayer::sortComputerListByType()
{
    _service.sortComputerListByType();
    printListOfComputers(_service.getComputerList());
}

void UserLayer::sortComputerListByWasBuilt()
{
    _service.sortComputerListWasBuilt();
    printListOfComputers(_service.getComputerList());
}

void UserLayer::sortComputerListByBuildYear()
{
    _service.sortComputertListByBuildYear();
    printListOfComputers(_service.getComputerList());
}
//Searches
void UserLayer::searchForAPerson()
{
    string userInput, searchString;

    do
    {
        cout << "| 1 | Search by name" << endl;
        cout << "| 2 | Search by year of birth" << endl;
        cout << "| 3 | Search by year of death" << endl;
        cout << "| 0 | Go back" << endl;
        cout << "Enter your choice here: ";

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

void UserLayer::searchForAComputer()
{
    string userInput, searchString;

    do
    {
        cout << "| 1 | Search by name" << endl;
        cout << "| 2 | Search by type" << endl;
        cout << "| 3 | Search by year" << endl;
        cout << "| 0 | Go back" << endl;
        cout << "Enter your choice here: ";

        cin >> userInput;
        if(userInput == constants::GO_BACKSTRING)
        {
            return;
        }
        if(userInput == constants::SEARCH_BY_NAME || userInput == constants::SEARCH_BY_TYPE || userInput == constants::SEARCH_BY_YEAR)
        {
            break;
        }
        invalidInput();

    }while(userInput != constants::SEARCH_BY_NAME || userInput != constants::SEARCH_BY_TYPE || userInput != constants::SEARCH_BY_YEAR);

    cout << "Please enter either: Name, type or year : ";
    cin.ignore();
    getline(cin, searchString);

    if(userInput == constants::SEARCH_BY_NAME)
    {
        _service.searchComputerByName(searchString);
    }
    else if(userInput == constants::SEARCH_BY_TYPE)
    {
        _service.searchComputerByType(searchString);
    }
    else if(userInput == constants::SEARCH_BY_YEAR)
    {
        _service.searchComputerByYear(searchString);
    }
}

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
