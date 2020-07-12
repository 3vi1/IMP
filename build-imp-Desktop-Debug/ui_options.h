/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTabWidget *options;
    QWidget *tabProximity;
    QGridLayout *gridLayout_12;
    QTableView *tableProxAlarms;
    QPushButton *btnRemoveProx;
    QPushButton *btnInsertProx;
    QWidget *alerts_tab;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_26;
    QSpinBox *redundantSpinBox;
    QLabel *label_27;
    QCheckBox *selfSuppressCheck;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QComboBox *statusCombo;
    QToolButton *statusTestButton;
    QLabel *label_14;
    QComboBox *essCombo;
    QToolButton *essTestButton;
    QCheckBox *essBox;
    QLabel *label_4;
    QSlider *volume;
    QWidget *rules_tab;
    QGridLayout *gridLayout_2;
    QTableView *tableView;
    QPushButton *ruleRemoveButton;
    QPushButton *ruleInsertButton;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QLabel *label_6;
    QCheckBox *kosCheck;
    QLabel *label_32;
    QCheckBox *checkKosDouble;
    QLabel *label_33;
    QLabel *label_11;
    QComboBox *clipKosCombo;
    QToolButton *clipKosTestButton;
    QLabel *label_12;
    QComboBox *clipNotKosCombo;
    QToolButton *clipNotKosTestButton;
    QLabel *label_34;
    QComboBox *comboIncomplete;
    QToolButton *incompleteTestButton;
    QWidget *map_tab;
    QGridLayout *gridLayout_3;
    QLabel *label_16;
    QSpinBox *autoPeriodSpin;
    QSpinBox *refreshSpin;
    QLabel *label_19;
    QLabel *label_15;
    QCheckBox *smoothCheck;
    QLineEdit *mapEdit;
    QLineEdit *bridgeEdit;
    QLabel *label_21;
    QLabel *label_17;
    QLabel *label_20;
    QLabel *label_18;
    QSpinBox *autoRefreshSpin;
    QLabel *label_31;
    QLabel *label_13;
    QWidget *tabMessages;
    QGridLayout *gridLayout_5;
    QSpinBox *fontSpinBox;
    QSpinBox *historySpinBox;
    QLabel *label_30;
    QSpinBox *avatarBox;
    QLabel *labelFontSize;
    QLabel *label_8;
    QLabel *labelFontSize_2;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *addIntelButton;
    QToolButton *delIntelButton;
    QLabel *labelFontSize_3;
    QLineEdit *intelEdit;
    QCheckBox *checkAvatar;
    QListWidget *intelWidget;
    QSpacerItem *verticalSpacer;
    QFontComboBox *fontComboBox;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QWidget *tabPoller;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLineEdit *logsEdit;
    QToolButton *logsButton;
    QGridLayout *gridLayout_9;
    QLabel *labelFontSize_4;
    QCheckBox *checkOldIntel;
    QLabel *label_28;
    QSpinBox *maxEntriesSpinBox;
    QLabel *label_29;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_23;
    QSpinBox *pollerSpinBox;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout;
    QLabel *label_25;
    QLabel *label_24;
    QWidget *tab_2;
    QGridLayout *gridLayout_8;
    QLabel *label_35;
    QComboBox *comboStyle;
    QWidget *tabUpdates;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkUpdates;
    QPushButton *buttonCheck;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioAudioSFML;
    QRadioButton *radioAudioQt;
    QCheckBox *checkDisableMusic;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QStringLiteral("Options"));
        Options->resize(1104, 571);
        QIcon icon;
        icon.addFile(QStringLiteral(":/graphics/impicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Options->setWindowIcon(icon);
        gridLayout = new QGridLayout(Options);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(Options);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        options = new QTabWidget(Options);
        options->setObjectName(QStringLiteral("options"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(options->sizePolicy().hasHeightForWidth());
        options->setSizePolicy(sizePolicy);
        options->setTabShape(QTabWidget::Rounded);
        tabProximity = new QWidget();
        tabProximity->setObjectName(QStringLiteral("tabProximity"));
        gridLayout_12 = new QGridLayout(tabProximity);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        tableProxAlarms = new QTableView(tabProximity);
        tableProxAlarms->setObjectName(QStringLiteral("tableProxAlarms"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableProxAlarms->sizePolicy().hasHeightForWidth());
        tableProxAlarms->setSizePolicy(sizePolicy1);

        gridLayout_12->addWidget(tableProxAlarms, 0, 0, 1, 2);

        btnRemoveProx = new QPushButton(tabProximity);
        btnRemoveProx->setObjectName(QStringLiteral("btnRemoveProx"));

        gridLayout_12->addWidget(btnRemoveProx, 1, 0, 1, 1);

        btnInsertProx = new QPushButton(tabProximity);
        btnInsertProx->setObjectName(QStringLiteral("btnInsertProx"));

        gridLayout_12->addWidget(btnInsertProx, 1, 1, 1, 1);

        options->addTab(tabProximity, QString());
        alerts_tab = new QWidget();
        alerts_tab->setObjectName(QStringLiteral("alerts_tab"));
        gridLayout_4 = new QGridLayout(alerts_tab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_26 = new QLabel(alerts_tab);
        label_26->setObjectName(QStringLiteral("label_26"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_26);

        redundantSpinBox = new QSpinBox(alerts_tab);
        redundantSpinBox->setObjectName(QStringLiteral("redundantSpinBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(redundantSpinBox->sizePolicy().hasHeightForWidth());
        redundantSpinBox->setSizePolicy(sizePolicy3);
        redundantSpinBox->setMaximum(300);
        redundantSpinBox->setValue(30);

        horizontalLayout_3->addWidget(redundantSpinBox);

        label_27 = new QLabel(alerts_tab);
        label_27->setObjectName(QStringLiteral("label_27"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(label_27);


        gridLayout_4->addLayout(horizontalLayout_3, 0, 1, 1, 3);

        selfSuppressCheck = new QCheckBox(alerts_tab);
        selfSuppressCheck->setObjectName(QStringLiteral("selfSuppressCheck"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(selfSuppressCheck->sizePolicy().hasHeightForWidth());
        selfSuppressCheck->setSizePolicy(sizePolicy5);
        selfSuppressCheck->setChecked(true);

        gridLayout_4->addWidget(selfSuppressCheck, 1, 1, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 2, 3, 1, 1);

        label_3 = new QLabel(alerts_tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy6);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_3, 3, 0, 1, 2);

        statusCombo = new QComboBox(alerts_tab);
        statusCombo->setObjectName(QStringLiteral("statusCombo"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(statusCombo->sizePolicy().hasHeightForWidth());
        statusCombo->setSizePolicy(sizePolicy7);

        gridLayout_4->addWidget(statusCombo, 3, 2, 1, 1);

        statusTestButton = new QToolButton(alerts_tab);
        statusTestButton->setObjectName(QStringLiteral("statusTestButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/graphics/volume-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        statusTestButton->setIcon(icon1);

        gridLayout_4->addWidget(statusTestButton, 3, 4, 1, 1);

        label_14 = new QLabel(alerts_tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy6.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy6);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_14, 4, 0, 1, 2);

        essCombo = new QComboBox(alerts_tab);
        essCombo->setObjectName(QStringLiteral("essCombo"));
        sizePolicy7.setHeightForWidth(essCombo->sizePolicy().hasHeightForWidth());
        essCombo->setSizePolicy(sizePolicy7);

        gridLayout_4->addWidget(essCombo, 4, 2, 1, 1);

        essTestButton = new QToolButton(alerts_tab);
        essTestButton->setObjectName(QStringLiteral("essTestButton"));
        essTestButton->setIcon(icon1);

        gridLayout_4->addWidget(essTestButton, 4, 4, 1, 1);

        essBox = new QCheckBox(alerts_tab);
        essBox->setObjectName(QStringLiteral("essBox"));
        essBox->setChecked(true);

        gridLayout_4->addWidget(essBox, 5, 2, 1, 2);

        label_4 = new QLabel(alerts_tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_4, 6, 0, 1, 1);

        volume = new QSlider(alerts_tab);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setMaximum(100);
        volume->setValue(100);
        volume->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(volume, 6, 2, 1, 1);

        options->addTab(alerts_tab, QString());
        rules_tab = new QWidget();
        rules_tab->setObjectName(QStringLiteral("rules_tab"));
        gridLayout_2 = new QGridLayout(rules_tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableView = new QTableView(rules_tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(tableView, 0, 0, 1, 2);

        ruleRemoveButton = new QPushButton(rules_tab);
        ruleRemoveButton->setObjectName(QStringLiteral("ruleRemoveButton"));

        gridLayout_2->addWidget(ruleRemoveButton, 1, 0, 1, 1);

        ruleInsertButton = new QPushButton(rules_tab);
        ruleInsertButton->setObjectName(QStringLiteral("ruleInsertButton"));

        gridLayout_2->addWidget(ruleInsertButton, 1, 1, 1, 1);

        options->addTab(rules_tab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy8);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_6, 0, 0, 1, 1);

        kosCheck = new QCheckBox(tab);
        kosCheck->setObjectName(QStringLiteral("kosCheck"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(kosCheck->sizePolicy().hasHeightForWidth());
        kosCheck->setSizePolicy(sizePolicy9);
        kosCheck->setChecked(true);

        gridLayout_6->addWidget(kosCheck, 0, 1, 1, 1);

        label_32 = new QLabel(tab);
        label_32->setObjectName(QStringLiteral("label_32"));
        sizePolicy8.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy8);
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_32, 1, 0, 1, 1);

        checkKosDouble = new QCheckBox(tab);
        checkKosDouble->setObjectName(QStringLiteral("checkKosDouble"));
        sizePolicy9.setHeightForWidth(checkKosDouble->sizePolicy().hasHeightForWidth());
        checkKosDouble->setSizePolicy(sizePolicy9);
        checkKosDouble->setChecked(true);

        gridLayout_6->addWidget(checkKosDouble, 1, 1, 1, 1);

        label_33 = new QLabel(tab);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setWordWrap(true);

        gridLayout_6->addWidget(label_33, 1, 2, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy8.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy8);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_11, 2, 0, 1, 1);

        clipKosCombo = new QComboBox(tab);
        clipKosCombo->setObjectName(QStringLiteral("clipKosCombo"));
        sizePolicy7.setHeightForWidth(clipKosCombo->sizePolicy().hasHeightForWidth());
        clipKosCombo->setSizePolicy(sizePolicy7);

        gridLayout_6->addWidget(clipKosCombo, 2, 1, 1, 2);

        clipKosTestButton = new QToolButton(tab);
        clipKosTestButton->setObjectName(QStringLiteral("clipKosTestButton"));
        clipKosTestButton->setIcon(icon1);

        gridLayout_6->addWidget(clipKosTestButton, 2, 3, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy8.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy8);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_12, 3, 0, 1, 1);

        clipNotKosCombo = new QComboBox(tab);
        clipNotKosCombo->setObjectName(QStringLiteral("clipNotKosCombo"));
        sizePolicy7.setHeightForWidth(clipNotKosCombo->sizePolicy().hasHeightForWidth());
        clipNotKosCombo->setSizePolicy(sizePolicy7);

        gridLayout_6->addWidget(clipNotKosCombo, 3, 1, 1, 2);

        clipNotKosTestButton = new QToolButton(tab);
        clipNotKosTestButton->setObjectName(QStringLiteral("clipNotKosTestButton"));
        clipNotKosTestButton->setIcon(icon1);

        gridLayout_6->addWidget(clipNotKosTestButton, 3, 3, 1, 1);

        label_34 = new QLabel(tab);
        label_34->setObjectName(QStringLiteral("label_34"));
        sizePolicy8.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy8);
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_34, 4, 0, 1, 1);

        comboIncomplete = new QComboBox(tab);
        comboIncomplete->setObjectName(QStringLiteral("comboIncomplete"));
        sizePolicy7.setHeightForWidth(comboIncomplete->sizePolicy().hasHeightForWidth());
        comboIncomplete->setSizePolicy(sizePolicy7);

        gridLayout_6->addWidget(comboIncomplete, 4, 1, 1, 2);

        incompleteTestButton = new QToolButton(tab);
        incompleteTestButton->setObjectName(QStringLiteral("incompleteTestButton"));
        incompleteTestButton->setIcon(icon1);

        gridLayout_6->addWidget(incompleteTestButton, 4, 3, 1, 1);

        options->addTab(tab, QString());
        map_tab = new QWidget();
        map_tab->setObjectName(QStringLiteral("map_tab"));
        gridLayout_3 = new QGridLayout(map_tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_16 = new QLabel(map_tab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_16, 2, 0, 1, 1);

        autoPeriodSpin = new QSpinBox(map_tab);
        autoPeriodSpin->setObjectName(QStringLiteral("autoPeriodSpin"));
        sizePolicy9.setHeightForWidth(autoPeriodSpin->sizePolicy().hasHeightForWidth());
        autoPeriodSpin->setSizePolicy(sizePolicy9);
        autoPeriodSpin->setMinimum(500);
        autoPeriodSpin->setMaximum(10000);
        autoPeriodSpin->setValue(4000);

        gridLayout_3->addWidget(autoPeriodSpin, 4, 3, 1, 1);

        refreshSpin = new QSpinBox(map_tab);
        refreshSpin->setObjectName(QStringLiteral("refreshSpin"));
        sizePolicy9.setHeightForWidth(refreshSpin->sizePolicy().hasHeightForWidth());
        refreshSpin->setSizePolicy(sizePolicy9);
        refreshSpin->setMinimum(1000);
        refreshSpin->setMaximum(10000);
        refreshSpin->setValue(1000);

        gridLayout_3->addWidget(refreshSpin, 2, 3, 1, 1);

        label_19 = new QLabel(map_tab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_19, 2, 4, 1, 1);

        label_15 = new QLabel(map_tab);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_15, 3, 0, 1, 1);

        smoothCheck = new QCheckBox(map_tab);
        smoothCheck->setObjectName(QStringLiteral("smoothCheck"));
        smoothCheck->setChecked(true);

        gridLayout_3->addWidget(smoothCheck, 3, 3, 1, 1);

        mapEdit = new QLineEdit(map_tab);
        mapEdit->setObjectName(QStringLiteral("mapEdit"));

        gridLayout_3->addWidget(mapEdit, 0, 3, 1, 2);

        bridgeEdit = new QLineEdit(map_tab);
        bridgeEdit->setObjectName(QStringLiteral("bridgeEdit"));

        gridLayout_3->addWidget(bridgeEdit, 1, 3, 1, 2);

        label_21 = new QLabel(map_tab);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_21, 5, 4, 1, 1);

        label_17 = new QLabel(map_tab);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_17, 4, 0, 1, 1);

        label_20 = new QLabel(map_tab);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_20, 4, 4, 1, 1);

        label_18 = new QLabel(map_tab);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_18, 5, 0, 1, 1);

        autoRefreshSpin = new QSpinBox(map_tab);
        autoRefreshSpin->setObjectName(QStringLiteral("autoRefreshSpin"));
        sizePolicy9.setHeightForWidth(autoRefreshSpin->sizePolicy().hasHeightForWidth());
        autoRefreshSpin->setSizePolicy(sizePolicy9);
        autoRefreshSpin->setMinimum(5);
        autoRefreshSpin->setMaximum(300);
        autoRefreshSpin->setValue(33);

        gridLayout_3->addWidget(autoRefreshSpin, 5, 3, 1, 1);

        label_31 = new QLabel(map_tab);
        label_31->setObjectName(QStringLiteral("label_31"));
        sizePolicy6.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy6);
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_31, 1, 0, 1, 1);

        label_13 = new QLabel(map_tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy6.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy6);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        options->addTab(map_tab, QString());
        tabMessages = new QWidget();
        tabMessages->setObjectName(QStringLiteral("tabMessages"));
        gridLayout_5 = new QGridLayout(tabMessages);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        fontSpinBox = new QSpinBox(tabMessages);
        fontSpinBox->setObjectName(QStringLiteral("fontSpinBox"));
        sizePolicy9.setHeightForWidth(fontSpinBox->sizePolicy().hasHeightForWidth());
        fontSpinBox->setSizePolicy(sizePolicy9);
        fontSpinBox->setMinimum(5);
        fontSpinBox->setValue(10);

        gridLayout_5->addWidget(fontSpinBox, 5, 1, 1, 1);

        historySpinBox = new QSpinBox(tabMessages);
        historySpinBox->setObjectName(QStringLiteral("historySpinBox"));
        sizePolicy9.setHeightForWidth(historySpinBox->sizePolicy().hasHeightForWidth());
        historySpinBox->setSizePolicy(sizePolicy9);
        historySpinBox->setMaximum(9999);
        historySpinBox->setValue(64);

        gridLayout_5->addWidget(historySpinBox, 6, 1, 1, 1);

        label_30 = new QLabel(tabMessages);
        label_30->setObjectName(QStringLiteral("label_30"));
        sizePolicy8.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy8);
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_30, 0, 0, 1, 1);

        avatarBox = new QSpinBox(tabMessages);
        avatarBox->setObjectName(QStringLiteral("avatarBox"));
        sizePolicy9.setHeightForWidth(avatarBox->sizePolicy().hasHeightForWidth());
        avatarBox->setSizePolicy(sizePolicy9);
        avatarBox->setMaximum(365);

        gridLayout_5->addWidget(avatarBox, 7, 1, 1, 1);

        labelFontSize = new QLabel(tabMessages);
        labelFontSize->setObjectName(QStringLiteral("labelFontSize"));
        sizePolicy8.setHeightForWidth(labelFontSize->sizePolicy().hasHeightForWidth());
        labelFontSize->setSizePolicy(sizePolicy8);
        labelFontSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(labelFontSize, 5, 0, 1, 1);

        label_8 = new QLabel(tabMessages);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy8.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy8);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_8, 7, 0, 1, 1);

        labelFontSize_2 = new QLabel(tabMessages);
        labelFontSize_2->setObjectName(QStringLiteral("labelFontSize_2"));
        sizePolicy8.setHeightForWidth(labelFontSize_2->sizePolicy().hasHeightForWidth());
        labelFontSize_2->setSizePolicy(sizePolicy8);
        labelFontSize_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(labelFontSize_2, 4, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        addIntelButton = new QToolButton(tabMessages);
        addIntelButton->setObjectName(QStringLiteral("addIntelButton"));
        sizePolicy8.setHeightForWidth(addIntelButton->sizePolicy().hasHeightForWidth());
        addIntelButton->setSizePolicy(sizePolicy8);
        addIntelButton->setMinimumSize(QSize(30, 0));

        horizontalLayout_5->addWidget(addIntelButton);

        delIntelButton = new QToolButton(tabMessages);
        delIntelButton->setObjectName(QStringLiteral("delIntelButton"));
        sizePolicy7.setHeightForWidth(delIntelButton->sizePolicy().hasHeightForWidth());
        delIntelButton->setSizePolicy(sizePolicy7);
        delIntelButton->setMinimumSize(QSize(30, 0));

        horizontalLayout_5->addWidget(delIntelButton);


        gridLayout_5->addLayout(horizontalLayout_5, 1, 3, 1, 1);

        labelFontSize_3 = new QLabel(tabMessages);
        labelFontSize_3->setObjectName(QStringLiteral("labelFontSize_3"));
        sizePolicy8.setHeightForWidth(labelFontSize_3->sizePolicy().hasHeightForWidth());
        labelFontSize_3->setSizePolicy(sizePolicy8);
        labelFontSize_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(labelFontSize_3, 3, 0, 1, 1);

        intelEdit = new QLineEdit(tabMessages);
        intelEdit->setObjectName(QStringLiteral("intelEdit"));

        gridLayout_5->addWidget(intelEdit, 1, 1, 1, 2);

        checkAvatar = new QCheckBox(tabMessages);
        checkAvatar->setObjectName(QStringLiteral("checkAvatar"));
        checkAvatar->setChecked(true);

        gridLayout_5->addWidget(checkAvatar, 3, 1, 1, 2);

        intelWidget = new QListWidget(tabMessages);
        intelWidget->setObjectName(QStringLiteral("intelWidget"));
        intelWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        intelWidget->setSortingEnabled(true);

        gridLayout_5->addWidget(intelWidget, 0, 1, 1, 3);

        verticalSpacer = new QSpacerItem(17, 47, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_5->addItem(verticalSpacer, 2, 1, 1, 1);

        fontComboBox = new QFontComboBox(tabMessages);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        sizePolicy7.setHeightForWidth(fontComboBox->sizePolicy().hasHeightForWidth());
        fontComboBox->setSizePolicy(sizePolicy7);

        gridLayout_5->addWidget(fontComboBox, 4, 1, 1, 2);

        label_5 = new QLabel(tabMessages);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy8.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy8);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_5, 6, 0, 1, 1);

        label_7 = new QLabel(tabMessages);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_7, 6, 2, 1, 1);

        label_9 = new QLabel(tabMessages);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_9, 7, 2, 1, 1);

        options->addTab(tabMessages, QString());
        tabPoller = new QWidget();
        tabPoller->setObjectName(QStringLiteral("tabPoller"));
        gridLayout_10 = new QGridLayout(tabPoller);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(tabPoller);
        label_10->setObjectName(QStringLiteral("label_10"));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy10);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_10);

        logsEdit = new QLineEdit(tabPoller);
        logsEdit->setObjectName(QStringLiteral("logsEdit"));

        horizontalLayout_4->addWidget(logsEdit);

        logsButton = new QToolButton(tabPoller);
        logsButton->setObjectName(QStringLiteral("logsButton"));

        horizontalLayout_4->addWidget(logsButton);


        gridLayout_10->addLayout(horizontalLayout_4, 0, 0, 1, 2);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        labelFontSize_4 = new QLabel(tabPoller);
        labelFontSize_4->setObjectName(QStringLiteral("labelFontSize_4"));
        sizePolicy2.setHeightForWidth(labelFontSize_4->sizePolicy().hasHeightForWidth());
        labelFontSize_4->setSizePolicy(sizePolicy2);
        labelFontSize_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(labelFontSize_4, 0, 0, 1, 1);

        checkOldIntel = new QCheckBox(tabPoller);
        checkOldIntel->setObjectName(QStringLiteral("checkOldIntel"));
        checkOldIntel->setChecked(true);

        gridLayout_9->addWidget(checkOldIntel, 0, 1, 1, 1);

        label_28 = new QLabel(tabPoller);
        label_28->setObjectName(QStringLiteral("label_28"));
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(1);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy11);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_28, 1, 0, 1, 1);

        maxEntriesSpinBox = new QSpinBox(tabPoller);
        maxEntriesSpinBox->setObjectName(QStringLiteral("maxEntriesSpinBox"));
        sizePolicy3.setHeightForWidth(maxEntriesSpinBox->sizePolicy().hasHeightForWidth());
        maxEntriesSpinBox->setSizePolicy(sizePolicy3);
        maxEntriesSpinBox->setMinimum(1);
        maxEntriesSpinBox->setMaximum(10000);
        maxEntriesSpinBox->setValue(50);

        gridLayout_9->addWidget(maxEntriesSpinBox, 1, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 1, 0, 2, 2);

        label_29 = new QLabel(tabPoller);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy7.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy7);

        gridLayout_10->addWidget(label_29, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 71, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_23 = new QLabel(tabPoller);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy7.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy7);
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_23);

        pollerSpinBox = new QSpinBox(tabPoller);
        pollerSpinBox->setObjectName(QStringLiteral("pollerSpinBox"));
        sizePolicy2.setHeightForWidth(pollerSpinBox->sizePolicy().hasHeightForWidth());
        pollerSpinBox->setSizePolicy(sizePolicy2);
        pollerSpinBox->setMinimum(100);
        pollerSpinBox->setMaximum(10000);
        pollerSpinBox->setValue(500);

        horizontalLayout_2->addWidget(pollerSpinBox);

        label_22 = new QLabel(tabPoller);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy7.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy7);

        horizontalLayout_2->addWidget(label_22);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_25 = new QLabel(tabPoller);
        label_25->setObjectName(QStringLiteral("label_25"));
        QSizePolicy sizePolicy12(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(1);
        sizePolicy12.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy12);
        label_25->setTextFormat(Qt::RichText);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_25->setWordWrap(true);

        horizontalLayout->addWidget(label_25);

        label_24 = new QLabel(tabPoller);
        label_24->setObjectName(QStringLiteral("label_24"));
        QSizePolicy sizePolicy13(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(1);
        sizePolicy13.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy13);
        label_24->setTextFormat(Qt::RichText);
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_24->setWordWrap(true);

        horizontalLayout->addWidget(label_24);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_10->addLayout(verticalLayout, 4, 0, 1, 2);

        options->addTab(tabPoller, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_8 = new QGridLayout(tab_2);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_35 = new QLabel(tab_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy8.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy8);
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_35, 0, 0, 1, 1);

        comboStyle = new QComboBox(tab_2);
        comboStyle->setObjectName(QStringLiteral("comboStyle"));
        QSizePolicy sizePolicy14(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy14.setHorizontalStretch(1);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(comboStyle->sizePolicy().hasHeightForWidth());
        comboStyle->setSizePolicy(sizePolicy14);

        gridLayout_8->addWidget(comboStyle, 0, 1, 1, 1);

        options->addTab(tab_2, QString());
        tabUpdates = new QWidget();
        tabUpdates->setObjectName(QStringLiteral("tabUpdates"));
        verticalLayout_5 = new QVBoxLayout(tabUpdates);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox = new QGroupBox(tabUpdates);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        checkUpdates = new QCheckBox(groupBox);
        checkUpdates->setObjectName(QStringLiteral("checkUpdates"));
        sizePolicy9.setHeightForWidth(checkUpdates->sizePolicy().hasHeightForWidth());
        checkUpdates->setSizePolicy(sizePolicy9);
        checkUpdates->setChecked(true);

        verticalLayout_2->addWidget(checkUpdates);

        buttonCheck = new QPushButton(groupBox);
        buttonCheck->setObjectName(QStringLiteral("buttonCheck"));

        verticalLayout_2->addWidget(buttonCheck);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tabUpdates);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioAudioSFML = new QRadioButton(groupBox_3);
        radioAudioSFML->setObjectName(QStringLiteral("radioAudioSFML"));
        radioAudioSFML->setChecked(true);

        verticalLayout_3->addWidget(radioAudioSFML);

        radioAudioQt = new QRadioButton(groupBox_3);
        radioAudioQt->setObjectName(QStringLiteral("radioAudioQt"));

        verticalLayout_3->addWidget(radioAudioQt);


        verticalLayout_4->addWidget(groupBox_3);

        checkDisableMusic = new QCheckBox(groupBox_2);
        checkDisableMusic->setObjectName(QStringLiteral("checkDisableMusic"));

        verticalLayout_4->addWidget(checkDisableMusic);


        verticalLayout_5->addWidget(groupBox_2);

        options->addTab(tabUpdates, QString());

        gridLayout->addWidget(options, 1, 0, 1, 1);

        QWidget::setTabOrder(statusCombo, statusTestButton);
        QWidget::setTabOrder(statusTestButton, essCombo);
        QWidget::setTabOrder(essCombo, essTestButton);
        QWidget::setTabOrder(essTestButton, essBox);
        QWidget::setTabOrder(essBox, volume);
        QWidget::setTabOrder(volume, refreshSpin);
        QWidget::setTabOrder(refreshSpin, smoothCheck);
        QWidget::setTabOrder(smoothCheck, autoPeriodSpin);
        QWidget::setTabOrder(autoPeriodSpin, autoRefreshSpin);
        QWidget::setTabOrder(autoRefreshSpin, tableView);
        QWidget::setTabOrder(tableView, ruleRemoveButton);
        QWidget::setTabOrder(ruleRemoveButton, ruleInsertButton);

        retranslateUi(Options);
        QObject::connect(buttonBox, SIGNAL(accepted()), Options, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Options, SLOT(reject()));

        options->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Options", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tableProxAlarms->setToolTip(QApplication::translate("Options", "Sounds that are played when enemies are reported at varying distances.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRemoveProx->setText(QApplication::translate("Options", "Remove Selected", Q_NULLPTR));
        btnInsertProx->setText(QApplication::translate("Options", "Insert Alert", Q_NULLPTR));
        options->setTabText(options->indexOf(tabProximity), QApplication::translate("Options", "Proximity", Q_NULLPTR));
        label_26->setText(QApplication::translate("Options", "Suppress alarms redundant if within", Q_NULLPTR));
        label_27->setText(QApplication::translate("Options", "seconds.", Q_NULLPTR));
        selfSuppressCheck->setText(QApplication::translate("Options", "Suppress alerts generated by my own intel reports.", Q_NULLPTR));
        label_3->setText(QApplication::translate("Options", "Status Requested:", Q_NULLPTR));
        statusTestButton->setText(QApplication::translate("Options", "...", Q_NULLPTR));
        label_14->setText(QApplication::translate("Options", "ESS Proximity:", Q_NULLPTR));
        essTestButton->setText(QApplication::translate("Options", "...", Q_NULLPTR));
        essBox->setText(QApplication::translate("Options", "Only alert on ESS when person is KOS.", Q_NULLPTR));
        label_4->setText(QApplication::translate("Options", "Volume:", Q_NULLPTR));
        options->setTabText(options->indexOf(alerts_tab), QApplication::translate("Options", "Alerts", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tableView->setToolTip(QApplication::translate("Options", "Rules to take action when expressions are seen in channels.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ruleRemoveButton->setText(QApplication::translate("Options", "Remove Rule", Q_NULLPTR));
        ruleInsertButton->setText(QApplication::translate("Options", "Insert Rule", Q_NULLPTR));
        options->setTabText(options->indexOf(rules_tab), QApplication::translate("Options", "Rules", Q_NULLPTR));
        label_6->setText(QApplication::translate("Options", "Clipboard KOS Checking:", Q_NULLPTR));
        kosCheck->setText(QString());
        label_32->setText(QApplication::translate("Options", "Check on double copy:", Q_NULLPTR));
        checkKosDouble->setText(QString());
        label_33->setText(QApplication::translate("Options", "(Require Ctrl-C twice on same data before sending to checker)", Q_NULLPTR));
        label_11->setText(QApplication::translate("Options", "Clipboard KOS:", Q_NULLPTR));
        clipKosTestButton->setText(QApplication::translate("Options", "...", Q_NULLPTR));
        label_12->setText(QApplication::translate("Options", "Clipboard not KOS:", Q_NULLPTR));
        clipNotKosTestButton->setText(QApplication::translate("Options", "...", Q_NULLPTR));
        label_34->setText(QApplication::translate("Options", "Failed to get Reply:", Q_NULLPTR));
        incompleteTestButton->setText(QApplication::translate("Options", "...", Q_NULLPTR));
        options->setTabText(options->indexOf(tab), QApplication::translate("Options", "KOS Checking", Q_NULLPTR));
        label_16->setText(QApplication::translate("Options", "Map refresh Interval:", Q_NULLPTR));
        label_19->setText(QApplication::translate("Options", "msecs", Q_NULLPTR));
        label_15->setText(QApplication::translate("Options", "Smooth auto-follow:", Q_NULLPTR));
        smoothCheck->setText(QString());
        mapEdit->setText(QApplication::translate("Options", "http://evemaps.dotlan.net/svg/", Q_NULLPTR));
        bridgeEdit->setText(QApplication::translate("Options", "http://eternaldusk.com/imp/jb/", Q_NULLPTR));
        label_21->setText(QApplication::translate("Options", "msecs", Q_NULLPTR));
        label_17->setText(QApplication::translate("Options", "Auto-follow reposition time:", Q_NULLPTR));
        label_20->setText(QApplication::translate("Options", "msecs", Q_NULLPTR));
        label_18->setText(QApplication::translate("Options", "Auto-follow refresh interval:", Q_NULLPTR));
        label_31->setText(QApplication::translate("Options", "Bridge Data:", Q_NULLPTR));
        label_13->setText(QApplication::translate("Options", "Maps:", Q_NULLPTR));
        options->setTabText(options->indexOf(map_tab), QApplication::translate("Options", "Map", Q_NULLPTR));
        label_30->setText(QApplication::translate("Options", "Intel Channels:", Q_NULLPTR));
        labelFontSize->setText(QApplication::translate("Options", "Font Size:", Q_NULLPTR));
        label_8->setText(QApplication::translate("Options", "Avatar Caching (days):", Q_NULLPTR));
        labelFontSize_2->setText(QApplication::translate("Options", "Font:", Q_NULLPTR));
        addIntelButton->setText(QApplication::translate("Options", "+", Q_NULLPTR));
        delIntelButton->setText(QApplication::translate("Options", "-", Q_NULLPTR));
        labelFontSize_3->setText(QApplication::translate("Options", "Show Avatar:", Q_NULLPTR));
        checkAvatar->setText(QString());
        fontComboBox->setCurrentText(QApplication::translate("Options", "Arial", Q_NULLPTR));
        label_5->setText(QApplication::translate("Options", "Message History:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Options", "(0 = Keep all)", Q_NULLPTR));
        label_9->setText(QApplication::translate("Options", "(0 = Do not override)", Q_NULLPTR));
        options->setTabText(options->indexOf(tabMessages), QApplication::translate("Options", "Messages", Q_NULLPTR));
        label_10->setText(QApplication::translate("Options", "ChatLogs:", Q_NULLPTR));
        logsButton->setText(QApplication::translate("Options", "...", Q_NULLPTR));
        labelFontSize_4->setText(QApplication::translate("Options", "Reload recent intel messages on restart:", Q_NULLPTR));
        checkOldIntel->setText(QString());
        label_28->setText(QApplication::translate("Options", "Maximum entries per channel to read on restart:", Q_NULLPTR));
        label_29->setText(QString());
        label_23->setText(QApplication::translate("Options", "Update Interval:", Q_NULLPTR));
        label_22->setText(QApplication::translate("Options", "msecs", Q_NULLPTR));
        label_25->setText(QApplication::translate("Options", "<html><head/><body><p><span style=\" font-weight:600;\">Note:</span></p></body></html>", Q_NULLPTR));
        label_24->setText(QApplication::translate("Options", "<html><head/><body><p>The update interval affects how often the poller checks the active logs when using the fallback poller. The fallback poller is currently used on Windows only. Linux uses an operating system hook to enable immediate updates.</p></body></html>", Q_NULLPTR));
        options->setTabText(options->indexOf(tabPoller), QApplication::translate("Options", "Poller", Q_NULLPTR));
        label_35->setText(QApplication::translate("Options", "Style:", Q_NULLPTR));
        options->setTabText(options->indexOf(tab_2), QApplication::translate("Options", "User Interface", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Options", "Updates", Q_NULLPTR));
        checkUpdates->setText(QApplication::translate("Options", "Check for application updates at startup.", Q_NULLPTR));
        buttonCheck->setText(QApplication::translate("Options", "Check Now", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Options", "Audio", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Options", "Backend:", Q_NULLPTR));
        radioAudioSFML->setText(QApplication::translate("Options", "SFML (OpenAL)", Q_NULLPTR));
        radioAudioQt->setText(QApplication::translate("Options", "&Qt", Q_NULLPTR));
        checkDisableMusic->setText(QApplication::translate("Options", "Disable music on About window", Q_NULLPTR));
        options->setTabText(options->indexOf(tabUpdates), QApplication::translate("Options", "Advanced", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
