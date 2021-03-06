#include "csmoreinfo.h"
#include "ui_csmoreinfo.h"

CSMoreInfo::CSMoreInfo( QWidget *parent) : QDialog(parent), ui(new Ui::CSMoreInfo)
{
    ui->setupUi(this);
}

CSMoreInfo::~CSMoreInfo()
{
    delete ui;
}

void CSMoreInfo::setDataInBoxes()
{
    ui->plainTextEdit_aboutComment->setPlainText(QString::fromStdString(_myPerson.getComments()));
    ui->lineEdit_aboutName->setText(QString::fromStdString(_myPerson.getName()));
    ui->lineEdit_aboutYearOfBirth->setText(QString::number(_myPerson.getBirthYear()));
    ui->lineEdit_aboutYearOfDeath->setText(QString::number(_myPerson.getPassedAwayYear()));
    ui->lineEdit_aboutAge->setText(QString::number(_myPerson.getAge()));
    int ID = _myPerson.getID();

    //_computerCSconnection
    int yearOfDeath = _myPerson.getPassedAwayYear();

    if(yearOfDeath == constants::STILL_ALIVE)
    {
        ui->lineEdit_aboutYearOfDeath->setText("Still alive");
    }
    else
    {
        ui->lineEdit_aboutYearOfDeath->setText(QString::number(_myPerson.getPassedAwayYear()));
    }
    loadImage();
}

void CSMoreInfo::addComputerstoCS()
{
    ui->tableWidget_aboutRelations->setRowCount(_computersConnectedToScientist.size());
    ui->tableWidget_aboutRelations->setColumnCount(3);
    for(unsigned int i = 0; i < _computersConnectedToScientist.size(); i++)
    {
        ui->tableWidget_aboutRelations->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(_computersConnectedToScientist[i].getName())));
        ui->tableWidget_aboutRelations->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(_computersConnectedToScientist[i].getType())));
        ui->tableWidget_aboutRelations->setItem(i, 2, new QTableWidgetItem(QString::number(_computersConnectedToScientist[i].getDesignYear())));
    }


}

void CSMoreInfo::loadImage()
{
    QPixmap pixmap = QPixmap();
    pixmap.loadFromData( _myPerson.getImage() );
    QIcon buttonIcon(pixmap);
    ui->image_of_person_input->setIcon(buttonIcon);
}

void CSMoreInfo::setComputerScientist(CSPerson myPerson)
{
    _myPerson = myPerson;
    setDataInBoxes();
}

void CSMoreInfo::on_pushButton_close_clicked()
{
    this->close();
}

void CSMoreInfo::setVectorOfComputersConnectedToScientist(vector<Computer> connectedComputers)
{
    _computersConnectedToScientist.clear();
    _computersConnectedToScientist = connectedComputers;
    addComputerstoCS();
}

void CSMoreInfo::on_pushButton_2_clicked()
{

}
