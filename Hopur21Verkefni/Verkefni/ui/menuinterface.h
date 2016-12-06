#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include "utilities/constants.h"
#include "ui/userlayer.h"


class MenuInterface
{
    private:
        UserLayer _uL;
        int _firstTimeBooting;

    public:
        MenuInterface();
        void DisplayMenu();
        void welcomeBanner();
        void banner();
        void processChoice(const string choice);
        void invalidInput();
        string subMenu();
        void displayScientists();

};

#endif // MENUINTERFACE_H
