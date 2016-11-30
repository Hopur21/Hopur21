#include <csperson.h>

using namespace std;

CSPerson::CSPerson(string name, string gender, int birthYear, int passedAwayYear, string comment)
{
   _name = name;
   _gender = gender;
   _birthYear = birthYear;
   _passedAwayYear = passedAwayYear;
   _comment = comment;
}
