#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <userlayer.h>
#include <cspersonservice.h>

class MenuInterface
{
    private:
        UserLayer _uL;

    public:
        void DisplayMenu();
        void welcomeBanner();
        void processChoice(const string choice);
        void invalidInput();
};

#endif // MENUINTERFACE_H
