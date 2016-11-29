#include "menuinterface.h"
#include <iostream>
using namespace std;


void MenuInterface::DisplayMenu()
{
    // TODO: Setja valmöguleikana í const


    int choice = 0;
    cout << "**************************************" << endl;
    cout << "WELCOME TO THE COMPUTER SCIENTIST LIST" << endl;
    cout << "**************************************" << endl;
    cout << endl;

    // THIS MENU IS NOT COMPLETE YET!!!!!

    cout << "Enter 1 to display the complete list " << endl;
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
        cout << endl;
        cout << "Your input was invalid, please try again." << endl;
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
            // call sort function
        }
        else if(choiceSub == 2)
        {
            // call sort function
        }
        else if(choiceSub == 3)
        {
            // call sort ...
        }
        else
        {
            cout << "Your input was invalid, please try again." << endl;
            DisplayMenu();
        }
    }

    else if(choice == 2)
    {
        _uL.addPerson();
    }

    else if(choice == 3)
    {
        //search list for CS
    }

    else if(choice == 4)
    {
        return;
    }

}
