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
        string _type;
        bool _created;

    public:
        Computer(){}
        Computer(string name, int designyear, int buildyear, string type, bool created);

        // Gets
        string getName()const {return _name;}
        int getDesignYear()const {return _designYear;}
        int getBuildYear()const {return _buildYear;}
        string getTypeID()const {return _type;}
        bool getCreated()const {return _created;}

        //Sets
        void setName(const string name){_name = name;}
        void setDesignYear(const int designYear){_designYear = designYear;}
        void setBuildYear(const int buildyear){_buildYear = buildyear;}
        void setType(const string type){_type = type;}
        void setCreated(const bool created){_created = created;}
};

#endif // COMPUTER_H
