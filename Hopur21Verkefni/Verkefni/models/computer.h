#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
using namespace std;

class Computer
{
    private:
        string _name;
        int _designYear;
        int _buildYear;
        int _typeID;
        bool _created;

    public:
        Computer();
};

#endif // COMPUTER_H
