#ifndef COMPUTERSCIENTISTTOCOMPUTER_H
#define COMPUTERSCIENTISTTOCOMPUTER_H


class ComputerScientistToComputer
{
public:
    ComputerScientistToComputer();
    int getCSid(){return _csID;}
    int getCompID(){return _compID;}

    void setCSID(int csID){_csID = csID;}
    void setCompID(int compID){_compID = compID;}

private:
    int _csID;
    int _compID;
};

#endif // COMPUTERSCIENTISTTOCOMPUTER_H
