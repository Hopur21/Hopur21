#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <userlayer.h>

class MenuInterface
{
    private:
        UserLayer uL;

    public:
        void DisplayMenu();
        void processChoice(int choice);
};

#endif // MENUINTERFACE_H
