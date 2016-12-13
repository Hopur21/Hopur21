#ifndef ADDTYPEE_H
#define ADDTYPEE_H

#include <QDialog>

namespace Ui {
class AddTypee;
}

class AddTypee : public QDialog
{
    Q_OBJECT

public:
    explicit AddTypee(QWidget *parent = 0);
    ~AddTypee();

private:
    Ui::AddTypee *ui;
};

#endif // ADDTYPEE_H
