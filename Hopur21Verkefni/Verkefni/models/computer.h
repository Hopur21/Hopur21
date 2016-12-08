#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
using namespace std;

class Computer
{
    private:
        string _name;
        string _type;
        bool _isCreated;
        int _id;
        int _designYear;
        int _buildYear;

    public:
        Computer(){}
        Computer(const int id, const string name,const int designYear,const int buildYear,const string type,const bool created);

        // Gets
        string getName()const {return _name;}
        int getDesignYear()const {return _designYear;}
        int getBuildYear()const {return _buildYear;}
        string getType()const {return _type;}
        bool getIsCreated()const {return _isCreated;}
        int getID()const {return _id;}

        //Sets
        void setName(const string name){_name = name;}
        void setDesignYear(const int designYear){_designYear = designYear;}
        void setBuildYear(const int buildYear){_buildYear = buildYear;}
        void setType(const string type){_type = type;}
        void setCreated(const bool isCreated){_isCreated = isCreated;}
        void setID(const int ID) {_id = ID;}
};

#endif // COMPUTER_H
