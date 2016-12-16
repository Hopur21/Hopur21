#ifndef COMPMOREINFO_H
#define COMPMOREINFO_H

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

private:
    Ui::compmoreinfo *ui;
};

#endif // COMPMOREINFO_H
