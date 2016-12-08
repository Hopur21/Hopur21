#ifndef USERLAYER_H
#define USERLAYER_H

#include "services/service.h"
#include <iostream>
#include "services/service.h"
#include "models/csperson.h"
#include "models/computer.h"


class UserLayer
{
    private:
        Service _service;
        void printListOfScientists(vector<CSPerson> list);
        void printListOfComputers(vector<Computer> list);
        void printListMoreInfo(vector<CSPerson> list);
        void adjustForSpaces(int i);
        void printGenderMenu();
        bool checkNumberValidity(string userInput);
        string birthYearValidation(string birthYear);
        string deathYearValidation(string birthYear, string deathYear);

    public:
        UserLayer(){}
        void addPerson();
        void addComputer();
        void removePersonFromList();
        //Scientist Sorts
        void sortScientistListAlphabetically();
        void sortScientistListAlphabeticallyDESC();
        void sortScientistListByGender();
        void sortScientistListByDeathYear();
        void sortScientistListByBirthYear();
        void sortScientistListByBirthYearASC();
        void sortScientistListByAge();
        //TODO Computer Sorts
        void sortComputerListAlphabetically();
        void sortComputerListAlphabeticallyDESC();
        void sortComputerListByDesignYear();
        void sortComputerListByType();
        void sortComputerListByWasBuilt();
        void sortComputerListByBuildYear();
        void searchForAPerson();
        void searchForAComputer();
        void printCompleteList();
        void printListMoreInfoComputer();
        void printCompleteListOfComputers();

        void invalidInput();
};

#endif // USERLAYER_H
