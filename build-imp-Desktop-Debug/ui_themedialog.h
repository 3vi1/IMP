/********************************************************************************
** Form generated from reading UI file 'themedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMEDIALOG_H
#define UI_THEMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
            ThemeDialog->setObjectName(QStringLiteral("ThemeDialog"));
        ThemeDialog->resize(259, 90);
        gridLayout = new QGridLayout(ThemeDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ThemeDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameEdit = new QLineEdit(ThemeDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ThemeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        ThemeDialog->setWindowTitle(QApplication::translate("ThemeDialog", "Save As...", Q_NULLPTR));
        label->setText(QApplication::translate("ThemeDialog", "Theme name:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ThemeDialog: public Ui_ThemeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEDIALOG_H
