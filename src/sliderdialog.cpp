#include "sliderdialog.h"
#include "ui_sliderdialog.h"

SliderDialog::SliderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SliderDialog)
{
    ui->setupUi(this);
}

SliderDialog::~SliderDialog()
{
    delete ui;
}

void SliderDialog::on_horizontalSlider_valueChanged(int value)
{
    ui->labelValue->setText(QString::number(value/divisor, 'f', 2));
}

int SliderDialog::value()
{
    return ui->horizontalSlider->value();
}

void SliderDialog::setUnit(QString s)
{
    ui->labelUnit->setText(s);
}

void SliderDialog::setMax(int value)
{
    ui->horizontalSlider->setMaximum(value);
    divisor = value;
}

void SliderDialog::setMin(int value)
{
    ui->horizontalSlider->setMinimum(value);
}

void SliderDialog::setValue(int value)
{
    on_horizontalSlider_valueChanged(value);
    ui->horizontalSlider->setValue(value);
}

void SliderDialog::on_buttonBox_accepted()
{
    this->close();
    this->setResult(QDialog::Accepted);
}

void SliderDialog::on_buttonBox_rejected()
{
    this->close();
    this->setResult(QDialog::Rejected);
}
