#include "models/computer.h"

Computer::Computer(string name, int designyear, int buildyear, string typeId, bool created)
{
    _name = name;
    _designYear = designyear;
    _buildYear = buildyear;
    _typeID = typeId;
    _created = created;
}
