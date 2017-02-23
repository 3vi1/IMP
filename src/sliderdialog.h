#ifndef OPACITYDIALOG_H
#define OPACITYDIALOG_H

#include <QDialog>

namespace Ui {
class SliderDialog;
}

class SliderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SliderDialog(QWidget *parent = 0);
    ~SliderDialog();

    int value();
    void setValue(int value);
    void setMin(int min);
    void setMax(int max);
    void setDivisor(int d){divisor = d;}
    void setUnit(QString s);

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::SliderDialog *ui;
    qreal divisor = 100.0;
};

#endif // OPACITYDIALOG_H
