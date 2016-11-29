#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <userlayer.h>
#include <csperson.h>

class MenuInterface
{
    private:
        UserLayer uL;
        //ListAccess lA;
    public:
        void DisplayMenu();
        void processChoice(int choice);
};

#endif // MENUINTERFACE_H
