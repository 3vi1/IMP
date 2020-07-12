/********************************************************************************
** Form generated from reading UI file 'themedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMEDIALOG_H
#define UI_THEMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ThemeDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ThemeDialog)
    {
        if (ThemeDialog->objectName().isEmpty())
            ThemeDialog->setObjectName(QString::fromUtf8("ThemeDialog"));
        ThemeDialog->resize(259, 90);
        gridLayout = new QGridLayout(ThemeDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ThemeDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameEdit = new QLineEdit(ThemeDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ThemeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(ThemeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ThemeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ThemeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ThemeDialog);
    } // setupUi

    void retranslateUi(QDialog *ThemeDialog)
    {
        ThemeDialog->setWindowTitle(QCoreApplication::translate("ThemeDialog", "Save As...", nullptr));
        label->setText(QCoreApplication::translate("ThemeDialog", "Theme name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThemeDialog: public Ui_ThemeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEDIALOG_H
