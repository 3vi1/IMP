#include "debugmessage.h"
#include "ui_debugmessage.h"

#include <QDateTime>

DebugMessage::DebugMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DebugMessage)
{
    ui->setupUi(this);
}

DebugMessage::~DebugMessage()
{
    delete ui;
}

void DebugMessage::on_pushButton_clicked()
{
    QString pilot = ui->lineEdit_pilot->text();
    QString message = ui->lineEdit_message->text();

    // [ 2016.07.24 16:27:15 ]
    QString date = QDateTime::currentDateTimeUtc().toString("[ yyyy.MM.dd HH:mm:ss ] ");
    emit testMessage(date + pilot + " > " + message);
}
