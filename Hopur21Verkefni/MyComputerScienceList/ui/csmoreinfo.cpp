#include "csmoreinfo.h"
#include "ui_csmoreinfo.h"

CSMoreInfo::CSMoreInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSMoreInfo)
{
    ui->setupUi(this);
}

CSMoreInfo::~CSMoreInfo()
{
    delete ui;
}
void CSMoreInfo::setComputerScientist(CSPerson myPerson)
{
    ui->label_tempNafn->setText(QString::fromStdString(myPerson.getName()));

    // Alternatively, load an image file directly into a QByteArray
    QFile file("test.jpg");
    if (file.open(QIODevice::ReadOnly))
    {
        qDebug() << "nadi að opna file";
    }
    QByteArray inByteArray = myPerson.getImage();

       QPixmap outPixmap = QPixmap();
       outPixmap.loadFromData( inByteArray );

       ui->showPicLabel->setPixmap(outPixmap);
       ui->showPicLabel->setScaledContents(true);
       ui->showPicLabel->show();



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
