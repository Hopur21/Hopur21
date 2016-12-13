#include "showtrash.h"
#include "ui_showtrash.h"

ShowTrash::ShowTrash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTrash)
{
    ui->setupUi(this);
}

ShowTrash::~ShowTrash()
{
    delete ui;
}
