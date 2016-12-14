#include "addcomputerscientist.h"
#include "ui_addcomputerscientist.h"

AddComputerScientist::AddComputerScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerScientist)
{
    ui->setupUi(this);

    // getCurrent year   (year is the currentyear)
    time_t timeNow = time(0);
    tm *ltm = localtime(&timeNow);
    int year = ltm->tm_year + 1900;

    // Validation for year of birth & year of death
    QIntValidator *yearValidator = new QIntValidator(0,year);
    ui->lineEdit_Addscientist_yearofbirth->setValidator(yearValidator);
    ui->lineEdit_Addscientist_deathYear->setValidator(yearValidator);

}

AddComputerScientist::~AddComputerScientist()
{
    delete ui;
}

void AddComputerScientist::on_pushButton_Addscientist_save_clicked()
{
    // While loop conditions
    bool exitLoop;
    bool validInput;

    // Gender options
    bool male = false;
    bool female = false;
    bool other = false;

    QString name = "";
    // isAlive is connected to the checkbox
    bool isAlive;
    QString gender;
    QString comment;
    QString birthYear;
    QString deathYear;


    // Taka inn mynd


    bool canCreatePerson = true;


    name = ui->lineEdit_Addscientist_name->text();
    qDebug() << name;
    birthYear = ui->lineEdit_Addscientist_yearofbirth->text();
    qDebug() << birthYear;
    isAlive = ui->checkBox_Addscientist_isPersonAlive->isChecked();
    if(isAlive)
    {
        qDebug() << "This person is still alive";
    }
    else if(isAlive == false)
    {
        deathYear = ui->lineEdit_Addscientist_deathYear->selectedText();
        qDebug() << "This person died in the year" << deathYear;
    }

    // If name or birthYear are empty strings
    if(name == "" || birthYear == "")
    {
        canCreatePerson = false;
    }

    if(isAlive == false && deathYear == "")
    {
        canCreatePerson = false;
    }

    // 1 denotes success 0 denotes failure
    if(canCreatePerson == true)
    {
        CSPerson createdPerson;
        _newPerson = createdPerson;
        //setResult(QDialog::Accepted);
    }
    else
    {
        //setResult(QDialog::Rejected);
    }


}
