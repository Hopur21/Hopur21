#include "models/computer.h"

Computer::Computer(int id, string name, int designyear, int buildyear, string type, bool created)
{
    _name = name;
    _designYear = designyear;
    _buildYear = buildyear;
    _type = type;
    _isCreated = created;
    _id = id;
}
