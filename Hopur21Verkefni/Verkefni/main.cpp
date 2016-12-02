#include <iostream>
#include <menuinterface.h>
using namespace std;

void welcomeBanner();

int main()
{
    MenuInterface mI;
    mI.welcomeBanner();
    mI.DisplayMenu();

    return 0;
}
