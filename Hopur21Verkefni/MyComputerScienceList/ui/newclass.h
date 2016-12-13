#ifndef NEWCLASS_H
#define NEWCLASS_H

#include <QDialog>

namespace Ui {
class NewClass;
}

class NewClass : public QDialog
{
    Q_OBJECT

public:
    explicit NewClass(QWidget *parent = 0);
    ~NewClass();

private:
    Ui::NewClass *ui;
};

#endif // NEWCLASS_H
