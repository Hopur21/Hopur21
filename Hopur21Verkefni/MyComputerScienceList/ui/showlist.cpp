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
    //streaches all columns to fit widget
    //ui->table_computerScientist_2->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    //streaches the name column
    //ui->table_computerScientist_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
}
void ShowList::setList(vector<CSPerson> compScientistsList, vector<Computer> computerList)
{
    _computerList = computerList;
    _CSlist = compScientistsList;
    printComputerList();
    printComputerScientistList();
}
void ShowList::printComputerScientistList()
{
    //Display computerScientistList
    ui->table_computerScientist_2->setRowCount(_CSlist.size());
    ui->table_computerScientist_2->setColumnCount(4);
    for(size_t i = 0; i < _CSlist.size(); i++)
    {

        ui->table_computerScientist_2->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(_CSlist[i].getName())));
        ui->table_computerScientist_2->setItem(i, 1, new QTableWidgetItem(QString::number(_CSlist[i].getAge())));
        ui->table_computerScientist_2->setItem(i, 2, new QTableWidgetItem(QString::number(_CSlist[i].getBirthYear())));
        ui->table_computerScientist_2->setItem(i, 3, new QTableWidgetItem(QString::number(_CSlist[i].getPassedAwayYear())));
    }
}
void ShowList::printComputerList()
{
    // Display computersList
    ui->table_computer_2->setRowCount(_computerList.size());
    ui->table_computer_2->setColumnCount(4);
    for(size_t j = 0; j < _computerList.size(); j++)
    {

        ui->table_computer_2->setItem(j, 0, new QTableWidgetItem(QString::fromStdString(_computerList[j].getName())));
        ui->table_computer_2->setItem(j, 1, new QTableWidgetItem(QString::fromStdString(_computerList[j].getType())));
        ui->table_computer_2->setItem(j, 2, new QTableWidgetItem(QString::number(_computerList[j].getDesignYear())));
        ui->table_computer_2->setItem(j, 3, new QTableWidgetItem(QString::number(_computerList[j].getBuildYear())));
    }
}

ShowList::~ShowList()
{
    delete ui;
}
