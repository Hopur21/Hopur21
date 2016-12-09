#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include "utilities/constants.h"
#include "ui/userlayer.h"


class MenuInterface
{
    private:
        UserLayer _userLayer;
        int _firstTimeBooting;

    public:
        MenuInterface();
        void DisplayMenu();
        void welcomeBanner();
        void banner();
        void processChoice(const string choice);
        void invalidInput();
        void displayScientists();
        void displayComputers();

};

#endif // MENUINTERFACE_H
