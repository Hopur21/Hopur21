#include "showlist.h"
#include "ui_showlist.h"
#include "models/csperson.h"
#include "services/service.h"

ShowList::ShowList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowList)
{
    ui->setupUi(this);
    //displayScientists();
}

/*
void ShowList::displayScientists()
{
    vector<CSPerson> CSPersons = service.getComputerScientistList("name", true);
    displayScientists(CSPersons);
}

void ShowList::displayScientists(std::vector<CSPerson> CSPersons)
{
    ui->list_CSPersons->clear();

    for (size_t i = 0; i < CSPersons.size(); i++)
    {
        CSPerson currentScientist = CSPersons.at(i);

        ui->tabWidget_scientist->addItem(QString::fromStdString(currentScientist.getName()));
    }
}
*/

ShowList::~ShowList()
{
    delete ui;
}
