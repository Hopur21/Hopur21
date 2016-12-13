#include "addtypee.h"
#include "ui_addtypee.h"

AddTypee::AddTypee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTypee)
{
    ui->setupUi(this);
}

AddTypee::~AddTypee()
{
    delete ui;
}
