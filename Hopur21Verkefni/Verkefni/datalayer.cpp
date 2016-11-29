#include "datalayer.h"


#include<iostream>

DataLayer::DataLayer()
{
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();


}
