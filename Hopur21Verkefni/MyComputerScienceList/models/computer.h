#ifndef COMPUTER_H
#define COMPUTER_H
#include "models/computertype.h"
#include <string>
#include <models/image.h>

using namespace std;

class Computer
{
    public:
        Computer(){}
        Computer(const int id, const string name,const int designYear,const int buildYear,string typeName, string typeID,const bool created, const int imageID = -1,const QByteArray imageByteArray = NULL, string imageName = "");
        // Gets
        string getName()const {return _name;}
        string getType() {return _myType.getName();}
        string getTypeID() {return to_string(_myType.getID());}
        int getDesignYear()const {return _designYear;}
        int getBuildYear()const {return _buildYear;}
        int getID()const {return _id;}
        bool getIsCreated()const {return _isCreated;}
        QByteArray getImage(){return _myImage.getImageByteArray();}
        string getImageName(){return _myImage.getName();}
        int getImageID(){return _myImage.getID();}
        //Sets
        void setName(const string name){_name = name;}
        void setDesignYear(const int designYear){_designYear = designYear;}
        void setBuildYear(const int buildYear){_buildYear = buildYear;}
        void setType(string typeName, int typeID){_myType.setTypeValues(typeName, typeID);}
        void setCreated(const bool isCreated){_isCreated = isCreated;}
        void setID(const int ID) {_id = ID;}
        void setImageInfo(int imageID,QByteArray imageByteArray, string imageName);
        void setImage(const Image& newImage){_myImage = newImage;}

    private:
        ComputerType _myType;
        Image _myImage;
        string _name;
        bool _isCreated;
        int _id;
        int _designYear;
        int _buildYear;
};

#endif // COMPUTER_H
