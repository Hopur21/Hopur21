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
    //displayScientists();
}
void ShowList::setList(vector<CSPerson> compScientistsList, vector<Computer> computerList)
{
    //Display computerScientistTrash
    ui->table_computerScientist_2->setRowCount(compScientistsList.size());
    ui->table_computerScientist_2->setColumnCount(4);
    for(size_t i = 0; i < compScientistsList.size(); i++)
    {

        ui->table_computerScientist_2->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(compScientistsList[i].getName())));
        ui->table_computerScientist_2->setItem(i, 1, new QTableWidgetItem(QString::number(compScientistsList[i].getAge())));
        ui->table_computerScientist_2->setItem(i, 2, new QTableWidgetItem(QString::number(compScientistsList[i].getBirthYear())));
        ui->table_computerScientist_2->setItem(i, 3, new QTableWidgetItem(QString::number(compScientistsList[i].getPassedAwayYear())));
    }

    // Display computersTrash
    ui->table_computer_2->setRowCount(computerList.size());
    ui->table_computer_2->setColumnCount(4);
    for(size_t j = 0; j < computerList.size(); j++)
    {

        ui->table_computer_2->setItem(j, 0, new QTableWidgetItem(QString::fromStdString(computerList[j].getName())));
        ui->table_computer_2->setItem(j, 1, new QTableWidgetItem(QString::fromStdString(computerList[j].getType())));
        ui->table_computer_2->setItem(j, 2, new QTableWidgetItem(QString::number(computerList[j].getDesignYear())));
        ui->table_computer_2->setItem(j, 3, new QTableWidgetItem(QString::number(computerList[j].getBuildYear())));
    }
}


ShowList::~ShowList()
{
    delete ui;
}
