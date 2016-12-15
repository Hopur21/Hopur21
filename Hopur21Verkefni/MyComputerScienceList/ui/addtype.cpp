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
    //If validation fails these are used
    bool canCreateType = true;

    //If validation fails this is set as false
    bool nameTypeFail = false;


    QString nameType = ui-> lineEdit_addComputerType->text();

    if(nameType == "")
    {
        canCreateType = false;
        nameTypeFail = true;
    }

    if(canCreateType)
    {
        ComputerType newType;
        _newType = newType;
        //_newType.getName(nameType.toStdString());
        this->setResult(QDialog::Accepted);

    }
    else
    {
        QString errorMessage = "Please enter a computer type!";
        ui->label_addTypeErrorField->setText("<span style = 'color : red>" + errorMessage+ "</span>");
        this->setResult(QDialog::Rejected);
    }
    //this->close();
    //this->setResult(QDialog::Accepted);
}

void AddType::on_button_clear_fields_clicked()
{
    this->close();
    this->setResult(QDialog::Rejected);
}
