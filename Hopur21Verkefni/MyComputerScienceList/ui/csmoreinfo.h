#ifndef CSMOREINFO_H
#define CSMOREINFO_H
#include "models/csperson.h"

#include <QDialog>

namespace Ui {
class CSMoreInfo;
}

class CSMoreInfo : public QDialog
{
    Q_OBJECT

public:
    explicit CSMoreInfo(QWidget *parent = 0);
    void setComputerScientist(CSPerson myPerson);
    ~CSMoreInfo();

private:
    CSPerson _myPerson;
    Ui::CSMoreInfo *ui;

};

#endif // CSMOREINFO_H
