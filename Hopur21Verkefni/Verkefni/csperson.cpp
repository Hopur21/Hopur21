#include <csperson.h>
#include <iostream>
#include <string>

using namespace std;

CSPerson::CSPerson(){};

CSPerson::CSPerson(string name, string gender, int birthYear, int deathYear, string comment)
{
   _name = name;
   _gender = gender;
   _birthYear = birthYear;
   _deathYear = deathYear;
   _comment = comment;
}
