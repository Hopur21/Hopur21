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
void ShowTrash::setComputerScientistTrashList(vector<CSPerson> compScientistsTrash)
{
        ui->table_trashComputerScientist->setRowCount(compScientistsTrash.size());
        ui->table_trashComputerScientist->setColumnCount(4);
        for(size_t i = 0; i < compScientistsTrash.size(); i++)
        {

            ui->table_trashComputerScientist->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(compScientistsTrash[i].getName())));
            ui->table_trashComputerScientist->setItem(i, 1, new QTableWidgetItem(QString::number(compScientistsTrash[i].getAge())));
            ui->table_trashComputerScientist->setItem(i, 2, new QTableWidgetItem(QString::number(compScientistsTrash[i].getBirthYear())));
            ui->table_trashComputerScientist->setItem(i, 3, new QTableWidgetItem(QString::number(compScientistsTrash[i].getPassedAwayYear())));
        }
        /*
        // Display computersTrash
        vector<Computer> computerList = _service.getComputerList();
        ui->table_computer->setRowCount(computerList.size());
        ui->table_computer->setColumnCount(4);
        for(size_t j = 0; j < computerList.size(); j++)
        {

            ui->table_computer->setItem(j, 0, new QTableWidgetItem(QString::fromStdString(computerList[j].getName())));
            ui->table_computer->setItem(j, 1, new QTableWidgetItem(QString::fromStdString(computerList[j].getType())));
            ui->table_computer->setItem(j, 2, new QTableWidgetItem(QString::number(computerList[j].getDesignYear())));
            ui->table_computer->setItem(j, 3, new QTableWidgetItem(QString::number(computerList[j].getBuildYear())));
        }

    }*/
}

void ShowTrash::listTrashCan()
{
    // Display scientistsTrash
    //vector<CSPerson> compScientistsTrash = _service.getComputerScientistTrash();


    /*ui->table_trashComputerScientist->setRowCount(compScientistsTrash.size());
    ui->table_trashComputerScientist->setColumnCount(4);
    for(size_t i = 0; i < compScientistsTrash.size(); i++)
    {

        ui->table_trashComputerScientist->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(compScientistsTrash[i].getName())));
        ui->table_trashComputerScientist->setItem(i, 1, new QTableWidgetItem(QString::number(compScientistsTrash[i].getAge())));
        ui->table_trashComputerScientist->setItem(i, 2, new QTableWidgetItem(QString::number(compScientistsTrash[i].getBirthYear())));
        ui->table_trashComputerScientist->setItem(i, 3, new QTableWidgetItem(QString::number(compScientistsTrash[i].getPassedAwayYear())));
    }
    /*
    // Display computersTrash
    vector<Computer> computerList = _service.getComputerList();
    ui->table_computer->setRowCount(computerList.size());
    ui->table_computer->setColumnCount(4);
    for(size_t j = 0; j < computerList.size(); j++)
    {

        ui->table_computer->setItem(j, 0, new QTableWidgetItem(QString::fromStdString(computerList[j].getName())));
        ui->table_computer->setItem(j, 1, new QTableWidgetItem(QString::fromStdString(computerList[j].getType())));
        ui->table_computer->setItem(j, 2, new QTableWidgetItem(QString::number(computerList[j].getDesignYear())));
        ui->table_computer->setItem(j, 3, new QTableWidgetItem(QString::number(computerList[j].getBuildYear())));
    }
*/
}


