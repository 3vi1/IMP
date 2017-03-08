#ifndef THEMECUSTOMIZATIONDIALOG_H
#define THEMECUSTOMIZATIONDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QGraphicsScene>

#include "theme.h"

namespace Ui {
class ThemeCustomizationDialog;
}

class ThemeCustomizationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThemeCustomizationDialog(QWidget *parent = 0);
    ~ThemeCustomizationDialog();

    void loadValues(Theme* theme);
    void sendChanges(Theme *theme);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_apply(bool checked);
    void on_buttonBox_rejected();
    void on_buttonBackColor_clicked();
    void on_buttonBackImage_clicked();

    void on_buttonFindImage_clicked();

    void on_buttonPilotImage_clicked();

    void on_buttonLineColor_clicked();

private:
    Ui::ThemeCustomizationDialog *ui;
    QGraphicsScene colorScene;
    Theme* m_theme = NULL;

    QPushButton* applyButton;
};

#endif // THEMECUSTOMIZATIONDIALOG_H
