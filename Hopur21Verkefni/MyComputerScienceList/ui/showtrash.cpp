#include "showtrash.h"
#include "ui_showtrash.h"

ShowTrash::ShowTrash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTrash)
{
    ui->setupUi(this);
}
ShowTrash::~ShowTrash()
{
    delete ui;
}
void ShowTrash::setTrashList(vector<CSPerson> compScientistsTrash, vector<Computer> computerTrashList)
{
    //Display computerScientistTrash
    ui->table_trashComputerScientist->setRowCount(compScientistsTrash.size());
    ui->table_trashComputerScientist->setColumnCount(4);
    for(size_t i = 0; i < compScientistsTrash.size(); i++)
    {

        ui->table_trashComputerScientist->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(compScientistsTrash[i].getName())));
        ui->table_trashComputerScientist->setItem(i, 1, new QTableWidgetItem(QString::number(compScientistsTrash[i].getAge())));
        ui->table_trashComputerScientist->setItem(i, 2, new QTableWidgetItem(QString::number(compScientistsTrash[i].getBirthYear())));
        ui->table_trashComputerScientist->setItem(i, 3, new QTableWidgetItem(QString::number(compScientistsTrash[i].getPassedAwayYear())));
    }

    // Display computersTrash
    ui->table_trashComputer->setRowCount(computerTrashList.size());
    ui->table_trashComputer->setColumnCount(4);
    for(size_t j = 0; j < computerTrashList.size(); j++)
    {

        ui->table_trashComputer->setItem(j, 0, new QTableWidgetItem(QString::fromStdString(computerTrashList[j].getName())));
        ui->table_trashComputer->setItem(j, 1, new QTableWidgetItem(QString::fromStdString(computerTrashList[j].getType())));
        ui->table_trashComputer->setItem(j, 2, new QTableWidgetItem(QString::number(computerTrashList[j].getDesignYear())));
        ui->table_trashComputer->setItem(j, 3, new QTableWidgetItem(QString::number(computerTrashList[j].getBuildYear())));
    }
}


