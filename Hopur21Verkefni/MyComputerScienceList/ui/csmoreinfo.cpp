#include "csmoreinfo.h"
#include "ui_csmoreinfo.h"

CSMoreInfo::CSMoreInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSMoreInfo)
{
    ui->setupUi(this);
}

CSMoreInfo::~CSMoreInfo()
{
    delete ui;
}
void CSMoreInfo::setComputerScientist(CSPerson myPerson)
{
    ui->label_tempNafn->setText(QString::fromStdString(myPerson.getName()));
}
