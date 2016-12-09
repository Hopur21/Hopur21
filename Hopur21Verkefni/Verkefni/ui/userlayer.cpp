#include <iostream>
#include "userlayer.h"

using namespace std;

void UserLayer::addPerson()
{
    string gender, comment, birthYear, deathYear, input;
    string name = "";
    char userInput;
    int error_counter = 0;
    bool validity = false;
    vector <Computer> computerList = _service.getComputerList();
    vector <string> userSelection;
    vector <int> realComputerID;

    // If user inputs no input an error message occurs
    do
    {
        cout << "Enter name(or 0 to go back): ";
        cin.ignore();
        getline(cin, name);
        if(name == constants::EMPTY_STRING)
        {
            invalidInput();
        }        
        if(name == constants::GO_BACK)
        {
            return;
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

        if(input == constants::GO_BACK)
        {
            return;
        }
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
    cout << "Enter the year of birth(0 to go back): ";
    cin >> birthYear;
    if(birthYear == constants::GO_BACK)
    {
        return;
    }
    birthYear = birthYearValidation(birthYear);
    cout << "Enter the year this person died, (0 if this person is still alive): ";
    cin >> deathYear;

    // No need to validate if person is still alive.
    if(deathYear != constants::ALIVE)
    {
        deathYear = deathYearValidation(birthYear, deathYear);
    }
    cout << "What is this person's greatest achievement(0 to go back): ";
    cin.ignore();
    getline(cin, comment);
    cout << endl;
    error_counter = 0;

    if(comment == constants::GO_BACK)
    {
        return;
    }

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
                  cout << i+1 << ". " << computerList.at(i).getName() << endl;
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

void UserLayer::computerChoice()
{
    bool valid = false;
    string subMenuChoice;
    while(valid == false)
    {
        cout << endl;
        cout << "Do you want to add:" << endl;
        cout << "| 1 | Computer " << endl;
        cout << "| 2 | Computer type" << endl;
        cin >> subMenuChoice;

        if(subMenuChoice == constants::ADD_COMPUTER || subMenuChoice == constants::ADD_COMPUTER_TYPE)
        {
            valid = true;
        }
        else
        {
            invalidInput();
        }
    }

    if(subMenuChoice == constants::ADD_COMPUTER)
    {
        addComputer();
    }
    else if(subMenuChoice == constants::ADD_COMPUTER_TYPE)
    {
        addComputerType();
    }
}

void UserLayer::addComputerType()
{
    bool valid = constants::INVALID;
    string computerType;
    char yesOrNo;

    do
    {
        cout << "Enter the name of the computer type: ";
        cin.ignore();
        getline(cin, computerType);
        cout << "Is this the computer type you wanted to add?" << endl;
        cout << "TYPE : " << computerType << endl;
        cout << "Enter y for yes, n for no." << endl;

        cin >> yesOrNo;

        switch(yesOrNo)
        {
            case 'y':
            case 'Y':
                _service.addComputerType(computerType);
                cout << "Computer type added successfully" << endl;
                valid = constants::VALID;
                break;
            case 'n':
            case 'N':
                break;
            default:
                invalidInput();
                break;
        }
    }while(valid == constants::INVALID);
}

void UserLayer::addComputer()
{

    string name, type;
    string designYear, buildYear, chosenComputer;
    vector<string> listOfComputerTypes = _service.getComputerTypesList();
    vector<Computer> listOfAllComputers = _service.getComputerList();
    int intDesignYear, intBuildYear, inputComputerType;
    string computerTypeRealID;
    unsigned int sizeOfTypesList = listOfComputerTypes.size();
    int valid; // Sometimes the bool validity didn't work, therefore int valid was also used
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

    cout << "Select the computer type: " << endl;
    cout << endl;

    if(sizeOfTypesList == constants::EMPTY_LIST)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        // Printing computer types
        for(unsigned int i = 0; i < sizeOfTypesList; i++)
        {
            // This should print a list of computer types
            cout << "#" << i+1 << "   " << listOfComputerTypes.at(i) << endl;
        }
    }


    // Selecting a computer type
    do
    {
        valid = constants::INVALID;

        cout << "Choose a computer type: " << endl;
        cout << endl;

        try
        {
            cin >> inputComputerType;
        }
        catch(int e)
        {
            invalidInput();
        }

        if(inputComputerType <= 0 || inputComputerType > sizeOfTypesList)
        {
            invalidInput();
        }
        else if(!isdigit(inputComputerType))
        {
            chosenComputer = listOfComputerTypes.at(inputComputerType-1);
            cout << "You chose : " << chosenComputer << endl;
            valid = constants::VALID;
        }

    }while(valid == constants::INVALID);


    for(unsigned int i = 0; i < listOfAllComputers.size();i++)
    {
        string comparisonType = listOfAllComputers.at(i).getType();
        if(chosenComputer == comparisonType)
        {
            // This is the correct ID of the computer type chosen
            computerTypeRealID = listOfAllComputers.at(i).getTypeID();
        }
    }

    valid = constants::INVALID;

    do
    {
        cout << "Was this computer ever built?" << endl;
        cout << "Enter y for yes, n for no." << endl;

        cin >> yesOrNo;

        switch(yesOrNo)
        {
            case 'y':
            case 'Y':
                created = true;
                valid = constants::VALID;
                break;
            case 'n':
            case 'N':
                created = false;
                valid = constants::VALID;
                break;
            default:
                invalidInput();
                break;
        }
    }while(valid == constants::INVALID);

    if(created == true)
    {

        valid = constants::INVALID;
        do
        {
            cout << "Enter the year the computer was built: ";
            cin >> buildYear;

            if(!checkNumberValidity(buildYear))
            {
                intBuildYear = stoi(buildYear);
                valid = constants::VALID;
            }
            else
            {
                invalidInput();
            }

        }while(valid == constants::INVALID);
    }


    valid = constants::INVALID;
    validity = false;
    connectPersons = false;

    do
    {
        cout << "Do you want to connect a person or persons to the making of this computer? " << endl;
        cout << "Enter y for yes, n for no." << endl;
        cin >> yesOrNo;

        switch(yesOrNo)
        {
            case 'y':
            case 'Y':
                valid = constants::VALID;
                connectPersons = true;
                break;
            case 'n':
            case 'N':
                created = false;
                valid = constants::VALID;
                break;
            default:
                invalidInput();
                break;
        }

    }while(valid == constants::INVALID);

    valid = constants::INVALID;

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
        valid = constants::INVALID;

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

                if(number < 0 || number > sizeOfList)
                {
                    invalidInput();
                }
                else if(number == 0)
                {
                    valid = constants::VALID;
                    break;
                }
                else if(!isdigit(number))
                {

                    string selection = computerScientistList.at(number -1).getName();
                    userSelection.push_back(selection);
                }

            }
        }while(valid == constants::INVALID);

        int realID;

        for(unsigned i = 0; i< userSelection.size() ;i++)
        {
            for(unsigned int j = 0; j< computerScientistList.size(); j++)
            {
                if(userSelection.at(i) == computerScientistList.at(j).getName())
                {
                    realID = computerScientistList.at(j).getID();
                    realScientistID.push_back(realID);
                }
            }
        }
    }

    if(_service.addNewComputerToList(realScientistID, name, intDesignYear, intBuildYear, computerTypeRealID, created))
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
    int valid = constants::INVALID;
    vector<CSPerson> listOfPersons = _service.getComputerScientistList();
    int listSize = listOfPersons.size();
    printCompleteList();
    int number;

    do
    {
        cout << "Enter the number of the person that is to be removed or 0 to go back: ";
        cin >> number;

        if(listSize == constants::EMPTY_LIST)
        {
            cout << "List is empty" << endl;
            return;
        }
        else if(number == constants::EMPTY_LIST)
        {
            return;
        }
        else if(number < constants::EMPTY_LIST || number > listSize)
        {
            invalidInput();
        }
        else if(!isdigit(number))
        {
            valid = constants::VALID;
        }
        else
        {
            //invalidInput();
            break;
        }

    }while(valid == constants::INVALID);

    string selection = listOfPersons.at(number -1).getName();

    int realID;

    for(unsigned int i = 0; i < listSize; i++)
    {
        if(selection == listOfPersons.at(i).getName())
        {
            realID = listOfPersons.at(i).getID();
        }
    }

    if(_service.removePersonFromList(to_string(realID)))
    {
        cout << "Computer scientist removed successfully" << endl;
        cout << endl;
        printCompleteList();
    }
    else
    {
        cout << "Something went wrong" << endl;
    }
}

