#include "models/computer.h"

Computer::Computer(const int id, const string name,const int designYear,const int buildYear,string typeName, string typeID,const bool created, const int imageID,const QByteArray imageByteArray, string imageName)
{
    int myTypeID = stoi(typeID);
    _id = id;
    _name = name;
    _designYear = designYear;
    _buildYear = buildYear;
    _myType.setTypeValues(typeName, myTypeID);
    _isCreated = created;
    //If imageID is not negative (which is default value)
    if(imageID >=0)
    {
        setImageInfo(imageID, imageByteArray,imageName);
    }
}

void Computer::setImageInfo(int imageID,QByteArray imageByteArray, string imageName)
{
    _myImage.setImageValues(imageByteArray,imageName,imageID);
}
