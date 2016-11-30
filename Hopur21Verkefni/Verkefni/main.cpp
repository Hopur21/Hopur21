#include <iostream>
#include <csperson.h>
#include <menuinterface.h>
#include <listaccess.h>
using namespace std;

void welcomeBanner();

int main()
{
    welcomeBanner();
    MenuInterface mI;
    mI.DisplayMenu();

    return 0;
}
