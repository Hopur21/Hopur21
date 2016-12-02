#include <iostream>
#include <menuinterface.h>
using namespace std;

void welcomeBanner();

int main()
{
    MenuInterface mI;
    mI.banner();
    mI.DisplayMenu();

    return 0;
}
