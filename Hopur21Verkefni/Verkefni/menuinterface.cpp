#include "menuinterface.h"
#include <iostream>
using namespace std;


void MenuInterface::DisplayMenu()
{
    int choice = 0;
    cout << "**************************************" << endl;
    cout << "WELCOME TO THE COMPUTER SCIENTIST LIST" << endl;
    cout << "**************************************" << endl;
    cout << endl;


    cout << "Enter 1 to display the complete list " << endl;
    cout << "Enter 2 to add a computer scientist to the list " << endl;
    cout << "Enter 3 to search the list for a computer scientist " << endl;
    cout << "Enter 4 to remove a computer scientist from the list" << endl;
    cout << "Enter 5 to exit program " << endl;
    cin >> choice;

    if(choice == 1 || choice == 2 || choice == 3 || choice ==4)
    {
        processChoice(choice);
    }
    else
    {
        cout << "Your input is invalid, please try again." << endl;
        DisplayMenu();
    }
}

void MenuInterface::processChoice(int choice)
{
    int choiceSub;
    // Here the input from the main menu is processed
    if(choice == 1)
    {
        // SETJA ALLT ÞETTA DRASL Í SÉR FÖLL!!!!
        //sub menu for different display options
        //in alphabetical order
        //by age
        //by year of birth
        //by year of death

        cout << "Enter 1 to sort computer scientists by alphabetical order:" << endl;
        cout << "Enter 2 to sort computer scientists by year of birth:" << endl;
        cout << "Enter 3 to sort computer scientists by year of death:" << endl;

        cin >> choiceSub;
        if(choiceSub == 1)
        {
            cout << "Computer Scientists in alphabetical order:" << endl;
            cout << "******************************************" << endl;
            cout << endl;

            //funtion sort alphabetical

            // TODO
        }
        else if(choiceSub == 2)
        {
            cout << "Computer Scientists by age:" << endl;
            cout << "***************************" << endl;
            cout << endl;

            //funtion sort by age, age = deathYear-birthYear
            //if still alive (no deathYear), age = 2016-birthYear
        }
        else if(choiceSub == 3)
        {
            cout << "Computer Scientists by year of birth:" << endl;
            cout << "*************************************" << endl;
            cout << endl;

            //funtion sort by year of birth
        }
        else if(choiceSub == 4)
        {
            cout << "Computer Scientists by year of death:" << endl;
            cout << "*************************************" << endl;
            cout << endl;

            //funtion sort by year of death
        }
    }

    else if(choice == 2)
    {
        person.addPerson();
    }

    else if(choice == 3)
    {
        //search list for CS
    }

    else if(choice == 4)
    {
        //exit program
        //return 0;
    }

}
