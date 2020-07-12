/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
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
            FindDialog->setObjectName(QStringLiteral("FindDialog"));
        FindDialog->resize(249, 42);
        QIcon icon;
        icon.addFile(QStringLiteral(":/graphics/impicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FindDialog->setWindowIcon(icon);
        pushButton = new QPushButton(FindDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 9, 61, 26));
        findCombo = new QComboBox(FindDialog);
        findCombo->setObjectName(QStringLiteral("findCombo"));
        findCombo->setGeometry(QRect(20, 10, 141, 24));
        findCombo->setEditable(true);
        QWidget::setTabOrder(findCombo, pushButton);

        retranslateUi(FindDialog);

        findCombo->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QApplication::translate("FindDialog", "Find System", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FindDialog", "Find", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
