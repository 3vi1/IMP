/********************************************************************************
** Form generated from reading UI file 'themecustomizer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMECUSTOMIZER_H
#define UI_THEMECUSTOMIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThemeCustomizer
{
public:
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *pageBackground;
    QGridLayout *gridLayout_7;
    QLabel *label_23;
    QDoubleSpinBox *spinBackY;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QLabel *label_24;
    QGridLayout *gridLayout_6;
    QToolButton *buttonBackImage;
    QLabel *labelBackFile;
    QLabel *label_14;
    QDoubleSpinBox *spinBackOpacity;
    QLabel *label_5;
    QDoubleSpinBox *spinBackScale;
    QLabel *labelBackgroundScale;
    QDoubleSpinBox *spinBackZ;
    QLabel *label_7;
    QDoubleSpinBox *spinBackX;
    QGridLayout *gridLayout_3;
    QGraphicsView *imageBackColor;
    QToolButton *buttonBackColor;
    QWidget *pageFind;
    QGridLayout *gridLayout_10;
    QLabel *label_15;
    QGridLayout *gridLayout_9;
    QToolButton *buttonFindImage;
    QLabel *labelFindFile;
    QLabel *label_27;
    QDoubleSpinBox *spinFindScale;
    QLabel *label_8;
    QDoubleSpinBox *spinFindOpacity;
    QLabel *label_26;
    QDoubleSpinBox *spinFindX;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_28;
    QDoubleSpinBox *spinFindY;
    QLabel *label_9;
    QDoubleSpinBox *spinFindZ;
    QSpacerItem *horizontalSpacer_4;
    QWidget *pageFonts;
    QLabel *label_22;
    QLabel *label_21;
    QSpinBox *timerFontSize;
    QFontComboBox *timerFont;
    QSpinBox *systemFontSize;
    QFontComboBox *systemFont;
    QWidget *pageLines;
    QGridLayout *gridLayout_8;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QGraphicsView *imageLineColor;
    QToolButton *buttonLineColor;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpinBox *spinLineWidth;
    QLabel *label_3;
    QDoubleSpinBox *spinLineOpacity;
    QLabel *label_4;
    QDoubleSpinBox *spinLineZ;
    QWidget *pagePilots;
    QGridLayout *gridLayout_4;
    QLabel *label_16;
    QGridLayout *gridLayout_14;
    QToolButton *buttonPilotImage;
    QLabel *labelPilotFile;
    QLabel *label_30;
    QDoubleSpinBox *spinPilotScale;
    QLabel *label_11;
    QDoubleSpinBox *spinPilotOpacity;
    QLabel *label_31;
    QDoubleSpinBox *spinPilotX;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_29;
    QDoubleSpinBox *spinPilotY;
    QLabel *label_10;
    QDoubleSpinBox *spinPilotZ;
    QSpacerItem *horizontalSpacer_7;
    QWidget *pageSystems;
    QGridLayout *gridLayout_11;
    QLabel *label_18;
    QGridLayout *gridLayout_15;
    QToolButton *buttonSystemImage;
    QLabel *labelSystemFile;
    QLabel *label_36;
    QDoubleSpinBox *spinSystemScale;
    QLabel *label_19;
    QDoubleSpinBox *spinSystemOpacity;
    QLabel *label_35;
    QDoubleSpinBox *spinSystemX;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_37;
    QDoubleSpinBox *spinSystemY;
    QLabel *label_20;
    QDoubleSpinBox *spinSystemZ;
    QSpacerItem *horizontalSpacer_11;
    QWidget *pageWormholes;
    QGridLayout *gridLayout_5;
    QLabel *label_17;
    QGridLayout *gridLayout;
    QLabel *labelWormholeFile;
    QToolButton *buttonWormholeImage;
    QLabel *label_32;
    QDoubleSpinBox *spinWormholeScale;
    QLabel *label_13;
    QDoubleSpinBox *spinWormholeOpacity;
    QLabel *label_33;
    QDoubleSpinBox *spinWormholeX;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_34;
    QDoubleSpinBox *spinWormholeY;
    QLabel *label_12;
    QDoubleSpinBox *spinWormholeZ;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *ThemeCustomizer)
    {
        if (ThemeCustomizer->objectName().isEmpty())
            ThemeCustomizer->setObjectName(QStringLiteral("ThemeCustomizer"));
        ThemeCustomizer->resize(388, 381);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ThemeCustomizer->sizePolicy().hasHeightForWidth());
        ThemeCustomizer->setSizePolicy(sizePolicy);
        ThemeCustomizer->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(ThemeCustomizer);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(ThemeCustomizer);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setEnabled(true);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setAutoFillBackground(false);
        pageBackground = new QWidget();
        pageBackground->setObjectName(QStringLiteral("pageBackground"));
        pageBackground->setGeometry(QRect(0, 0, 374, 244));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pageBackground->sizePolicy().hasHeightForWidth());
        pageBackground->setSizePolicy(sizePolicy1);
        pageBackground->setAutoFillBackground(true);
        gridLayout_7 = new QGridLayout(pageBackground);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_23 = new QLabel(pageBackground);
        label_23->setObjectName(QStringLiteral("label_23"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_23, 5, 0, 1, 1);

        spinBackY = new QDoubleSpinBox(pageBackground);
        spinBackY->setObjectName(QStringLiteral("spinBackY"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBackY->sizePolicy().hasHeightForWidth());
        spinBackY->setSizePolicy(sizePolicy3);
        spinBackY->setMinimum(-10000);
        spinBackY->setMaximum(10000);

        gridLayout_7->addWidget(spinBackY, 5, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(145, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 6, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(145, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_3, 4, 2, 1, 1);

        label_6 = new QLabel(pageBackground);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy4);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_6, 6, 0, 1, 1);

        label_24 = new QLabel(pageBackground);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy2.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy2);
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_24, 4, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        buttonBackImage = new QToolButton(pageBackground);
        buttonBackImage->setObjectName(QStringLiteral("buttonBackImage"));

        gridLayout_6->addWidget(buttonBackImage, 0, 2, 1, 1);

        labelBackFile = new QLabel(pageBackground);
        labelBackFile->setObjectName(QStringLiteral("labelBackFile"));
        sizePolicy1.setHeightForWidth(labelBackFile->sizePolicy().hasHeightForWidth());
        labelBackFile->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(labelBackFile, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 1, 1, 1, 2);

        label_14 = new QLabel(pageBackground);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_14, 1, 0, 1, 1);

        spinBackOpacity = new QDoubleSpinBox(pageBackground);
        spinBackOpacity->setObjectName(QStringLiteral("spinBackOpacity"));
        sizePolicy1.setHeightForWidth(spinBackOpacity->sizePolicy().hasHeightForWidth());
        spinBackOpacity->setSizePolicy(sizePolicy1);
        spinBackOpacity->setMinimum(0.01);
        spinBackOpacity->setMaximum(1);
        spinBackOpacity->setSingleStep(0.01);
        spinBackOpacity->setValue(1);

        gridLayout_7->addWidget(spinBackOpacity, 3, 1, 1, 1);

        label_5 = new QLabel(pageBackground);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_5, 0, 0, 1, 1);

        spinBackScale = new QDoubleSpinBox(pageBackground);
        spinBackScale->setObjectName(QStringLiteral("spinBackScale"));
        sizePolicy1.setHeightForWidth(spinBackScale->sizePolicy().hasHeightForWidth());
        spinBackScale->setSizePolicy(sizePolicy1);
        spinBackScale->setMinimum(0.01);
        spinBackScale->setMaximum(100);
        spinBackScale->setValue(1);

        gridLayout_7->addWidget(spinBackScale, 2, 1, 1, 1);

        labelBackgroundScale = new QLabel(pageBackground);
        labelBackgroundScale->setObjectName(QStringLiteral("labelBackgroundScale"));
        sizePolicy4.setHeightForWidth(labelBackgroundScale->sizePolicy().hasHeightForWidth());
        labelBackgroundScale->setSizePolicy(sizePolicy4);
        labelBackgroundScale->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(labelBackgroundScale, 2, 0, 1, 1);

        spinBackZ = new QDoubleSpinBox(pageBackground);
        spinBackZ->setObjectName(QStringLiteral("spinBackZ"));
        sizePolicy3.setHeightForWidth(spinBackZ->sizePolicy().hasHeightForWidth());
        spinBackZ->setSizePolicy(sizePolicy3);
        spinBackZ->setMinimum(-100);
        spinBackZ->setMaximum(100);
        spinBackZ->setValue(-10);

        gridLayout_7->addWidget(spinBackZ, 6, 1, 1, 1);

        label_7 = new QLabel(pageBackground);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_7, 3, 0, 1, 1);

        spinBackX = new QDoubleSpinBox(pageBackground);
        spinBackX->setObjectName(QStringLiteral("spinBackX"));
        sizePolicy1.setHeightForWidth(spinBackX->sizePolicy().hasHeightForWidth());
        spinBackX->setSizePolicy(sizePolicy1);
        spinBackX->setMinimum(-10000);
        spinBackX->setMaximum(10000);

        gridLayout_7->addWidget(spinBackX, 4, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        imageBackColor = new QGraphicsView(pageBackground);
        imageBackColor->setObjectName(QStringLiteral("imageBackColor"));
        sizePolicy3.setHeightForWidth(imageBackColor->sizePolicy().hasHeightForWidth());
        imageBackColor->setSizePolicy(sizePolicy3);
        imageBackColor->setMaximumSize(QSize(32, 32));
        imageBackColor->setFrameShadow(QFrame::Sunken);
        imageBackColor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        imageBackColor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_3->addWidget(imageBackColor, 0, 0, 1, 1);

        buttonBackColor = new QToolButton(pageBackground);
        buttonBackColor->setObjectName(QStringLiteral("buttonBackColor"));

        gridLayout_3->addWidget(buttonBackColor, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 1, 1, 1);

        toolBox->addItem(pageBackground, QStringLiteral("Background"));
        pageFind = new QWidget();
        pageFind->setObjectName(QStringLiteral("pageFind"));
        pageFind->setGeometry(QRect(0, 0, 374, 204));
        sizePolicy1.setHeightForWidth(pageFind->sizePolicy().hasHeightForWidth());
        pageFind->setSizePolicy(sizePolicy1);
        pageFind->setAutoFillBackground(true);
        gridLayout_10 = new QGridLayout(pageFind);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_15 = new QLabel(pageFind);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_15, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        buttonFindImage = new QToolButton(pageFind);
        buttonFindImage->setObjectName(QStringLiteral("buttonFindImage"));

        gridLayout_9->addWidget(buttonFindImage, 0, 2, 1, 1);

        labelFindFile = new QLabel(pageFind);
        labelFindFile->setObjectName(QStringLiteral("labelFindFile"));
        sizePolicy1.setHeightForWidth(labelFindFile->sizePolicy().hasHeightForWidth());
        labelFindFile->setSizePolicy(sizePolicy1);

        gridLayout_9->addWidget(labelFindFile, 0, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 0, 1, 1, 2);

        label_27 = new QLabel(pageFind);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy4.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy4);
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_27, 1, 0, 1, 1);

        spinFindScale = new QDoubleSpinBox(pageFind);
        spinFindScale->setObjectName(QStringLiteral("spinFindScale"));
        sizePolicy1.setHeightForWidth(spinFindScale->sizePolicy().hasHeightForWidth());
        spinFindScale->setSizePolicy(sizePolicy1);
        spinFindScale->setMinimum(0.01);
        spinFindScale->setMaximum(100);
        spinFindScale->setValue(1);

        gridLayout_10->addWidget(spinFindScale, 1, 1, 1, 1);

        label_8 = new QLabel(pageFind);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_8, 2, 0, 1, 1);

        spinFindOpacity = new QDoubleSpinBox(pageFind);
        spinFindOpacity->setObjectName(QStringLiteral("spinFindOpacity"));
        sizePolicy1.setHeightForWidth(spinFindOpacity->sizePolicy().hasHeightForWidth());
        spinFindOpacity->setSizePolicy(sizePolicy1);
        spinFindOpacity->setMinimum(0.01);
        spinFindOpacity->setMaximum(1);
        spinFindOpacity->setSingleStep(0.01);
        spinFindOpacity->setValue(1);

        gridLayout_10->addWidget(spinFindOpacity, 2, 1, 1, 1);

        label_26 = new QLabel(pageFind);
        label_26->setObjectName(QStringLiteral("label_26"));
        sizePolicy2.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy2);
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_26, 3, 0, 1, 1);

        spinFindX = new QDoubleSpinBox(pageFind);
        spinFindX->setObjectName(QStringLiteral("spinFindX"));
        sizePolicy1.setHeightForWidth(spinFindX->sizePolicy().hasHeightForWidth());
        spinFindX->setSizePolicy(sizePolicy1);
        spinFindX->setMinimum(-10000);
        spinFindX->setMaximum(10000);

        gridLayout_10->addWidget(spinFindX, 3, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(145, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_5, 3, 2, 1, 1);

        label_28 = new QLabel(pageFind);
        label_28->setObjectName(QStringLiteral("label_28"));
        sizePolicy2.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy2);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_28, 4, 0, 1, 1);

        spinFindY = new QDoubleSpinBox(pageFind);
        spinFindY->setObjectName(QStringLiteral("spinFindY"));
        sizePolicy3.setHeightForWidth(spinFindY->sizePolicy().hasHeightForWidth());
        spinFindY->setSizePolicy(sizePolicy3);
        spinFindY->setMinimum(-10000);
        spinFindY->setMaximum(10000);

        gridLayout_10->addWidget(spinFindY, 4, 1, 1, 1);

        label_9 = new QLabel(pageFind);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy4.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy4);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(label_9, 5, 0, 1, 1);

        spinFindZ = new QDoubleSpinBox(pageFind);
        spinFindZ->setObjectName(QStringLiteral("spinFindZ"));
        sizePolicy3.setHeightForWidth(spinFindZ->sizePolicy().hasHeightForWidth());
        spinFindZ->setSizePolicy(sizePolicy3);
        spinFindZ->setMinimum(-100);
        spinFindZ->setMaximum(100);
        spinFindZ->setValue(-10);

        gridLayout_10->addWidget(spinFindZ, 5, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(145, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_4, 5, 2, 1, 1);

        toolBox->addItem(pageFind, QStringLiteral("Find"));
        pageFonts = new QWidget();
        pageFonts->setObjectName(QStringLiteral("pageFonts"));
        pageFonts->setGeometry(QRect(0, 0, 388, 164));
        pageFonts->setAutoFillBackground(true);
        label_22 = new QLabel(pageFonts);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 120, 71, 20));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy5);
        label_22->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_21 = new QLabel(pageFonts);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 20, 110, 18));
        sizePolicy5.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy5);
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        timerFontSize = new QSpinBox(pageFonts);
        timerFontSize->setObjectName(QStringLiteral("timerFontSize"));
        timerFontSize->setGeometry(QRect(10, 170, 52, 28));
        sizePolicy3.setHeightForWidth(timerFontSize->sizePolicy().hasHeightForWidth());
        timerFontSize->setSizePolicy(sizePolicy3);
        timerFontSize->setMinimum(1);
        timerFont = new QFontComboBox(pageFonts);
        timerFont->setObjectName(QStringLiteral("timerFont"));
        timerFont->setGeometry(QRect(10, 140, 231, 28));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(4);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(timerFont->sizePolicy().hasHeightForWidth());
        timerFont->setSizePolicy(sizePolicy6);
        systemFontSize = new QSpinBox(pageFonts);
        systemFontSize->setObjectName(QStringLiteral("systemFontSize"));
        systemFontSize->setGeometry(QRect(10, 70, 52, 28));
        sizePolicy3.setHeightForWidth(systemFontSize->sizePolicy().hasHeightForWidth());
        systemFontSize->setSizePolicy(sizePolicy3);
        systemFontSize->setMinimum(1);
        systemFont = new QFontComboBox(pageFonts);
        systemFont->setObjectName(QStringLiteral("systemFont"));
        systemFont->setGeometry(QRect(10, 40, 231, 28));
        sizePolicy6.setHeightForWidth(systemFont->sizePolicy().hasHeightForWidth());
        systemFont->setSizePolicy(sizePolicy6);
        toolBox->addItem(pageFonts, QStringLiteral("Fonts"));
        pageLines = new QWidget();
        pageLines->setObjectName(QStringLiteral("pageLines"));
        pageLines->setGeometry(QRect(0, 0, 388, 148));
        sizePolicy1.setHeightForWidth(pageLines->sizePolicy().hasHeightForWidth());
        pageLines->setSizePolicy(sizePolicy1);
        pageLines->setAutoFillBackground(true);
        gridLayout_8 = new QGridLayout(pageLines);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label = new QLabel(pageLines);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        imageLineColor = new QGraphicsView(pageLines);
        imageLineColor->setObjectName(QStringLiteral("imageLineColor"));
        sizePolicy3.setHeightForWidth(imageLineColor->sizePolicy().hasHeightForWidth());
        imageLineColor->setSizePolicy(sizePolicy3);
        imageLineColor->setMaximumSize(QSize(32, 32));
        imageLineColor->setFrameShadow(QFrame::Sunken);
        imageLineColor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        imageLineColor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_2->addWidget(imageLineColor, 0, 0, 1, 1);

        buttonLineColor = new QToolButton(pageLines);
        buttonLineColor->setObjectName(QStringLiteral("buttonLineColor"));

        gridLayout_2->addWidget(buttonLineColor, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(pageLines);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_2, 1, 0, 1, 1);

        spinLineWidth = new QSpinBox(pageLines);
        spinLineWidth->setObjectName(QStringLiteral("spinLineWidth"));
        sizePolicy1.setHeightForWidth(spinLineWidth->sizePolicy().hasHeightForWidth());
        spinLineWidth->setSizePolicy(sizePolicy1);
        spinLineWidth->setMinimum(0);
        spinLineWidth->setMaximum(100);
        spinLineWidth->setValue(1);

        gridLayout_8->addWidget(spinLineWidth, 1, 1, 1, 1);

        label_3 = new QLabel(pageLines);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_3, 2, 0, 1, 1);

        spinLineOpacity = new QDoubleSpinBox(pageLines);
        spinLineOpacity->setObjectName(QStringLiteral("spinLineOpacity"));
        sizePolicy1.setHeightForWidth(spinLineOpacity->sizePolicy().hasHeightForWidth());
        spinLineOpacity->setSizePolicy(sizePolicy1);
        spinLineOpacity->setMinimum(0.01);
        spinLineOpacity->setMaximum(1);
        spinLineOpacity->setSingleStep(0.01);
        spinLineOpacity->setValue(1);

        gridLayout_8->addWidget(spinLineOpacity, 2, 1, 1, 1);

        label_4 = new QLabel(pageLines);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_4, 3, 0, 1, 1);

        spinLineZ = new QDoubleSpinBox(pageLines);
        spinLineZ->setObjectName(QStringLiteral("spinLineZ"));
        sizePolicy1.setHeightForWidth(spinLineZ->sizePolicy().hasHeightForWidth());
        spinLineZ->setSizePolicy(sizePolicy1);
        spinLineZ->setMinimum(-100);
        spinLineZ->setMaximum(100);

        gridLayout_8->addWidget(spinLineZ, 3, 1, 1, 1);

        toolBox->addItem(pageLines, QStringLiteral("Lines"));
        pagePilots = new QWidget();
        pagePilots->setObjectName(QStringLiteral("pagePilots"));
        pagePilots->setGeometry(QRect(0, 0, 374, 204));
        sizePolicy1.setHeightForWidth(pagePilots->sizePolicy().hasHeightForWidth());
        pagePilots->setSizePolicy(sizePolicy1);
        pagePilots->setAutoFillBackground(true);
        gridLayout_4 = new QGridLayout(pagePilots);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_16 = new QLabel(pagePilots);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_16, 0, 0, 1, 1);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        buttonPilotImage = new QToolButton(pagePilots);
        buttonPilotImage->setObjectName(QStringLiteral("buttonPilotImage"));

        gridLayout_14->addWidget(buttonPilotImage, 0, 2, 1, 1);

        labelPilotFile = new QLabel(pagePilots);
        labelPilotFile->setObjectName(QStringLiteral("labelPilotFile"));
        sizePolicy1.setHeightForWidth(labelPilotFile->sizePolicy().hasHeightForWidth());
        labelPilotFile->setSizePolicy(sizePolicy1);

        gridLayout_14->addWidget(labelPilotFile, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_14, 0, 1, 1, 2);

        label_30 = new QLabel(pagePilots);
        label_30->setObjectName(QStringLiteral("label_30"));
        sizePolicy4.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy4);
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_30, 1, 0, 1, 1);

        spinPilotScale = new QDoubleSpinBox(pagePilots);
        spinPilotScale->setObjectName(QStringLiteral("spinPilotScale"));
        sizePolicy1.setHeightForWidth(spinPilotScale->sizePolicy().hasHeightForWidth());
        spinPilotScale->setSizePolicy(sizePolicy1);
        spinPilotScale->setMinimum(0.01);
        spinPilotScale->setMaximum(100);
        spinPilotScale->setValue(1);

        gridLayout_4->addWidget(spinPilotScale, 1, 1, 1, 1);

        label_11 = new QLabel(pagePilots);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy4.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy4);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_11, 2, 0, 1, 1);

        spinPilotOpacity = new QDoubleSpinBox(pagePilots);
        spinPilotOpacity->setObjectName(QStringLiteral("spinPilotOpacity"));
        sizePolicy1.setHeightForWidth(spinPilotOpacity->sizePolicy().hasHeightForWidth());
        spinPilotOpacity->setSizePolicy(sizePolicy1);
        spinPilotOpacity->setMinimum(0.01);
        spinPilotOpacity->setMaximum(1);
        spinPilotOpacity->setSingleStep(0.01);
        spinPilotOpacity->setValue(1);

        gridLayout_4->addWidget(spinPilotOpacity, 2, 1, 1, 1);

        label_31 = new QLabel(pagePilots);
        label_31->setObjectName(QStringLiteral("label_31"));
        sizePolicy2.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy2);
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_31, 3, 0, 1, 1);

        spinPilotX = new QDoubleSpinBox(pagePilots);
        spinPilotX->setObjectName(QStringLiteral("spinPilotX"));
        sizePolicy1.setHeightForWidth(spinPilotX->sizePolicy().hasHeightForWidth());
        spinPilotX->setSizePolicy(sizePolicy1);
        spinPilotX->setMinimum(-10000);
        spinPilotX->setMaximum(10000);

        gridLayout_4->addWidget(spinPilotX, 3, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(142, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 3, 2, 1, 1);

        label_29 = new QLabel(pagePilots);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy2.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy2);
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_29, 4, 0, 1, 1);

        spinPilotY = new QDoubleSpinBox(pagePilots);
        spinPilotY->setObjectName(QStringLiteral("spinPilotY"));
        sizePolicy3.setHeightForWidth(spinPilotY->sizePolicy().hasHeightForWidth());
        spinPilotY->setSizePolicy(sizePolicy3);
        spinPilotY->setMinimum(-10000);
        spinPilotY->setMaximum(10000);

        gridLayout_4->addWidget(spinPilotY, 4, 1, 1, 1);

        label_10 = new QLabel(pagePilots);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy4.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy4);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_10, 5, 0, 1, 1);

        spinPilotZ = new QDoubleSpinBox(pagePilots);
        spinPilotZ->setObjectName(QStringLiteral("spinPilotZ"));
        sizePolicy3.setHeightForWidth(spinPilotZ->sizePolicy().hasHeightForWidth());
        spinPilotZ->setSizePolicy(sizePolicy3);
        spinPilotZ->setMinimum(-100);
        spinPilotZ->setMaximum(100);
        spinPilotZ->setValue(-10);

        gridLayout_4->addWidget(spinPilotZ, 5, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(142, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 5, 2, 1, 1);

        toolBox->addItem(pagePilots, QStringLiteral("Pilots"));
        pageSystems = new QWidget();
        pageSystems->setObjectName(QStringLiteral("pageSystems"));
        pageSystems->setGeometry(QRect(0, 0, 374, 204));
        gridLayout_11 = new QGridLayout(pageSystems);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        label_18 = new QLabel(pageSystems);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_18, 0, 0, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        buttonSystemImage = new QToolButton(pageSystems);
        buttonSystemImage->setObjectName(QStringLiteral("buttonSystemImage"));

        gridLayout_15->addWidget(buttonSystemImage, 0, 2, 1, 1);

        labelSystemFile = new QLabel(pageSystems);
        labelSystemFile->setObjectName(QStringLiteral("labelSystemFile"));
        sizePolicy1.setHeightForWidth(labelSystemFile->sizePolicy().hasHeightForWidth());
        labelSystemFile->setSizePolicy(sizePolicy1);

        gridLayout_15->addWidget(labelSystemFile, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_15, 0, 1, 1, 1);

        label_36 = new QLabel(pageSystems);
        label_36->setObjectName(QStringLiteral("label_36"));
        sizePolicy4.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy4);
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_36, 1, 0, 1, 1);

        spinSystemScale = new QDoubleSpinBox(pageSystems);
        spinSystemScale->setObjectName(QStringLiteral("spinSystemScale"));
        sizePolicy1.setHeightForWidth(spinSystemScale->sizePolicy().hasHeightForWidth());
        spinSystemScale->setSizePolicy(sizePolicy1);
        spinSystemScale->setMinimum(0.01);
        spinSystemScale->setMaximum(100);
        spinSystemScale->setValue(1);

        gridLayout_11->addWidget(spinSystemScale, 1, 1, 1, 1);

        label_19 = new QLabel(pageSystems);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy4.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy4);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_19, 2, 0, 1, 1);

        spinSystemOpacity = new QDoubleSpinBox(pageSystems);
        spinSystemOpacity->setObjectName(QStringLiteral("spinSystemOpacity"));
        sizePolicy1.setHeightForWidth(spinSystemOpacity->sizePolicy().hasHeightForWidth());
        spinSystemOpacity->setSizePolicy(sizePolicy1);
        spinSystemOpacity->setMinimum(0.01);
        spinSystemOpacity->setMaximum(1);
        spinSystemOpacity->setSingleStep(0.01);
        spinSystemOpacity->setValue(1);

        gridLayout_11->addWidget(spinSystemOpacity, 2, 1, 1, 1);

        label_35 = new QLabel(pageSystems);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy2.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy2);
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_35, 3, 0, 1, 1);

        spinSystemX = new QDoubleSpinBox(pageSystems);
        spinSystemX->setObjectName(QStringLiteral("spinSystemX"));
        sizePolicy1.setHeightForWidth(spinSystemX->sizePolicy().hasHeightForWidth());
        spinSystemX->setSizePolicy(sizePolicy1);
        spinSystemX->setMinimum(-10000);
        spinSystemX->setMaximum(10000);

        gridLayout_11->addWidget(spinSystemX, 3, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(142, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_10, 3, 2, 1, 1);

        label_37 = new QLabel(pageSystems);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy2.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy2);
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_37, 4, 0, 1, 1);

        spinSystemY = new QDoubleSpinBox(pageSystems);
        spinSystemY->setObjectName(QStringLiteral("spinSystemY"));
        sizePolicy3.setHeightForWidth(spinSystemY->sizePolicy().hasHeightForWidth());
        spinSystemY->setSizePolicy(sizePolicy3);
        spinSystemY->setMinimum(-10000);
        spinSystemY->setMaximum(10000);

        gridLayout_11->addWidget(spinSystemY, 4, 1, 1, 1);

        label_20 = new QLabel(pageSystems);
        label_20->setObjectName(QStringLiteral("label_20"));
        sizePolicy4.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy4);
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_20, 5, 0, 1, 1);

        spinSystemZ = new QDoubleSpinBox(pageSystems);
        spinSystemZ->setObjectName(QStringLiteral("spinSystemZ"));
        sizePolicy3.setHeightForWidth(spinSystemZ->sizePolicy().hasHeightForWidth());
        spinSystemZ->setSizePolicy(sizePolicy3);
        spinSystemZ->setMinimum(-100);
        spinSystemZ->setMaximum(100);
        spinSystemZ->setValue(1);

        gridLayout_11->addWidget(spinSystemZ, 5, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(142, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_11, 5, 2, 1, 1);

        toolBox->addItem(pageSystems, QStringLiteral("Systems"));
        pageWormholes = new QWidget();
        pageWormholes->setObjectName(QStringLiteral("pageWormholes"));
        pageWormholes->setGeometry(QRect(0, 0, 374, 204));
        gridLayout_5 = new QGridLayout(pageWormholes);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_17 = new QLabel(pageWormholes);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_17, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelWormholeFile = new QLabel(pageWormholes);
        labelWormholeFile->setObjectName(QStringLiteral("labelWormholeFile"));
        sizePolicy1.setHeightForWidth(labelWormholeFile->sizePolicy().hasHeightForWidth());
        labelWormholeFile->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelWormholeFile, 0, 0, 1, 1);

        buttonWormholeImage = new QToolButton(pageWormholes);
        buttonWormholeImage->setObjectName(QStringLiteral("buttonWormholeImage"));

        gridLayout->addWidget(buttonWormholeImage, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 1, 1, 2);

        label_32 = new QLabel(pageWormholes);
        label_32->setObjectName(QStringLiteral("label_32"));
        sizePolicy4.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy4);
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_32, 1, 0, 1, 1);

        spinWormholeScale = new QDoubleSpinBox(pageWormholes);
        spinWormholeScale->setObjectName(QStringLiteral("spinWormholeScale"));
        sizePolicy1.setHeightForWidth(spinWormholeScale->sizePolicy().hasHeightForWidth());
        spinWormholeScale->setSizePolicy(sizePolicy1);
        spinWormholeScale->setMinimum(0.01);
        spinWormholeScale->setMaximum(100);
        spinWormholeScale->setValue(0.05);

        gridLayout_5->addWidget(spinWormholeScale, 1, 1, 1, 1);

        label_13 = new QLabel(pageWormholes);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy4.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy4);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_13, 2, 0, 1, 1);

        spinWormholeOpacity = new QDoubleSpinBox(pageWormholes);
        spinWormholeOpacity->setObjectName(QStringLiteral("spinWormholeOpacity"));
        sizePolicy1.setHeightForWidth(spinWormholeOpacity->sizePolicy().hasHeightForWidth());
        spinWormholeOpacity->setSizePolicy(sizePolicy1);
        spinWormholeOpacity->setMinimum(0.01);
        spinWormholeOpacity->setMaximum(1);
        spinWormholeOpacity->setSingleStep(0.01);
        spinWormholeOpacity->setValue(0.8);

        gridLayout_5->addWidget(spinWormholeOpacity, 2, 1, 1, 1);

        label_33 = new QLabel(pageWormholes);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy2.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy2);
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_33, 3, 0, 1, 1);

        spinWormholeX = new QDoubleSpinBox(pageWormholes);
        spinWormholeX->setObjectName(QStringLiteral("spinWormholeX"));
        sizePolicy1.setHeightForWidth(spinWormholeX->sizePolicy().hasHeightForWidth());
        spinWormholeX->setSizePolicy(sizePolicy1);
        spinWormholeX->setMinimum(-10000);
        spinWormholeX->setMaximum(10000);
        spinWormholeX->setValue(23);

        gridLayout_5->addWidget(spinWormholeX, 3, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(142, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 3, 2, 1, 1);

        label_34 = new QLabel(pageWormholes);
        label_34->setObjectName(QStringLiteral("label_34"));
        sizePolicy2.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy2);
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_34, 4, 0, 1, 1);

        spinWormholeY = new QDoubleSpinBox(pageWormholes);
        spinWormholeY->setObjectName(QStringLiteral("spinWormholeY"));
        sizePolicy3.setHeightForWidth(spinWormholeY->sizePolicy().hasHeightForWidth());
        spinWormholeY->setSizePolicy(sizePolicy3);
        spinWormholeY->setMinimum(-10000);
        spinWormholeY->setMaximum(10000);
        spinWormholeY->setValue(10);

        gridLayout_5->addWidget(spinWormholeY, 4, 1, 1, 1);

        label_12 = new QLabel(pageWormholes);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy4.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy4);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_12, 5, 0, 1, 1);

        spinWormholeZ = new QDoubleSpinBox(pageWormholes);
        spinWormholeZ->setObjectName(QStringLiteral("spinWormholeZ"));
        sizePolicy3.setHeightForWidth(spinWormholeZ->sizePolicy().hasHeightForWidth());
        spinWormholeZ->setSizePolicy(sizePolicy3);
        spinWormholeZ->setMinimum(-100);
        spinWormholeZ->setMaximum(100);
        spinWormholeZ->setValue(1);

        gridLayout_5->addWidget(spinWormholeZ, 5, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(142, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 5, 2, 1, 1);

        toolBox->addItem(pageWormholes, QStringLiteral("Wormholes"));

        verticalLayout->addWidget(toolBox);


        retranslateUi(ThemeCustomizer);

        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(6);


        QMetaObject::connectSlotsByName(ThemeCustomizer);
    } // setupUi

    void retranslateUi(QWidget *ThemeCustomizer)
    {
        ThemeCustomizer->setWindowTitle(QApplication::translate("ThemeCustomizer", "Form", Q_NULLPTR));
        label_23->setText(QApplication::translate("ThemeCustomizer", "Y offset:", Q_NULLPTR));
        label_6->setText(QApplication::translate("ThemeCustomizer", "Z position:", Q_NULLPTR));
        label_24->setText(QApplication::translate("ThemeCustomizer", "X offset:", Q_NULLPTR));
        buttonBackImage->setText(QApplication::translate("ThemeCustomizer", "...", Q_NULLPTR));
        labelBackFile->setText(QApplication::translate("ThemeCustomizer", "fileName", Q_NULLPTR));
        label_14->setText(QApplication::translate("ThemeCustomizer", "Image:", Q_NULLPTR));
        label_5->setText(QApplication::translate("ThemeCustomizer", "Color:", Q_NULLPTR));
        labelBackgroundScale->setText(QApplication::translate("ThemeCustomizer", "Scale:", Q_NULLPTR));
        label_7->setText(QApplication::translate("ThemeCustomizer", "Opacity:", Q_NULLPTR));
        buttonBackColor->setText(QApplication::translate("ThemeCustomizer", "...", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(pageBackground), QApplication::translate("ThemeCustomizer", "Background", Q_NULLPTR));
        label_15->setText(QApplication::translate("ThemeCustomizer", "Image:", Q_NULLPTR));
        buttonFindImage->setText(QApplication::translate("ThemeCustomizer", "...", Q_NULLPTR));
        labelFindFile->setText(QApplication::translate("ThemeCustomizer", "fileName", Q_NULLPTR));
        label_27->setText(QApplication::translate("ThemeCustomizer", "Scale:", Q_NULLPTR));
        label_8->setText(QApplication::translate("ThemeCustomizer", "Opacity:", Q_NULLPTR));
        label_26->setText(QApplication::translate("ThemeCustomizer", "X offset:", Q_NULLPTR));
        label_28->setText(QApplication::translate("ThemeCustomizer", "Y offset:", Q_NULLPTR));
        label_9->setText(QApplication::translate("ThemeCustomizer", "Z position:", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(pageFind), QApplication::translate("ThemeCustomizer", "Find", Q_NULLPTR));
        label_22->setText(QApplication::translate("ThemeCustomizer", "Timer:", Q_NULLPTR));
        label_21->setText(QApplication::translate("ThemeCustomizer", "System Name:", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(pageFonts), QApplication::translate("ThemeCustomizer", "Fonts", Q_NULLPTR));
        label->setText(QApplication::translate("ThemeCustomizer", "Color:", Q_NULLPTR));
        buttonLineColor->setText(QApplication::translate("ThemeCustomizer", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("ThemeCustomizer", "Width:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ThemeCustomizer", "Opacity:", Q_NULLPTR));
        label_4->setText(QApplication::translate("ThemeCustomizer", "Z position:", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(pageLines), QApplication::translate("ThemeCustomizer", "Lines", Q_NULLPTR));
        label_16->setText(QApplication::translate("ThemeCustomizer", "Image:", Q_NULLPTR));
        buttonPilotImage->setText(QApplication::translate("ThemeCustomizer", "...", Q_NULLPTR));
        labelPilotFile->setText(QApplication::translate("ThemeCustomizer", "fileName", Q_NULLPTR));
        label_30->setText(QApplication::translate("ThemeCustomizer", "Scale:", Q_NULLPTR));
        label_11->setText(QApplication::translate("ThemeCustomizer", "Opacity:", Q_NULLPTR));
        label_31->setText(QApplication::translate("ThemeCustomizer", "X offset:", Q_NULLPTR));
        label_29->setText(QApplication::translate("ThemeCustomizer", "Y offset:", Q_NULLPTR));
        label_10->setText(QApplication::translate("ThemeCustomizer", "Z position:", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(pagePilots), QApplication::translate("ThemeCustomizer", "Pilots", Q_NULLPTR));
        label_18->setText(QApplication::translate("ThemeCustomizer", "SVG:", Q_NULLPTR));
        buttonSystemImage->setText(QApplication::translate("ThemeCustomizer", "...", Q_NULLPTR));
        labelSystemFile->setText(QApplication::translate("ThemeCustomizer", "fileName", Q_NULLPTR));
        label_36->setText(QApplication::translate("ThemeCustomizer", "Scale:", Q_NULLPTR));
        label_19->setText(QApplication::translate("ThemeCustomizer", "Opacity:", Q_NULLPTR));
        label_35->setText(QApplication::translate("ThemeCustomizer", "X offset:", Q_NULLPTR));
        label_37->setText(QApplication::translate("ThemeCustomizer", "Y offset:", Q_NULLPTR));
        label_20->setText(QApplication::translate("ThemeCustomizer", "Z position:", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(pageSystems), QApplication::translate("ThemeCustomizer", "Systems", Q_NULLPTR));
        label_17->setText(QApplication::translate("ThemeCustomizer", "Image:", Q_NULLPTR));
        labelWormholeFile->setText(QApplication::translate("ThemeCustomizer", "fileName", Q_NULLPTR));
        buttonWormholeImage->setText(QApplication::translate("ThemeCustomizer", "...", Q_NULLPTR));
        label_32->setText(QApplication::translate("ThemeCustomizer", "Scale:", Q_NULLPTR));
        label_13->setText(QApplication::translate("ThemeCustomizer", "Opacity:", Q_NULLPTR));
        label_33->setText(QApplication::translate("ThemeCustomizer", "X offset:", Q_NULLPTR));
        label_34->setText(QApplication::translate("ThemeCustomizer", "Y offset:", Q_NULLPTR));
        label_12->setText(QApplication::translate("ThemeCustomizer", "Z position:", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(pageWormholes), QApplication::translate("ThemeCustomizer", "Wormholes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ThemeCustomizer: public Ui_ThemeCustomizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMECUSTOMIZER_H
