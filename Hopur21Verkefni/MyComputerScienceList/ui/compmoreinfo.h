#ifndef COMPMOREINFO_H
#define COMPMOREINFO_H
#include "models/computer.h"

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::compmoreinfo *ui;
    Computer _myComputer;
    void loadImage();
    void setDataInBoxes();
};

#endif // COMPMOREINFO_H
