#include "themecustomizer.h"
#include "ui_themecustomizer.h"

ThemeCustomizer::ThemeCustomizer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThemeCustomizer)
{
    ui->setupUi(this);
}

ThemeCustomizer::~ThemeCustomizer()
{
    delete ui;
}
