#include "themecustomizationdialog.h"
#include "ui_themecustomizationdialog.h"

ThemeCustomizationDialog::ThemeCustomizationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThemeCustomizationDialog)
{
    ui->setupUi(this);
}

ThemeCustomizationDialog::~ThemeCustomizationDialog()
{
    delete ui;
}
