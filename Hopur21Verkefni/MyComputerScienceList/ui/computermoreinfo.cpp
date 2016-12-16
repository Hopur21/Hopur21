#include "computermoreinfo.h"
#include "ui_computermoreinfo.h"

ComputerMoreInfo::ComputerMoreInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ComputerMoreInfo)
{
    ui->setupUi(this);
}

ComputerMoreInfo::~ComputerMoreInfo()
{
    delete ui;
}
