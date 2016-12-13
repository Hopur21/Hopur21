#include "addcomputerscientist.h"
#include "ui_addcomputerscientist.h"

AddComputerScientist::AddComputerScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerScientist)
{
    ui->setupUi(this);
}

AddComputerScientist::~AddComputerScientist()
{
    delete ui;
}
