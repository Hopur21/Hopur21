#include <iostream>
#include <ui/menuinterface.h>
using namespace std;

void welcomeBanner();

int main()
{
    MenuInterface mI;
    mI.banner();
    mI.DisplayMenu();

    return 0;
}


