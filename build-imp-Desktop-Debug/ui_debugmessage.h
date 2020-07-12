/********************************************************************************
** Form generated from reading UI file 'debugmessage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGMESSAGE_H
#define UI_DEBUGMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DebugMessage
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_pilot;
    QLabel *label;
    QLineEdit *lineEdit_message;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *DebugMessage)
    {
        if (DebugMessage->objectName().isEmpty())
            DebugMessage->setObjectName(QStringLiteral("DebugMessage"));
        DebugMessage->resize(470, 101);
        gridLayout = new QGridLayout(DebugMessage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(DebugMessage);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_pilot = new QLineEdit(DebugMessage);
        lineEdit_pilot->setObjectName(QStringLiteral("lineEdit_pilot"));

        gridLayout->addWidget(lineEdit_pilot, 1, 0, 1, 1);

        label = new QLabel(DebugMessage);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        lineEdit_message = new QLineEdit(DebugMessage);
        lineEdit_message->setObjectName(QStringLiteral("lineEdit_message"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_message->sizePolicy().hasHeightForWidth());
        lineEdit_message->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit_message, 1, 2, 1, 2);

        horizontalSpacer = new QSpacerItem(193, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        pushButton = new QPushButton(DebugMessage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton, 2, 3, 1, 1);


        retranslateUi(DebugMessage);

        QMetaObject::connectSlotsByName(DebugMessage);
    } // setupUi

    void retranslateUi(QDialog *DebugMessage)
    {
        DebugMessage->setWindowTitle(QApplication::translate("DebugMessage", "Debugging", Q_NULLPTR));
        label_2->setText(QApplication::translate("DebugMessage", "Test Message:", Q_NULLPTR));
        lineEdit_pilot->setText(QApplication::translate("DebugMessage", "Test Pilot Name", Q_NULLPTR));
        label->setText(QApplication::translate("DebugMessage", ">", Q_NULLPTR));
        lineEdit_message->setText(QApplication::translate("DebugMessage", "Test message here", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DebugMessage", "&Inject", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DebugMessage: public Ui_DebugMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGMESSAGE_H
