#ifndef ADDTYPE_H
#define ADDTYPE_H
#include "models/computertype.h"
#include <vector>
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
    void clearFields();
    void resetData();
    void setTypes(std::vector<ComputerType> compTypes){_compTypes = compTypes;}
    std::string getTypeName(){return _newTypeName;}

private slots:
    void on_button_Save_Type_clicked();
    void on_button_clear_fields_clicked();

private:
    Ui::AddType *ui;
    std::vector<ComputerType> _compTypes;
    std::string _newTypeName;

    bool typeAlreadyExist(std::string typeName);
};

#endif // ADDTYPE_H
