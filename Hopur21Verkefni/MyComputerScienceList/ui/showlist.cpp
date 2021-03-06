#include "showlist.h"
#include "ui_showlist.h"
#include "models/csperson.h"
#include "services/service.h"
#include <QTableWidget>
#include <QDialog>

ShowList::ShowList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowList)
{
    ui->setupUi(this);
}

void ShowList::setList(vector<CSPerson> compScientistsList, vector<Computer> computerList, vector<ComputerScientistToComputer> computerCSconnection)
{
    _computerCSconnection = computerCSconnection;
    _computerList = computerList;
    _CSlist = compScientistsList;
    printComputerList();
    printComputerScientistList();
}

void ShowList::printComputerScientistList()
{
    //Display computerScientistList
    ui->table_ComputerScientist->setRowCount(_CSlist.size());
    ui->table_ComputerScientist->setColumnCount(5);
    for(size_t i = 0; i < _CSlist.size(); i++)
    {
        ui->table_ComputerScientist->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(_CSlist[i].getName())));
        ui->table_ComputerScientist->setItem(i, 1, new QTableWidgetItem(QString::number(_CSlist[i].getAge())));
        ui->table_ComputerScientist->setItem(i, 2, new QTableWidgetItem(QString::number(_CSlist[i].getBirthYear())));
        int yearOfDeath = _CSlist[i].getPassedAwayYear();
        if(yearOfDeath == constants::STILL_ALIVE)
        {
            ui->table_ComputerScientist->setItem(i, 3, new QTableWidgetItem("Still alive"));
        }
        else
        {
            ui->table_ComputerScientist->setItem(i, 3, new QTableWidgetItem(QString::number(_CSlist[i].getPassedAwayYear())));
        }
        ui->table_ComputerScientist->setItem(i, 4, new QTableWidgetItem(QString::number(_CSlist[i].getID())));
        ui->table_ComputerScientist->setColumnHidden(4,true);//Hide our ID column
    }
}

void ShowList::printComputerList()
{
    // Display computersList
    ui->table_Computer->setRowCount(_computerList.size());
    ui->table_Computer->setColumnCount(5);
    for(size_t j = 0; j < _computerList.size(); j++)
    {
        ui->table_Computer->setItem(j, 0, new QTableWidgetItem(QString::fromStdString(_computerList[j].getName())));
        ui->table_Computer->setItem(j, 1, new QTableWidgetItem(QString::fromStdString(_computerList[j].getType())));
        ui->table_Computer->setItem(j, 2, new QTableWidgetItem(QString::number(_computerList[j].getDesignYear())));
        int buildYear = _computerList[j].getBuildYear();
        if(buildYear == constants::NEVER_BUILT)
        {
            ui->table_Computer->setItem(j, 3, new QTableWidgetItem("Computer was not built"));
        }
        else
        {
            ui->table_Computer->setItem(j, 3, new QTableWidgetItem(QString::number(_computerList[j].getBuildYear())));
        }
        ui->table_Computer->setItem(j, 4, new QTableWidgetItem(QString::number(_computerList[j].getID())));
        ui->table_Computer->setColumnHidden(4,true);//Hide our ID column
    }
}

ShowList::~ShowList()
{
    delete ui;
}

void ShowList::on_Button_Delete_clicked()
{
    this->setResult(QDialog::Accepted);
    if(_removeComputerOrScientist == constants::COMPUTER)
    {
        _idToRemove = _computerList[_row].getID();
    }
    else
    {
        _idToRemove = _CSlist[_row].getID();
    }
}

//If we switched tabs
void ShowList::on_tabWidget_scientist_currentChanged()
{
    ui->Button_Delete->setEnabled(false);
}

void ShowList::on_table_ComputerScientist_doubleClicked(const QModelIndex &index)
{
     _personToSend = getPersonFromID(_idForMoreInfo);
    _csMoreInfo.setComputerScientist(_personToSend);
    _csMoreInfo.setVectorOfComputersConnectedToScientist(getComputersFromCSid(_idForMoreInfo));
    _csMoreInfo.setModal(true);
    _csMoreInfo.exec();
}

void ShowList::on_table_Computer_cellClicked(int row)
{
    ui->Button_Delete->setEnabled(true);
    _removeComputerOrScientist = constants::COMPUTER;
    _row = row;
    _idForMoreInfo = ui->table_Computer->item(row,4)->text().toInt();
}

void ShowList::on_table_ComputerScientist_cellClicked(int row)
{
    _idForMoreInfo = ui->table_ComputerScientist->item(row,4)->text().toInt();
    ui->Button_Delete->setEnabled(true);
    _removeComputerOrScientist = constants::COMPUTER_SCIENTIST;
    _row = row;
}

void ShowList::on_table_Computer_doubleClicked()
{
   _compMoreInfo.setComputer(getComputerFromID(_idForMoreInfo));
   _compMoreInfo.setComputerCreators(getCSfromCompID(_idForMoreInfo));
   _compMoreInfo.setModal(true);
   _compMoreInfo.exec();
}

CSPerson ShowList::getPersonFromID(int id)
{
    for(unsigned int i = 0; i < _CSlist.size(); i++)
    {
        if (_CSlist[i].getID() == id)
        {
            return _CSlist[i];
        }
    }
}

Computer ShowList::getComputerFromID(int id)
{
    for(unsigned int i = 0; i < _computerList.size(); i++)
    {
        if (_computerList[i].getID() == id)
        {
            return _computerList[i];
        }
    }
}

vector<Computer> ShowList::getComputersFromCSid(int id)
{
    vector<Computer> returnValue;
    for(unsigned int i = 0; i < _computerCSconnection.size(); i++)
    {
        if(_computerCSconnection[i].getCSid() == id)
        {
            returnValue.push_back(getComputerFromID(_computerCSconnection[i].getCompID()));
        }
    }
    return returnValue;
}

vector<CSPerson> ShowList::getCSfromCompID(int id)
{
    vector<CSPerson> returnValue;
    for(unsigned int i = 0; i < _computerCSconnection.size(); i++)
    {
        if(_computerCSconnection[i].getCompID() == id)
        {
            returnValue.push_back(getPersonFromID(_computerCSconnection[i].getCSid()));
        }
    }
    return returnValue;
}
