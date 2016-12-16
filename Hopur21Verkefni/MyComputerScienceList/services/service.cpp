#include "service.h"

Service::Service()
{
    updateAllLists();
}
bool Service::addNewPersonToList(const vector<int> computerConnectionID,const string name,const string gender, const string birthYear, const string deathYear,const string comment, string imageName, QByteArray image)
{
    Image newImage;
    int newImageID = NULL;

    if(!image.isEmpty())//If picture is inserted
    {
        newImageID =_dbCon.addPicture(imageName,image);
        newImage.setImageValues(image,imageName,newImageID);
    }
    CSPerson newPerson;
    int newPersonID;
    newPerson.setName(name);
    newPerson.setGender(gender);
    newPerson.setBirthYear(stoi(birthYear));
    newPerson.setPassedAwayYear(stoi(deathYear));
    if(deathYear != constants::ALIVE) {
        newPerson.setIsAlive(false);
    } else {
        newPerson.setIsAlive(true);
    }
    newPerson.setComment(comment);
    newPerson.setImage(newImage);
    newPersonID = _dbCon.addComputerScientist(newPerson);
    for(unsigned int i = 0; i < computerConnectionID.size(); i++)
    {
        _dbCon.addCStoComputer(newPersonID,computerConnectionID[i]);
    }
    updateComputerScientistList();
    return true;
}
bool Service::onlyAddPicturetoDB(const string picName, QByteArray picture)
{
    try
    {
        _dbCon.addPicture(picName, picture);
        return true;
    }
    catch(int e)
    {
        return false;
    }
}

bool Service::addNewComputerToList(const vector<int> scientistConnectionID, const string name, const int designYear, const int buildYear, const string typeRealID, const bool created, string imageName, QByteArray image)
{
    int typeID = 0;
    try
    {
        typeID = stoi(typeRealID);
    }
    catch(int e)
    {
        return false;//We didnt make it.
    }
    Image newImage;
    int newImageID;

    if(!image.isEmpty())//If picture is inserted
    {
        newImageID =_dbCon.addPicture(imageName,image);
        newImage.setImageValues(image,imageName,newImageID);
    }

    Computer newComputer;
    int newComputerID = 0;
    newComputer.setName(name);
    newComputer.setDesignYear(designYear);
    newComputer.setBuildYear(buildYear);
    newComputer.setType("", typeID);
    newComputer.setCreated(created);
    newComputer.setImage(newImage);
    newComputerID = _dbCon.addComputer(newComputer);
    //Assign computer to computer scientists
    for(unsigned int i = 0; i < scientistConnectionID.size(); i++)
    {
        _dbCon.addCStoComputer(scientistConnectionID[i],newComputerID);
    }
    updateComputerList();
    return true;
}
bool Service::removePersonFromList(const string id)
{
    if(!validNumber(id))
    {
        return false;
    }
    bool success = _dbCon.removeComputerScientist(stoi(id));
    if(success)
    {
        updateComputerScientistList();
    }
    return success;
}
bool Service::removeComputerFromList(const string id)
{
    if(!validNumber(id))
    {
        return false;
    }
    bool success = _dbCon.removeComputer(stoi(id));
    if(success)
    {
        updateComputerList();
    }
    return success;
}
vector<CSPerson> Service::getComputerScientistTrash()
{
    return _dbCon.getComputerScientistsTrashCan();
}

vector<Computer> Service::getComputerTrash()
{
    return _dbCon.getComputerTrashCan();
}

vector<CSPerson> Service::getScientistConntedToComputers(const int computerID)
{
    return _dbCon.getCSConntedToComputer(computerID);
}
vector<Computer> Service::getComputersConntedToCS(const int computerScientistID)
{
    return _dbCon.getComputersConnectedToCS(computerScientistID);
}

void Service::updateComputerTypesList()
{
    _dbCon.getComputerTypes(_computerTypes);
}
void Service::updateComputerList()
{
    _dbCon.getComputers(_computerList);
}
void Service::updateComputerScientistList()
{
    _dbCon.getComputerScientists(_computerScientists);
}
void Service::updateAllLists()
{
    updateComputerScientistList();
    updateComputerList();
    updateComputerTypesList();
}
bool Service::validNumber(string number)
{
    try
    {
        stoi(number);
        return true;
    }
    catch(int e)
    {
        return false;
    }
}
bool Service::addComputerType(const string typeName)
{
    return _dbCon.addComputerType(typeName);
}

vector<CSPerson> Service::searchComputerScientist(const string searchString)
{
    vector <CSPerson> searchCS;
    _dbCon.searchScientist(searchCS,searchString);
    return searchCS;
}
vector<Computer> Service::searchComputer(const string searchString)
{
    vector<Computer> searchComputer;
    _dbCon.searchComputer(searchComputer, searchString);
    return searchComputer;
}
