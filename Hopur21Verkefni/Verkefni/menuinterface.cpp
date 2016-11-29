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

    // THIS MENU IS NOT COMPLETE YET!!!!!

    cout << "Enter 1 to display the complete list in alphabetical order " << endl;
    cout << "Enter 2 to add a computer scientist to the list " << endl;
    cout << "Enter 3 to search the list for a computer scientist " << endl;
    cout << "Enter 4 to exit program " << endl;
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

        cout << "Enter 1 to sort computer scientists by alphabetical order:" << endl;
        cout << "Enter 2 to sort computer scientists by year of birth:" << endl;
        cout << "Enter 3 to sort computer scientists by year of death:" << endl;

        cin >> choiceSub;
        if(choiceSub == 1)
        {

        }
        else if(choiceSub == 2)
        {

        }
        else if(choiceSub == 3)
        {

        }
        else
        {
            cout << "Your input is invalid, please try again." << endl;
            DisplayMenu();
        }
    }

    else if(choice == 2)
    {
        person.addPerson();
    }

    //Nonni er bestur

}
