#include "models/computer.h"

Computer::Computer(const int id, const string name,const int designYear,const int buildYear,string typeName, string typeID,const bool created)
{
    int myTypeID = stoi(typeID);
    _name = name;
    _designYear = designYear;
    _buildYear = buildYear;
    _myType.setTypeValues(typeName, myTypeID);
    _isCreated = created;
    _id = id;
}
