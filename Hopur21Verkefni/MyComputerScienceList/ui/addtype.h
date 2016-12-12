#ifndef ADDTYPE_H
#define ADDTYPE_H

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

private:
    Ui::AddType *ui;
};

#endif // ADDTYPE_H
