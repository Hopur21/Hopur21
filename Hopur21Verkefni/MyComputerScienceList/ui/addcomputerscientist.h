#ifndef ADDCOMPUTERSCIENTIST_H
#define ADDCOMPUTERSCIENTIST_H
#include "models/csperson.h"
#include <QDialog>
#include <QIntValidator>
#include <qdebug.h>

namespace Ui {
class AddComputerScientist;
}

class AddComputerScientist : public QDialog
{
    Q_OBJECT

    //AddComputerScientist(QWidget *parent):QDialog(parent),ui(new Ui::AddComputerScientist);
public:
    explicit AddComputerScientist(QWidget *parent = 0);
    ~AddComputerScientist();

private slots:
    void on_pushButton_Addscientist_save_clicked();



    void on_checkBox_Addscientist_isPersonAlive_toggled(bool checked);

private:
    Ui::AddComputerScientist *ui;
    CSPerson _newPerson;
    QIntValidator *yearValidator;
    CSPerson getPerson() { return _newPerson;}
};

#endif // ADDCOMPUTERSCIENTIST_H
