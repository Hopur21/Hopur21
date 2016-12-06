#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <ui/userlayer.h>
//#include <services/cspersonservice.h>

class MenuInterface
{
    private:
        UserLayer _uL;
        int firstTimeBooting;

    public:
        MenuInterface(){firstTimeBooting = 0;}
        void DisplayMenu();
        void welcomeBanner();
        void banner();
        void processChoice(const string choice);
        void invalidInput();
        string subMenu();
        void displayScientists();

};

#endif // MENUINTERFACE_H
