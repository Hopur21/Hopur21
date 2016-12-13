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

void AddComputerScientist::on_pushButton_Addscientist_save_clicked()
{
    QString name = "";
    bool isAlive;
    QString gender;
    QString comment;
    QString birthYear;
    QString deathYear;

    // getCurrent year   (year is the currentyear)
    time_t timeNow = time(0);
    tm *ltm = localtime(&timeNow);
    int year = ltm->tm_year + 1900;


    // Taka inn mynd

    name = ui->lineEdit_Addscientist_name->text();
    qDebug() << name;
    birthYear = ui->lineEdit_Addscientist_yearofbirth->text();
    isAlive = ui->checkBox_Addscientist_isPersonAlive->isChecked();

    if(isAlive == false)
    {
        deathYear = ui->lineEdit_Addscientist_deathYear->selectedText();
    }

    bool saveStatus = true;

    // If name is an empty string
    if(name == "")
    {
        saveStatus = false;
    }
    // QIntValidator á eftir að skoða betur
    //ui->lineEdit_Addscientist_yearofbirth->setValidator( new QIntValidator(0, year, this) );


    CSPerson createdPerson;
    _newPerson = createdPerson;

    // 1 denotes success 0 denotes failure
    setResult(QDialog::Accepted);


}
