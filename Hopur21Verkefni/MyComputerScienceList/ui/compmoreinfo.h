#ifndef COMPMOREINFO_H
#define COMPMOREINFO_H
#include "models/computer.h"
#include "models/csperson.h"

//Was accidentally created with only lowercase, we got many conflicts trying to fix it.

#include <QDialog>

namespace Ui {
class compmoreinfo;
}

class compmoreinfo : public QDialog
{
    Q_OBJECT

    public:
        explicit compmoreinfo(QWidget *parent = 0);
        ~compmoreinfo();
        void setComputer(Computer myComputer);
        void setComputerCreators(vector<CSPerson> myCreators);

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::compmoreinfo *ui;
        Computer _myComputer;
        vector<CSPerson> _myCreators;
        void loadImage();
        void setDataInBoxes();
        void showCreatorsofComputer();
};

#endif // COMPMOREINFO_H
