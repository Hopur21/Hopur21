#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <csperson.h>

class MenuInterface
{
    private:
        CSPerson person;
        //ListAccess lA;
    public:
        void DisplayMenu();
        void processChoice(int choice);
};

#endif // MENUINTERFACE_H
