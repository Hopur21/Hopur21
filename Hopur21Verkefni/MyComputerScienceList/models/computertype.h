#ifndef COMPUTERTYPE_H
#define COMPUTERTYPE_H
#include <string>

class ComputerType
{
public:
    ComputerType();

    //Sets
    void setTypeValues(std::string& name, int& id);
    //Gets
    std::string getName();
    int getID();
private:
    std::string _typeName;
    int _typeID;
};

#endif // COMPUTERTYPE_H
