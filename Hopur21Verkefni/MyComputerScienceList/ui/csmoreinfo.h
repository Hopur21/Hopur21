#ifndef CSMOREINFO_H
#define CSMOREINFO_H
#include "models/csperson.h"
#include "models/computer.h"

namespace Ui {
class CSMoreInfo;
}

class CSMoreInfo : public QDialog
{
    Q_OBJECT

    public:
        explicit CSMoreInfo(QWidget *parent = 0);
        void setComputerScientist(CSPerson myPerson);
        void setVectorOfComputersConnectedToScientist(vector<Computer> connectedComputers);
        ~CSMoreInfo();

    private slots:
        void on_pushButton_close_clicked();

    private:
        CSPerson _myPerson;
        Ui::CSMoreInfo *ui;
        vector<Computer> _computersConnectedToScientist;
        void setDataInBoxes();
        void loadImage();
        void addComputerstoCS();

};

#endif // CSMOREINFO_H
