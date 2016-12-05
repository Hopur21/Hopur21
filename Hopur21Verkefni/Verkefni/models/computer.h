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
        int _typeID; //Strengur
        bool _created;

    public:
        Computer();

        // Gets
        string getName()const {return _name;}
        int getDesignYear()const {return _designYear;}
        int getBuildYear()const {return _buildYear;}
        int getTypeID()const {return _typeID;}
        bool getCreated()const {return _created;}

        //Sets
        void setName(const string name){_name = name;}
        void setDesignYear(const int designYear){_designYear = designYear;}
        void setBuildYear(const int buildyear){_buildYear = buildyear;}
        void setTypeID(const int type){_typeID = type;}
        void setCreated(const bool created){_created = created;}
};

#endif // COMPUTER_H
