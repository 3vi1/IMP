/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *versionInfo;
    QDialogButtonBox *okayButton;
    QLabel *label_3;

    void setupUi(QDialog *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QString::fromUtf8("Info"));
        Info->setWindowModality(Qt::ApplicationModal);
        Info->resize(585, 604);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graphics/impicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Info->setWindowIcon(icon);
        Info->setWindowOpacity(1.000000000000000);
        Info->setAutoFillBackground(false);
        Info->setModal(true);
        gridLayout = new QGridLayout(Info);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalSpacer = new QSpacerItem(13, 13, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(Info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(300, 162));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/graphics/Imp.png")));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(13, 13, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        label = new QLabel(Info);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setWordWrap(true);
        label->setMargin(0);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        versionInfo = new QLabel(Info);
        versionInfo->setObjectName(QString::fromUtf8("versionInfo"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(versionInfo->sizePolicy().hasHeightForWidth());
        versionInfo->setSizePolicy(sizePolicy2);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        versionInfo->setFont(font);
        versionInfo->setTextFormat(Qt::RichText);
        versionInfo->setAlignment(Qt::AlignCenter);
        versionInfo->setWordWrap(true);

        gridLayout->addWidget(versionInfo, 2, 0, 1, 1);

        okayButton = new QDialogButtonBox(Info);
        okayButton->setObjectName(QString::fromUtf8("okayButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(okayButton->sizePolicy().hasHeightForWidth());
        okayButton->setSizePolicy(sizePolicy3);
        okayButton->setOrientation(Qt::Vertical);
        okayButton->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(okayButton, 5, 0, 1, 1);

        label_3 = new QLabel(Info);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);
        label_3->setWordWrap(true);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);


        retranslateUi(Info);

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QDialog *Info)
    {
        Info->setWindowTitle(QApplication::translate("Info", "About...", nullptr));
        label_2->setText(QString());
        label->setText(QApplication::translate("Info", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Eve Online</span><span style=\" font-size:14pt; font-weight:600;\"><br/>Intelligence Management Program</span></p></body></html>", nullptr));
        versionInfo->setText(QApplication::translate("Info", "V_._ - Codename", nullptr));
        label_3->setText(QApplication::translate("Info", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Created by Jesse Litton<br/></span>\302\251<span style=\" font-size:12pt;\"> Copyright 2016-2018</span></p><p align=\"center\"><span style=\" font-size:12pt;\">Icon, logo, miscellaneous sounds, and music<br/>by Lorelei Litton</span></p><p align=\"center\"><span style=\" font-size:12pt;\">100% Free to use and open source - See COPYING for details.<br/>Developed on Linux.</span></p><p align=\"center\"><span style=\" font-size:12pt;\">See CREDITS for additional attributions!</span></p><p align=\"center\">ISK donations to Khasm Kaotiqa will be used to improve this instead of ratting. :)</p><p align=\"center\"><img src=\":/graphics/impicon.png\" width=\"42\" height=\"42\"/><span style=\" font-size:12pt;\"><br/></span><a href=\"https://github.com/3vi1/IMP\"><span style=\" text-decoration: underline; color:#0000ff;\">Official GitHub/Download Site</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
