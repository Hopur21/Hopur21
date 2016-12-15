#ifndef ADDTYPE_H
#define ADDTYPE_H
#include "models/computertype.h"

#include <QDialog>

namespace Ui {
class AddType;
}

class AddType : public QDialog
{
    Q_OBJECT

public:
    explicit AddType(QWidget *parent = 0);
    ~AddType();

    int getMyIntValue() {return myIntValue;}

private slots:
    void on_button_Save_Type_clicked();

    void on_button_clear_fields_clicked();

private:
    Ui::AddType *ui;
    ComputerType _newType;
    ComputerType getType() {return _newType;}

    int myIntValue;
};

#endif // ADDTYPE_H
