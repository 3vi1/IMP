#ifndef CUSTOMIZATIONDIALOG_H
#define CUSTOMIZATIONDIALOG_H

#include <QDialog>

namespace Ui {
class CustomizationDialog;
}

class CustomizationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomizationDialog(QWidget *parent = 0);
    ~CustomizationDialog();

    qreal xValue();
    qreal yValue();
    qreal zValue();

    void setXValue(qreal d);
    void setYValue(qreal d);
    void setZValue(qreal d);


private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CustomizationDialog *ui;
};

#endif // CUSTOMIZATIONDIALOG_H
