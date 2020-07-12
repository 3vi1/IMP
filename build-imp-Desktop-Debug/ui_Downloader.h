/********************************************************************************
** Form generated from reading UI file 'Downloader.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADER_H
#define UI_DOWNLOADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Downloader
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *updater_icon;
    QWidget *progressFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *downloadLabel;
    QProgressBar *progressBar;
    QLabel *timeLabel;
    QWidget *buttonFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *buttonSpacer;
    QPushButton *openButton;
    QPushButton *stopButton;

    void setupUi(QWidget *Downloader)
    {
        if (Downloader->objectName().isEmpty())
            Downloader->setObjectName(QStringLiteral("Downloader"));
        Downloader->resize(464, 164);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Downloader->sizePolicy().hasHeightForWidth());
        Downloader->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Downloader);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        widget = new QWidget(Downloader);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        updater_icon = new QLabel(widget);
        updater_icon->setObjectName(QStringLiteral("updater_icon"));
        updater_icon->setMinimumSize(QSize(96, 96));
        updater_icon->setPixmap(QPixmap(QString::fromUtf8(":/icons/update.png")));

        horizontalLayout->addWidget(updater_icon);

        progressFrame = new QWidget(widget);
        progressFrame->setObjectName(QStringLiteral("progressFrame"));
        verticalLayout_2 = new QVBoxLayout(progressFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        downloadLabel = new QLabel(progressFrame);
        downloadLabel->setObjectName(QStringLiteral("downloadLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        downloadLabel->setFont(font);

        verticalLayout_2->addWidget(downloadLabel);

        progressBar = new QProgressBar(progressFrame);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(320, 0));
        progressBar->setValue(0);
        progressBar->setInvertedAppearance(false);

        verticalLayout_2->addWidget(progressBar);

        timeLabel = new QLabel(progressFrame);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        verticalLayout_2->addWidget(timeLabel);


        horizontalLayout->addWidget(progressFrame);


        verticalLayout->addWidget(widget);

        buttonFrame = new QWidget(Downloader);
        buttonFrame->setObjectName(QStringLiteral("buttonFrame"));
        horizontalLayout_2 = new QHBoxLayout(buttonFrame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(12, 12, 12, 12);
        buttonSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(buttonSpacer);

        openButton = new QPushButton(buttonFrame);
        openButton->setObjectName(QStringLiteral("openButton"));

        horizontalLayout_2->addWidget(openButton);

        stopButton = new QPushButton(buttonFrame);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout_2->addWidget(stopButton);


        verticalLayout->addWidget(buttonFrame);


        retranslateUi(Downloader);

        QMetaObject::connectSlotsByName(Downloader);
    } // setupUi

    void retranslateUi(QWidget *Downloader)
    {
        Downloader->setWindowTitle(QApplication::translate("Downloader", "Updater", Q_NULLPTR));
        updater_icon->setText(QString());
        downloadLabel->setText(QApplication::translate("Downloader", "Downloading updates", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("Downloader", "Time remaining: 0 minutes", Q_NULLPTR));
        openButton->setText(QApplication::translate("Downloader", "Open", Q_NULLPTR));
        stopButton->setText(QApplication::translate("Downloader", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Downloader: public Ui_Downloader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADER_H
