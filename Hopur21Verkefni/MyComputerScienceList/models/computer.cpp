#include "models/computer.h"

Computer::Computer(const int id, const string name,const int designYear,const int buildYear,const string type, const string typeID,const bool created)
{
    _name = name;
    _designYear = designYear;
    _buildYear = buildYear;
    _type = type;
    _typeID = typeID;
    _isCreated = created;
    _id = id;
}
