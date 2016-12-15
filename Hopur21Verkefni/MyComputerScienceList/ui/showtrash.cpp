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
    _computerList = computerTrashList;
    _CSList = compScientistsTrash;
    printComputerScientistTrash();
    printComputerTrash();
}
void ShowTrash::printComputerScientistTrash()
{
    ui->table_trashComputerScientist->setRowCount(_CSList.size());
    ui->table_trashComputerScientist->setColumnCount(4);
    for(size_t i = 0; i < _CSList.size(); i++)
    {

        ui->table_trashComputerScientist->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(_CSList[i].getName())));
        ui->table_trashComputerScientist->setItem(i, 1, new QTableWidgetItem(QString::number(_CSList[i].getAge())));
        ui->table_trashComputerScientist->setItem(i, 2, new QTableWidgetItem(QString::number(_CSList[i].getBirthYear())));
        ui->table_trashComputerScientist->setItem(i, 3, new QTableWidgetItem(QString::number(_CSList[i].getPassedAwayYear())));
    }
}

void ShowTrash::printComputerTrash()
{
    ui->table_trashComputer->setRowCount(_computerList.size());
    ui->table_trashComputer->setColumnCount(4);
    for(size_t j = 0; j < _computerList.size(); j++)
    {
        ui->table_trashComputer->setItem(j, 0, new QTableWidgetItem(QString::fromStdString(_computerList[j].getName())));
        ui->table_trashComputer->setItem(j, 1, new QTableWidgetItem(QString::fromStdString(_computerList[j].getType())));
        ui->table_trashComputer->setItem(j, 2, new QTableWidgetItem(QString::number(_computerList[j].getDesignYear())));
        ui->table_trashComputer->setItem(j, 3, new QTableWidgetItem(QString::number(_computerList[j].getBuildYear())));
    }
}
