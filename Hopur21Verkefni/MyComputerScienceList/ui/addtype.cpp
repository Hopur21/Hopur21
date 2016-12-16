#include "addtype.h"
#include "ui_addtype.h"
#include <QDebug>
#include <QString>

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


    QString nameType = ui->lineEdit_AddComputerType_Name->text();
    QString errorMessage = "";

    if(nameType == "")
    {
        canCreateType = false;
        nameTypeFail = true;
        errorMessage = "Please enter a computer type!";
    }
    else if(typeAlreadyExist(nameType.toStdString()))
    {
        canCreateType = false;
        errorMessage = "Computer type already exists!";
    }

    if(canCreateType)
    {
        _newTypeName = nameType.toStdString();
        this->setResult(QDialog::Accepted);
        clearFields();
    }
    else
    {
        ui->label_addTypeErrorField->setText("<span style = 'color : red'>" + errorMessage + "</span>");
        this->setResult(QDialog::Rejected);
    }
}

bool AddType::typeAlreadyExist(std::string typeName)
{

    for(unsigned int i = 0; i < _compTypes.size(); i++)
    {

        if(typeName == _compTypes[i].getName())
        {
            return true;
        }
    }
    return false;//If name is not in database
}

void AddType::on_button_Clear_Fields_Type_clicked()
{
    clearFields();
}
void AddType::clearFields()
{
    ui->lineEdit_AddComputerType_Name->clear();
}
void AddType::resetData()
{
    std::vector<ComputerType> compTypes;
    _compTypes = compTypes;
    _newTypeName = "";
}
