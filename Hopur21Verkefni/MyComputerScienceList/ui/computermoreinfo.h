#ifndef COMPUTERMOREINFO_H
#define COMPUTERMOREINFO_H

#include <QMainWindow>

namespace Ui {
class ComputerMoreInfo;
}

class ComputerMoreInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit ComputerMoreInfo(QWidget *parent = 0);
    ~ComputerMoreInfo();

private:
    Ui::ComputerMoreInfo *ui;
};

#endif // COMPUTERMOREINFO_H
