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

    // Alternatively, load an image file directly into a QByteArray
    /*QFile file("test.jpg");
    if (file.open(QIODevice::ReadOnly))
    {
        qDebug() << "nadi að opna file";
    }
    QByteArray inByteArray = myPerson.getImage();

       QPixmap outPixmap = QPixmap();
       outPixmap.loadFromData( inByteArray );*/

       /*
       ui->showPicLabel->setPixmap(outPixmap);
       ui->showPicLabel->setScaledContents(true);
       ui->showPicLabel->show();
    */


       /* To read from files
      QFile file("test.jpg");
      if (file.open(QIODevice::ReadOnly))
      {
          qDebug() << "nadi að opna file";
          QByteArray inByteArray = file.readAll();

      }


      vector<CSPerson> tempList;
      tempList = _service.getComputerScientistList();
      _csMoreInfo.setModal(true);
      _csMoreInfo.setComputerScientist(tempList[0]);
      _csMoreInfo.exec();

      */

       /*
       ui->label_title->setText(QString("<h2>%1</h2>").arg(QString::fromStdString(car.toString())));
       QPixmap pixmap(QString::fromStdString(car.getImagePath()));
       ui->label_image->setPixmap(pixmap);
       ui->label_image->setScaledContents(true);
       */






}
