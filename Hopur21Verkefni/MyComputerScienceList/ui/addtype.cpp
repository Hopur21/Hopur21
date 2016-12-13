#include "addtype.h"
#include "ui_addtype.h"

AddType::AddType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddType)
{
    ui->setupUi(this);
}

AddType::~AddType()
{
    delete ui;
}

void AddType::on_button_Save_Type_clicked()
{
    this->close();
    this->setResult(QDialog::Accepted);
}

void AddType::on_button_clear_fields_clicked()
{
    this->close();
    this->setResult(QDialog::Rejected);
}
