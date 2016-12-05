#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <userlayer.h>
#include <cspersonservice.h>

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
        void processChoice(const string choice, const string subMenuChoice);
        void invalidInput();
        void subMenu(string choice);

};

#endif // MENUINTERFACE_H
