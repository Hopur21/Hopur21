#ifndef ADDCOMPUTERSCIENTIST_H
#define ADDCOMPUTERSCIENTIST_H

#include <QDialog>

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

private:
    Ui::AddComputerScientist *ui;
};

#endif // ADDCOMPUTERSCIENTIST_H
