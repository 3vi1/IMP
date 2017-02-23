#include "customizationdialog.h"
#include "ui_customizationdialog.h"

CustomizationDialog::CustomizationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomizationDialog)
{
    ui->setupUi(this);
}

CustomizationDialog::~CustomizationDialog()
{
    delete ui;
}

qreal CustomizationDialog::xValue()
{
    return ui->xSpin->value();
}

qreal CustomizationDialog::yValue()
{
    return ui->ySpin->value();
}

qreal CustomizationDialog::zValue()
{
    return ui->zSpin->value();
}

void CustomizationDialog::setXValue(qreal i)
{
    ui->xSpin->setValue(i);
}

void CustomizationDialog::setYValue(qreal i)
{
    ui->ySpin->setValue(i);
}

void CustomizationDialog::setZValue(qreal i)
{
    ui->zSpin->setValue(i);
}

void CustomizationDialog::on_buttonBox_accepted()
{
    this->close();
    this->setResult(QDialog::Accepted);
}

void CustomizationDialog::on_buttonBox_rejected()
{
    this->close();
    this->setResult(QDialog::Rejected);
}