void UserLayer::removeComputerFromList()
{
    int valid = constants::INVALID;
    vector<Computer> listOfComputers = _service.getComputerList();
    int listSize = listOfComputers.size();
    printCompleteListOfComputers();
    int number;

    do
    {
        cout << "Enter the number of the computer that is to be removed or 0 to go back: ";
        cin >> number;

        if(listSize == constants::EMPTY_LIST)
        {
            cout << "List is empty" << endl;
            return;
        }
        else if(number == constants::EMPTY_LIST)
        {
            return;
        }
        else if(number < constants::EMPTY_LIST || number > listSize)
        {
            invalidInput();
        }
        else if(!isdigit(number))
        {
            valid = constants::VALID;
        }
        else
        {
            break;
        }

    }while(valid == constants::INVALID);

    string selection = listOfComputers.at(number -1).getName();

    int realID;

    for(unsigned int i = 0; i < listSize; i++)
    {
        if(selection == listOfComputers.at(i).getName())
        {
            realID = listOfComputers.at(i).getID();
        }
    }

    if(_service.removeComputerFromList(to_string(realID)))
    {
        cout << "Computer removed successfully" << endl;
        cout << endl;
        printCompleteListOfComputers();
    }
    else
    {
        cout << "Something went wrong" << endl;
    }
}

