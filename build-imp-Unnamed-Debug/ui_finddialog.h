/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QPushButton *pushButton;
    QComboBox *findCombo;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QString::fromUtf8("FindDialog"));
        FindDialog->resize(249, 42);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graphics/impicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FindDialog->setWindowIcon(icon);
        pushButton = new QPushButton(FindDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 9, 61, 26));
        findCombo = new QComboBox(FindDialog);
        findCombo->setObjectName(QString::fromUtf8("findCombo"));
        findCombo->setGeometry(QRect(20, 10, 141, 24));
        findCombo->setEditable(true);
        QWidget::setTabOrder(findCombo, pushButton);

        retranslateUi(FindDialog);

        findCombo->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "Find System", nullptr));
        pushButton->setText(QCoreApplication::translate("FindDialog", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
