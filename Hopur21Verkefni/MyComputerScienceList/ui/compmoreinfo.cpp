#include "compmoreinfo.h"
#include "ui_compmoreinfo.h"

compmoreinfo::compmoreinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compmoreinfo)
{
    ui->setupUi(this);
}

compmoreinfo::~compmoreinfo()
{
    delete ui;
}

