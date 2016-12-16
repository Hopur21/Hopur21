#include "computertype.h"

ComputerType::ComputerType() {}

//Both values are set in at once, to make sure the ID is not skipped.
void ComputerType::setTypeValues(std::string& name, int& id)
{
    _typeName = name;
    _typeID = id;
}

//Gets
std::string ComputerType::getName()
{
    return _typeName;
}

int ComputerType::getID()
{
    return _typeID;
}
