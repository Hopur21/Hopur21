#ifndef ADDCOMP_H
#define ADDCOMP_H

#include <QDialog>

namespace Ui {
class AddComp;
}

class AddComp : public QDialog
{
    Q_OBJECT

public:
    explicit AddComp(QWidget *parent = 0);
    ~AddComp();

private:
    Ui::AddComp *ui;
};

#endif // ADDCOMP_H
