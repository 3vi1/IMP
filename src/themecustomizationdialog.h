#ifndef THEMECUSTOMIZATIONDIALOG_H
#define THEMECUSTOMIZATIONDIALOG_H

#include <QDialog>

namespace Ui {
class ThemeCustomizationDialog;
}

class ThemeCustomizationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThemeCustomizationDialog(QWidget *parent = 0);
    ~ThemeCustomizationDialog();

private:
    Ui::ThemeCustomizationDialog *ui;
};

#endif // THEMECUSTOMIZATIONDIALOG_H
