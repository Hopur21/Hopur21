#include "cspersonservice.h"
//Bool variablers are used in sorting to decide the order of sorting, DESCending and ASCending
bool sortByNameDESCC(const CSPerson &lhs, const CSPerson &rhs) { return lhs.getName() > rhs.getName(); }
bool sortByNameASCC(const CSPerson &lhs, const CSPerson &rhs) { return lhs.getName() < rhs.getName(); }
bool sortByGenderDESC(const CSPerson &lhs, const CSPerson &rhs) { return lhs.getGender() < rhs.getGender(); }
bool sortByDeathYearASCC(const CSPerson &lhs, const CSPerson &rhs) {return lhs.getPassedAwayYear() > rhs.getPassedAwayYear(); }
bool sortByBirthYearDESC(const CSPerson &lhs, const CSPerson &rhs) {return lhs.getBirthYear() < rhs.getBirthYear(); }
bool sortByBirthYearASCC(const CSPerson &lhs, const CSPerson &rhs) {return lhs.getBirthYear() > rhs.getBirthYear(); }
bool sortByAgeASCC(const CSPerson &lhs, const CSPerson &rhs)
{
    CSPerson tempLeft = lhs;//Copy our const into a temp variable, so we can work with our int value and get the age.
    CSPerson tempRight = rhs;
    return tempLeft.getAge() > tempRight.getAge();
}
CSPersonService::CSPersonService()
{
}
//Sorts
void CSPersonService::sortByName(vector<CSPerson>& computerScientists)
{
    sort(computerScientists.begin(), computerScientists.end(), sortByNameASCC);
}
void CSPersonService::sortByNameDESC(vector<CSPerson>& computerScientists)
{
    sort(computerScientists.begin(), computerScientists.end(), sortByNameDESCC);
}
void CSPersonService::sortByGender(vector<CSPerson>& computerScientists)
{
    sort(computerScientists.begin(), computerScientists.end(), sortByGenderDESC);
}
void CSPersonService::sortByDeathYear(vector<CSPerson>& computerScientists)
{
    sort(computerScientists.begin(), computerScientists.end(), sortByDeathYearASCC);
}
void CSPersonService::sortByBirthYear(vector<CSPerson>& computerScientists)
{
    sort(computerScientists.begin(), computerScientists.end(), sortByBirthYearDESC);
}
void CSPersonService::sortByBirthYearASC(vector<CSPerson>& computerScientists)
{
    sort(computerScientists.begin(), computerScientists.end(), sortByBirthYearASCC);
}
void CSPersonService::sortByAge(vector<CSPerson>& computerScientists)
{
    sort(computerScientists.begin(), computerScientists.end(), sortByAgeASCC);
}



bool CSPersonService::validNumber(string number)
{
    int inputNumber = 0;
    try
    {
        inputNumber = stoi(number.c_str());//Try to convert string to int
    }
    catch(int e)
    {
        return false;
    }
    if(inputNumber > 0  || inputNumber < 3000)//If the year is beetween 1 - 2999
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Returns true if string2 is a part of string1, no matter upper or lower case.
bool CSPersonService::checkIfStringSameIgnoreUpper(string orginalString, string searchFor)
{
    //Make sure both strings are the same case
    transform(orginalString.begin(), orginalString.end(),orginalString.begin(), ::tolower);
    transform(searchFor.begin(), searchFor.end(),searchFor.begin(), ::tolower);
    if(orginalString.find(searchFor) != string::npos)//If string.find is not size_t max size
    {
        return true;
    }
    else
    {
        return false;
    }
}
