#include <iostream>
#include "userlayer.h"

using namespace std;

const string SEARCH_BY_NAME = "1";
const string SEARCH_BY_YEAR_OF_BIRTH = "2";
const string SEARCH_BY_YEAR_OF_DEATH = "3";

const string GENDER_MALE = "1";
const string GENDER_FEMALE = "2";
const string GENDER_OTHER = "3";
const string ALIVE = "0";
const char SPACE = ' ';
const int GO_BACK = 0;
const string GO_BACKSTRING = "0";


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

    // Birth year validation
    cout << "Enter the year of birth: ";
    cin >> birthYear;
    birthYear = birthYearValidation(birthYear);
    cout << "Enter the year this person died, (0 if this person is still alive): ";
    cin >> deathYear;

    // No need to validate if person is still alive.
    if(deathYear != ALIVE)
    {
        deathYear = deathYearValidation(birthYear, deathYear);
    }
    cout << "What is this person's greatest achievement: ";
    cin.ignore();
    getline(cin, comment);
    cout << endl;

    if(_service.addNewPersonToList(name, gender, birthYear, deathYear, comment))
    {
        cout << "This person has been added successfully." << endl;
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
    int personToRemove;
    cout << "Enter the number of the person that is to be removed or 0 to go back: ";
    cin >> personToRemove;
    if(personToRemove == GO_BACK)
    {
        return;
    }
    _service.removePersonFromList(to_string(personToRemove));
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

void UserLayer::printList(vector<CSPerson> list)
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

        cout << name.append(32 - name.length(), SPACE);
        cout << gender.append(11 - gender.length(), SPACE);
        cout << stringBirthYear.append(8 - stringBirthYear.length(), SPACE);

        if(stringPassedAway != ALIVE)
        {
            cout << stringPassedAway.append(9 - stringPassedAway.length(), SPACE);
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

        cout << name.append(32 - name.length(), SPACE);
        cout << gender.append(11 - gender.length(), SPACE);
        cout << stringBirthYear.append(8 - stringBirthYear.length(), SPACE);

        if(stringPassedAway != ALIVE)
        {
            cout << stringPassedAway.append(9 - stringPassedAway.length(), SPACE);
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
    printList(_service.getCompleteList());
}

void UserLayer::sortListAlphabetically()
{
    _service.sortListAlphabetically();
    printList(_service.getCompleteList());
}
void UserLayer::sortListAlphabeticallyASC()
{
    _service.sortListAlphabeticallyASC();
    printList(_service.getCompleteList());
}
void UserLayer::sortListByGender()
{
    _service.sortListByGender();
    printList(_service.getCompleteList());
}
void UserLayer::sortListByDeathYear()
{
    _service.sortListByDeathYear();
    printList(_service.getCompleteList());
}
void UserLayer::sortListByBirthYear()
{
    _service.sortListByBirthYear();
    printList(_service.getCompleteList());
}
void UserLayer::sortListByBirthYearASC()
{
    _service.sortListByBirthYearASC();
    printList(_service.getCompleteList());
}

void UserLayer::sortListByAge()
{
    _service.sortListByAge();
    printList(_service.getCompleteList());
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
        if(userInput == GO_BACKSTRING)
        {
            return;
        }
        if(userInput == SEARCH_BY_NAME || userInput == SEARCH_BY_YEAR_OF_BIRTH || userInput == SEARCH_BY_YEAR_OF_DEATH)
        {
            break;
        }
        invalidInput();

    }while(userInput != SEARCH_BY_NAME || userInput != SEARCH_BY_YEAR_OF_BIRTH || userInput != SEARCH_BY_YEAR_OF_DEATH);

    cout << "Who are we searching for : ";
    cin.ignore();
    getline(cin, searchString);

    if(userInput == SEARCH_BY_NAME)
    {
        printListMoreInfo(_service.searchByName(searchString));
    }
    else if(userInput == SEARCH_BY_YEAR_OF_BIRTH)
    {
        printListMoreInfo(_service.searchByYearOfBirth(searchString));
    }
    else if(userInput == SEARCH_BY_YEAR_OF_DEATH)
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