void UserLayer::printGenderMenu()
{
    cout << "Select gender: " << endl << endl;
    cout << "| 1 | Male" << endl;
    cout << "| 2 | Female" << endl;
    cout << "| 3 | Other" << endl;
    cout << "| 0 | Go back" << endl;
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
            if (deathYear == constants::ALIVE)
            {
                deathYearValidation = false;
                return deathYear;
            }
        }  
        // catches inputs if they are not numbers and if input is lower than birthyear
        if(checkNumberValidity(deathYear))
        {
            invalidInput();
        }
        if(stoi(birthYear) >= stoi(deathYear))
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

        cout << name.append(32 - name.length(), constants::SPACE);
        cout << type;
        cout << endl;
    }
    cout <<   "------------------------------------------------------------------------" << endl;
    cout << endl;
}

void UserLayer::printListMoreInfoComputer()
{
    vector <Computer> computerList = _service.getComputerList();

    int id, realID;
    string buildYear, designYear, name, type, computerScientist;
    bool valid = false;
    int listSize = computerList.size();
    cout << "Enter the id of the computer you want info on: ";
    cin >> id;
    cout << endl;

    do
    {
        if(id < 0 || id > listSize || isdigit(id))
        {
            invalidInput();
            cout << "Enter the id of the computer you want info on: ";
            cout << endl;
            cin >> id;
            cout << endl;
        }
        else
        {
            valid = true;
        }
    }while(valid == false);

    buildYear = to_string(computerList.at(id-1).getBuildYear());
    designYear = to_string(computerList.at(id-1).getDesignYear());
    name = computerList.at(id-1).getName();
    type = computerList.at(id-1).getType();
    //computerScientist = computerList.at(id-1).getCSConntedToComputer(); //how to find the scientist that made the computer???

    cout << "------------------------------------------------------------------------------" << endl;
    cout << "BUILD YEAR:" << buildYear << "          " << name <<  "         DESIGN YEAR:" << designYear << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    // GetRealID of the computer
    for(unsigned int i=0; i< listSize; i++)
    {
        if(name == computerList.at(i).getName())
        {
            realID = computerList.at(i).getID();
        }
    }

    vector <CSPerson> personsConnectedToTheCompter = _service.getScientistConntedToComputers(realID);
    int sizeOfPersonsList = personsConnectedToTheCompter.size();
    cout << "Persons connected to the making and designing of the computer: " << endl;
    for(int i = 0; i < sizeOfPersonsList; i++)
    {
        string personConnected = personsConnectedToTheCompter.at(i).getName();
        if(sizeOfPersonsList > constants::EMPTY_LIST)
        cout << endl;

        cout << "Person " << i+1 << ": " << personConnected << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << personsConnectedToTheCompter.at(i).getComments() << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;
    }
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
    string searchString;
    cout << "Who are we searching for: ";
    cin.ignore();
    getline(cin, searchString);
    vector<CSPerson> listOfPersons = _service.searchComputerScientist(searchString);
    if(listOfPersons.size() == constants::EMPTY_LIST)
    {
        cout << "Not found" << endl;
    }
    else
    {
        printListOfScientists(listOfPersons);
    }
}

void UserLayer::searchForAComputer()
{
    string searchString;

    cout << "Please enter either: Name, type or year: ";
    cin.ignore();
    getline(cin, searchString);
    vector<Computer> listOfComputers = _service.searchComputer(searchString);
    if(listOfComputers.size() == constants::EMPTY_LIST)
    {
        cout << "Not found" << endl;
    }
    else
    {
        printListOfComputers(listOfComputers);
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


