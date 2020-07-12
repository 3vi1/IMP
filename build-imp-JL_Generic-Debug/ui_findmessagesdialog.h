/********************************************************************************
** Form generated from reading UI file 'findmessagesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDMESSAGESDIALOG_H
#define UI_FINDMESSAGESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_FindMessagesDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *containsEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FindMessagesDialog)
    {
        if (FindMessagesDialog->objectName().isEmpty())
            FindMessagesDialog->setObjectName(QString::fromUtf8("FindMessagesDialog"));
        FindMessagesDialog->resize(400, 85);
        gridLayout = new QGridLayout(FindMessagesDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(FindMessagesDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        containsEdit = new QLineEdit(FindMessagesDialog);
        containsEdit->setObjectName(QString::fromUtf8("containsEdit"));

        gridLayout->addWidget(containsEdit, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(FindMessagesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(FindMessagesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FindMessagesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FindMessagesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FindMessagesDialog);
    } // setupUi

    void retranslateUi(QDialog *FindMessagesDialog)
    {
        FindMessagesDialog->setWindowTitle(QApplication::translate("FindMessagesDialog", "Find Messages", nullptr));
        label->setText(QApplication::translate("FindMessagesDialog", "Contains:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindMessagesDialog: public Ui_FindMessagesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDMESSAGESDIALOG_H
