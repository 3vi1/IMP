/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(1104, 571);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graphics/impicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Options->setWindowIcon(icon);
        gridLayout = new QGridLayout(Options);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(Options);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        options = new QTabWidget(Options);
        options->setObjectName(QString::fromUtf8("options"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(options->sizePolicy().hasHeightForWidth());
        options->setSizePolicy(sizePolicy);
        options->setTabShape(QTabWidget::Rounded);
        tabProximity = new QWidget();
        tabProximity->setObjectName(QString::fromUtf8("tabProximity"));
        gridLayout_12 = new QGridLayout(tabProximity);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        tableProxAlarms = new QTableView(tabProximity);
        tableProxAlarms->setObjectName(QString::fromUtf8("tableProxAlarms"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableProxAlarms->sizePolicy().hasHeightForWidth());
        tableProxAlarms->setSizePolicy(sizePolicy1);

        gridLayout_12->addWidget(tableProxAlarms, 0, 0, 1, 2);

        btnRemoveProx = new QPushButton(tabProximity);
        btnRemoveProx->setObjectName(QString::fromUtf8("btnRemoveProx"));

        gridLayout_12->addWidget(btnRemoveProx, 1, 0, 1, 1);

        btnInsertProx = new QPushButton(tabProximity);
        btnInsertProx->setObjectName(QString::fromUtf8("btnInsertProx"));

        gridLayout_12->addWidget(btnInsertProx, 1, 1, 1, 1);

        options->addTab(tabProximity, QString());
        alerts_tab = new QWidget();
        alerts_tab->setObjectName(QString::fromUtf8("alerts_tab"));
        gridLayout_4 = new QGridLayout(alerts_tab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_26 = new QLabel(alerts_tab);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_26);

        redundantSpinBox = new QSpinBox(alerts_tab);
        redundantSpinBox->setObjectName(QString::fromUtf8("redundantSpinBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(redundantSpinBox->sizePolicy().hasHeightForWidth());
        redundantSpinBox->setSizePolicy(sizePolicy3);
        redundantSpinBox->setMaximum(300);
        redundantSpinBox->setValue(30);

        horizontalLayout_3->addWidget(redundantSpinBox);

        label_27 = new QLabel(alerts_tab);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(label_27);


        gridLayout_4->addLayout(horizontalLayout_3, 0, 1, 1, 3);

        selfSuppressCheck = new QCheckBox(alerts_tab);
        selfSuppressCheck->setObjectName(QString::fromUtf8("selfSuppressCheck"));
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
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy6);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_3, 3, 0, 1, 2);

        statusCombo = new QComboBox(alerts_tab);
        statusCombo->setObjectName(QString::fromUtf8("statusCombo"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(statusCombo->sizePolicy().hasHeightForWidth());
        statusCombo->setSizePolicy(sizePolicy7);

        gridLayout_4->addWidget(statusCombo, 3, 2, 1, 1);

        statusTestButton = new QToolButton(alerts_tab);
        statusTestButton->setObjectName(QString::fromUtf8("statusTestButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/graphics/volume-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        statusTestButton->setIcon(icon1);

        gridLayout_4->addWidget(statusTestButton, 3, 4, 1, 1);

        label_14 = new QLabel(alerts_tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy6.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy6);
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_14, 4, 0, 1, 2);

        essCombo = new QComboBox(alerts_tab);
        essCombo->setObjectName(QString::fromUtf8("essCombo"));
        sizePolicy7.setHeightForWidth(essCombo->sizePolicy().hasHeightForWidth());
        essCombo->setSizePolicy(sizePolicy7);

        gridLayout_4->addWidget(essCombo, 4, 2, 1, 1);

        essTestButton = new QToolButton(alerts_tab);
        essTestButton->setObjectName(QString::fromUtf8("essTestButton"));
        essTestButton->setIcon(icon1);

        gridLayout_4->addWidget(essTestButton, 4, 4, 1, 1);

        essBox = new QCheckBox(alerts_tab);
        essBox->setObjectName(QString::fromUtf8("essBox"));
        essBox->setChecked(true);

        gridLayout_4->addWidget(essBox, 5, 2, 1, 2);

        label_4 = new QLabel(alerts_tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_4, 6, 0, 1, 1);

        volume = new QSlider(alerts_tab);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setMaximum(100);
        volume->setValue(100);
        volume->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(volume, 6, 2, 1, 1);

        options->addTab(alerts_tab, QString());
        rules_tab = new QWidget();
        rules_tab->setObjectName(QString::fromUtf8("rules_tab"));
        gridLayout_2 = new QGridLayout(rules_tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView = new QTableView(rules_tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(tableView, 0, 0, 1, 2);

        ruleRemoveButton = new QPushButton(rules_tab);
        ruleRemoveButton->setObjectName(QString::fromUtf8("ruleRemoveButton"));

        gridLayout_2->addWidget(ruleRemoveButton, 1, 0, 1, 1);

        ruleInsertButton = new QPushButton(rules_tab);
        ruleInsertButton->setObjectName(QString::fromUtf8("ruleInsertButton"));

        gridLayout_2->addWidget(ruleInsertButton, 1, 1, 1, 1);

        options->addTab(rules_tab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy8);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_6, 0, 0, 1, 1);

        kosCheck = new QCheckBox(tab);
        kosCheck->setObjectName(QString::fromUtf8("kosCheck"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(kosCheck->sizePolicy().hasHeightForWidth());
        kosCheck->setSizePolicy(sizePolicy9);
        kosCheck->setChecked(true);

        gridLayout_6->addWidget(kosCheck, 0, 1, 1, 1);

        label_32 = new QLabel(tab);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        sizePolicy8.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy8);
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_32, 1, 0, 1, 1);

        checkKosDouble = new QCheckBox(tab);
        checkKosDouble->setObjectName(QString::fromUtf8("checkKosDouble"));
        sizePolicy9.setHeightForWidth(checkKosDouble->sizePolicy().hasHeightForWidth());
        checkKosDouble->setSizePolicy(sizePolicy9);
        checkKosDouble->setChecked(true);

        gridLayout_6->addWidget(checkKosDouble, 1, 1, 1, 1);

        label_33 = new QLabel(tab);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setWordWrap(true);

        gridLayout_6->addWidget(label_33, 1, 2, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy8.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy8);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_11, 2, 0, 1, 1);

        clipKosCombo = new QComboBox(tab);
        clipKosCombo->setObjectName(QString::fromUtf8("clipKosCombo"));
        sizePolicy7.setHeightForWidth(clipKosCombo->sizePolicy().hasHeightForWidth());
        clipKosCombo->setSizePolicy(sizePolicy7);

        gridLayout_6->addWidget(clipKosCombo, 2, 1, 1, 2);

        clipKosTestButton = new QToolButton(tab);
        clipKosTestButton->setObjectName(QString::fromUtf8("clipKosTestButton"));
        clipKosTestButton->setIcon(icon1);

        gridLayout_6->addWidget(clipKosTestButton, 2, 3, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy8.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy8);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_12, 3, 0, 1, 1);

        clipNotKosCombo = new QComboBox(tab);
        clipNotKosCombo->setObjectName(QString::fromUtf8("clipNotKosCombo"));
        sizePolicy7.setHeightForWidth(clipNotKosCombo->sizePolicy().hasHeightForWidth());
        clipNotKosCombo->setSizePolicy(sizePolicy7);

        gridLayout_6->addWidget(clipNotKosCombo, 3, 1, 1, 2);

        clipNotKosTestButton = new QToolButton(tab);
        clipNotKosTestButton->setObjectName(QString::fromUtf8("clipNotKosTestButton"));
        clipNotKosTestButton->setIcon(icon1);

        gridLayout_6->addWidget(clipNotKosTestButton, 3, 3, 1, 1);

        label_34 = new QLabel(tab);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        sizePolicy8.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy8);
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_34, 4, 0, 1, 1);

        comboIncomplete = new QComboBox(tab);
        comboIncomplete->setObjectName(QString::fromUtf8("comboIncomplete"));
        sizePolicy7.setHeightForWidth(comboIncomplete->sizePolicy().hasHeightForWidth());
        comboIncomplete->setSizePolicy(sizePolicy7);

        gridLayout_6->addWidget(comboIncomplete, 4, 1, 1, 2);

        incompleteTestButton = new QToolButton(tab);
        incompleteTestButton->setObjectName(QString::fromUtf8("incompleteTestButton"));
        incompleteTestButton->setIcon(icon1);

        gridLayout_6->addWidget(incompleteTestButton, 4, 3, 1, 1);

        options->addTab(tab, QString());
        map_tab = new QWidget();
        map_tab->setObjectName(QString::fromUtf8("map_tab"));
        gridLayout_3 = new QGridLayout(map_tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_16 = new QLabel(map_tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_16, 2, 0, 1, 1);

        autoPeriodSpin = new QSpinBox(map_tab);
        autoPeriodSpin->setObjectName(QString::fromUtf8("autoPeriodSpin"));
        sizePolicy9.setHeightForWidth(autoPeriodSpin->sizePolicy().hasHeightForWidth());
        autoPeriodSpin->setSizePolicy(sizePolicy9);
        autoPeriodSpin->setMinimum(500);
        autoPeriodSpin->setMaximum(10000);
        autoPeriodSpin->setValue(4000);

        gridLayout_3->addWidget(autoPeriodSpin, 4, 3, 1, 1);

        refreshSpin = new QSpinBox(map_tab);
        refreshSpin->setObjectName(QString::fromUtf8("refreshSpin"));
        sizePolicy9.setHeightForWidth(refreshSpin->sizePolicy().hasHeightForWidth());
        refreshSpin->setSizePolicy(sizePolicy9);
        refreshSpin->setMinimum(1000);
        refreshSpin->setMaximum(10000);
        refreshSpin->setValue(1000);

        gridLayout_3->addWidget(refreshSpin, 2, 3, 1, 1);

        label_19 = new QLabel(map_tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_19, 2, 4, 1, 1);

        label_15 = new QLabel(map_tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_15, 3, 0, 1, 1);

        smoothCheck = new QCheckBox(map_tab);
        smoothCheck->setObjectName(QString::fromUtf8("smoothCheck"));
        smoothCheck->setChecked(true);

        gridLayout_3->addWidget(smoothCheck, 3, 3, 1, 1);

        mapEdit = new QLineEdit(map_tab);
        mapEdit->setObjectName(QString::fromUtf8("mapEdit"));

        gridLayout_3->addWidget(mapEdit, 0, 3, 1, 2);

        bridgeEdit = new QLineEdit(map_tab);
        bridgeEdit->setObjectName(QString::fromUtf8("bridgeEdit"));

        gridLayout_3->addWidget(bridgeEdit, 1, 3, 1, 2);

        label_21 = new QLabel(map_tab);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_21, 5, 4, 1, 1);

        label_17 = new QLabel(map_tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_17, 4, 0, 1, 1);

        label_20 = new QLabel(map_tab);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_20, 4, 4, 1, 1);

        label_18 = new QLabel(map_tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_18, 5, 0, 1, 1);

        autoRefreshSpin = new QSpinBox(map_tab);
        autoRefreshSpin->setObjectName(QString::fromUtf8("autoRefreshSpin"));
        sizePolicy9.setHeightForWidth(autoRefreshSpin->sizePolicy().hasHeightForWidth());
        autoRefreshSpin->setSizePolicy(sizePolicy9);
        autoRefreshSpin->setMinimum(5);
        autoRefreshSpin->setMaximum(300);
        autoRefreshSpin->setValue(33);

        gridLayout_3->addWidget(autoRefreshSpin, 5, 3, 1, 1);

        label_31 = new QLabel(map_tab);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        sizePolicy6.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy6);
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_31, 1, 0, 1, 1);

        label_13 = new QLabel(map_tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy6.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy6);
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        options->addTab(map_tab, QString());
        tabMessages = new QWidget();
        tabMessages->setObjectName(QString::fromUtf8("tabMessages"));
        gridLayout_5 = new QGridLayout(tabMessages);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        fontSpinBox = new QSpinBox(tabMessages);
        fontSpinBox->setObjectName(QString::fromUtf8("fontSpinBox"));
        sizePolicy9.setHeightForWidth(fontSpinBox->sizePolicy().hasHeightForWidth());
        fontSpinBox->setSizePolicy(sizePolicy9);
        fontSpinBox->setMinimum(5);
        fontSpinBox->setValue(10);

        gridLayout_5->addWidget(fontSpinBox, 5, 1, 1, 1);

        historySpinBox = new QSpinBox(tabMessages);
        historySpinBox->setObjectName(QString::fromUtf8("historySpinBox"));
        sizePolicy9.setHeightForWidth(historySpinBox->sizePolicy().hasHeightForWidth());
        historySpinBox->setSizePolicy(sizePolicy9);
        historySpinBox->setMaximum(9999);
        historySpinBox->setValue(64);

        gridLayout_5->addWidget(historySpinBox, 6, 1, 1, 1);

        label_30 = new QLabel(tabMessages);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        sizePolicy8.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy8);
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_30, 0, 0, 1, 1);

        avatarBox = new QSpinBox(tabMessages);
        avatarBox->setObjectName(QString::fromUtf8("avatarBox"));
        sizePolicy9.setHeightForWidth(avatarBox->sizePolicy().hasHeightForWidth());
        avatarBox->setSizePolicy(sizePolicy9);
        avatarBox->setMaximum(365);

        gridLayout_5->addWidget(avatarBox, 7, 1, 1, 1);

        labelFontSize = new QLabel(tabMessages);
        labelFontSize->setObjectName(QString::fromUtf8("labelFontSize"));
        sizePolicy8.setHeightForWidth(labelFontSize->sizePolicy().hasHeightForWidth());
        labelFontSize->setSizePolicy(sizePolicy8);
        labelFontSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(labelFontSize, 5, 0, 1, 1);

        label_8 = new QLabel(tabMessages);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy8.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy8);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_8, 7, 0, 1, 1);

        labelFontSize_2 = new QLabel(tabMessages);
        labelFontSize_2->setObjectName(QString::fromUtf8("labelFontSize_2"));
        sizePolicy8.setHeightForWidth(labelFontSize_2->sizePolicy().hasHeightForWidth());
        labelFontSize_2->setSizePolicy(sizePolicy8);
        labelFontSize_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(labelFontSize_2, 4, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        addIntelButton = new QToolButton(tabMessages);
        addIntelButton->setObjectName(QString::fromUtf8("addIntelButton"));
        sizePolicy8.setHeightForWidth(addIntelButton->sizePolicy().hasHeightForWidth());
        addIntelButton->setSizePolicy(sizePolicy8);
        addIntelButton->setMinimumSize(QSize(30, 0));

        horizontalLayout_5->addWidget(addIntelButton);

        delIntelButton = new QToolButton(tabMessages);
        delIntelButton->setObjectName(QString::fromUtf8("delIntelButton"));
        sizePolicy7.setHeightForWidth(delIntelButton->sizePolicy().hasHeightForWidth());
        delIntelButton->setSizePolicy(sizePolicy7);
        delIntelButton->setMinimumSize(QSize(30, 0));

        horizontalLayout_5->addWidget(delIntelButton);


        gridLayout_5->addLayout(horizontalLayout_5, 1, 3, 1, 1);

        labelFontSize_3 = new QLabel(tabMessages);
        labelFontSize_3->setObjectName(QString::fromUtf8("labelFontSize_3"));
        sizePolicy8.setHeightForWidth(labelFontSize_3->sizePolicy().hasHeightForWidth());
        labelFontSize_3->setSizePolicy(sizePolicy8);
        labelFontSize_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(labelFontSize_3, 3, 0, 1, 1);

        intelEdit = new QLineEdit(tabMessages);
        intelEdit->setObjectName(QString::fromUtf8("intelEdit"));

        gridLayout_5->addWidget(intelEdit, 1, 1, 1, 2);

        checkAvatar = new QCheckBox(tabMessages);
        checkAvatar->setObjectName(QString::fromUtf8("checkAvatar"));
        checkAvatar->setChecked(true);

        gridLayout_5->addWidget(checkAvatar, 3, 1, 1, 2);

        intelWidget = new QListWidget(tabMessages);
        intelWidget->setObjectName(QString::fromUtf8("intelWidget"));
        intelWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        intelWidget->setSortingEnabled(true);

        gridLayout_5->addWidget(intelWidget, 0, 1, 1, 3);

        verticalSpacer = new QSpacerItem(17, 47, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_5->addItem(verticalSpacer, 2, 1, 1, 1);

        fontComboBox = new QFontComboBox(tabMessages);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        sizePolicy7.setHeightForWidth(fontComboBox->sizePolicy().hasHeightForWidth());
        fontComboBox->setSizePolicy(sizePolicy7);

        gridLayout_5->addWidget(fontComboBox, 4, 1, 1, 2);

        label_5 = new QLabel(tabMessages);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy8.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy8);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_5, 6, 0, 1, 1);

        label_7 = new QLabel(tabMessages);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_7, 6, 2, 1, 1);

        label_9 = new QLabel(tabMessages);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_9, 7, 2, 1, 1);

        options->addTab(tabMessages, QString());
        tabPoller = new QWidget();
        tabPoller->setObjectName(QString::fromUtf8("tabPoller"));
        gridLayout_10 = new QGridLayout(tabPoller);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_10 = new QLabel(tabPoller);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy10);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_10);

        logsEdit = new QLineEdit(tabPoller);
        logsEdit->setObjectName(QString::fromUtf8("logsEdit"));

        horizontalLayout_4->addWidget(logsEdit);

        logsButton = new QToolButton(tabPoller);
        logsButton->setObjectName(QString::fromUtf8("logsButton"));

        horizontalLayout_4->addWidget(logsButton);


        gridLayout_10->addLayout(horizontalLayout_4, 0, 0, 1, 2);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        labelFontSize_4 = new QLabel(tabPoller);
        labelFontSize_4->setObjectName(QString::fromUtf8("labelFontSize_4"));
        sizePolicy2.setHeightForWidth(labelFontSize_4->sizePolicy().hasHeightForWidth());
        labelFontSize_4->setSizePolicy(sizePolicy2);
        labelFontSize_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(labelFontSize_4, 0, 0, 1, 1);

        checkOldIntel = new QCheckBox(tabPoller);
        checkOldIntel->setObjectName(QString::fromUtf8("checkOldIntel"));
        checkOldIntel->setChecked(true);

        gridLayout_9->addWidget(checkOldIntel, 0, 1, 1, 1);

        label_28 = new QLabel(tabPoller);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(1);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy11);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_28, 1, 0, 1, 1);

        maxEntriesSpinBox = new QSpinBox(tabPoller);
        maxEntriesSpinBox->setObjectName(QString::fromUtf8("maxEntriesSpinBox"));
        sizePolicy3.setHeightForWidth(maxEntriesSpinBox->sizePolicy().hasHeightForWidth());
        maxEntriesSpinBox->setSizePolicy(sizePolicy3);
        maxEntriesSpinBox->setMinimum(1);
        maxEntriesSpinBox->setMaximum(10000);
        maxEntriesSpinBox->setValue(50);

        gridLayout_9->addWidget(maxEntriesSpinBox, 1, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 1, 0, 2, 2);

        label_29 = new QLabel(tabPoller);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy7.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy7);

        gridLayout_10->addWidget(label_29, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 71, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_23 = new QLabel(tabPoller);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy7.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy7);
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_23);

        pollerSpinBox = new QSpinBox(tabPoller);
        pollerSpinBox->setObjectName(QString::fromUtf8("pollerSpinBox"));
        sizePolicy2.setHeightForWidth(pollerSpinBox->sizePolicy().hasHeightForWidth());
        pollerSpinBox->setSizePolicy(sizePolicy2);
        pollerSpinBox->setMinimum(100);
        pollerSpinBox->setMaximum(10000);
        pollerSpinBox->setValue(500);

        horizontalLayout_2->addWidget(pollerSpinBox);

        label_22 = new QLabel(tabPoller);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy7.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy7);

        horizontalLayout_2->addWidget(label_22);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_25 = new QLabel(tabPoller);
        label_25->setObjectName(QString::fromUtf8("label_25"));
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
        label_24->setObjectName(QString::fromUtf8("label_24"));
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
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_8 = new QGridLayout(tab_2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_35 = new QLabel(tab_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        sizePolicy8.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy8);
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_35, 0, 0, 1, 1);

        comboStyle = new QComboBox(tab_2);
        comboStyle->setObjectName(QString::fromUtf8("comboStyle"));
        QSizePolicy sizePolicy14(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy14.setHorizontalStretch(1);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(comboStyle->sizePolicy().hasHeightForWidth());
        comboStyle->setSizePolicy(sizePolicy14);

        gridLayout_8->addWidget(comboStyle, 0, 1, 1, 1);

        options->addTab(tab_2, QString());
        tabUpdates = new QWidget();
        tabUpdates->setObjectName(QString::fromUtf8("tabUpdates"));
        verticalLayout_5 = new QVBoxLayout(tabUpdates);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox = new QGroupBox(tabUpdates);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkUpdates = new QCheckBox(groupBox);
        checkUpdates->setObjectName(QString::fromUtf8("checkUpdates"));
        sizePolicy9.setHeightForWidth(checkUpdates->sizePolicy().hasHeightForWidth());
        checkUpdates->setSizePolicy(sizePolicy9);
        checkUpdates->setChecked(true);

        verticalLayout_2->addWidget(checkUpdates);

        buttonCheck = new QPushButton(groupBox);
        buttonCheck->setObjectName(QString::fromUtf8("buttonCheck"));

        verticalLayout_2->addWidget(buttonCheck);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tabUpdates);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioAudioSFML = new QRadioButton(groupBox_3);
        radioAudioSFML->setObjectName(QString::fromUtf8("radioAudioSFML"));
        radioAudioSFML->setChecked(true);

        verticalLayout_3->addWidget(radioAudioSFML);

        radioAudioQt = new QRadioButton(groupBox_3);
        radioAudioQt->setObjectName(QString::fromUtf8("radioAudioQt"));

        verticalLayout_3->addWidget(radioAudioQt);


        verticalLayout_4->addWidget(groupBox_3);

        checkDisableMusic = new QCheckBox(groupBox_2);
        checkDisableMusic->setObjectName(QString::fromUtf8("checkDisableMusic"));

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
        Options->setWindowTitle(QCoreApplication::translate("Options", "Options", nullptr));
#if QT_CONFIG(tooltip)
        tableProxAlarms->setToolTip(QCoreApplication::translate("Options", "Sounds that are played when enemies are reported at varying distances.", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRemoveProx->setText(QCoreApplication::translate("Options", "Remove Selected", nullptr));
        btnInsertProx->setText(QCoreApplication::translate("Options", "Insert Alert", nullptr));
        options->setTabText(options->indexOf(tabProximity), QCoreApplication::translate("Options", "Proximity", nullptr));
        label_26->setText(QCoreApplication::translate("Options", "Suppress alarms redundant if within", nullptr));
        label_27->setText(QCoreApplication::translate("Options", "seconds.", nullptr));
        selfSuppressCheck->setText(QCoreApplication::translate("Options", "Suppress alerts generated by my own intel reports.", nullptr));
        label_3->setText(QCoreApplication::translate("Options", "Status Requested:", nullptr));
        statusTestButton->setText(QCoreApplication::translate("Options", "...", nullptr));
        label_14->setText(QCoreApplication::translate("Options", "ESS Proximity:", nullptr));
        essTestButton->setText(QCoreApplication::translate("Options", "...", nullptr));
        essBox->setText(QCoreApplication::translate("Options", "Only alert on ESS when person is KOS.", nullptr));
        label_4->setText(QCoreApplication::translate("Options", "Volume:", nullptr));
        options->setTabText(options->indexOf(alerts_tab), QCoreApplication::translate("Options", "Alerts", nullptr));
#if QT_CONFIG(tooltip)
        tableView->setToolTip(QCoreApplication::translate("Options", "Rules to take action when expressions are seen in channels.", nullptr));
#endif // QT_CONFIG(tooltip)
        ruleRemoveButton->setText(QCoreApplication::translate("Options", "Remove Rule", nullptr));
        ruleInsertButton->setText(QCoreApplication::translate("Options", "Insert Rule", nullptr));
        options->setTabText(options->indexOf(rules_tab), QCoreApplication::translate("Options", "Rules", nullptr));
        label_6->setText(QCoreApplication::translate("Options", "Clipboard KOS Checking:", nullptr));
        kosCheck->setText(QString());
        label_32->setText(QCoreApplication::translate("Options", "Check on double copy:", nullptr));
        checkKosDouble->setText(QString());
        label_33->setText(QCoreApplication::translate("Options", "(Require Ctrl-C twice on same data before sending to checker)", nullptr));
        label_11->setText(QCoreApplication::translate("Options", "Clipboard KOS:", nullptr));
        clipKosTestButton->setText(QCoreApplication::translate("Options", "...", nullptr));
        label_12->setText(QCoreApplication::translate("Options", "Clipboard not KOS:", nullptr));
        clipNotKosTestButton->setText(QCoreApplication::translate("Options", "...", nullptr));
        label_34->setText(QCoreApplication::translate("Options", "Failed to get Reply:", nullptr));
        incompleteTestButton->setText(QCoreApplication::translate("Options", "...", nullptr));
        options->setTabText(options->indexOf(tab), QCoreApplication::translate("Options", "KOS Checking", nullptr));
        label_16->setText(QCoreApplication::translate("Options", "Map refresh Interval:", nullptr));
        label_19->setText(QCoreApplication::translate("Options", "msecs", nullptr));
        label_15->setText(QCoreApplication::translate("Options", "Smooth auto-follow:", nullptr));
        smoothCheck->setText(QString());
        mapEdit->setText(QCoreApplication::translate("Options", "http://evemaps.dotlan.net/svg/", nullptr));
        bridgeEdit->setText(QCoreApplication::translate("Options", "http://eternaldusk.com/imp/jb/", nullptr));
        label_21->setText(QCoreApplication::translate("Options", "msecs", nullptr));
        label_17->setText(QCoreApplication::translate("Options", "Auto-follow reposition time:", nullptr));
        label_20->setText(QCoreApplication::translate("Options", "msecs", nullptr));
        label_18->setText(QCoreApplication::translate("Options", "Auto-follow refresh interval:", nullptr));
        label_31->setText(QCoreApplication::translate("Options", "Bridge Data:", nullptr));
        label_13->setText(QCoreApplication::translate("Options", "Maps:", nullptr));
        options->setTabText(options->indexOf(map_tab), QCoreApplication::translate("Options", "Map", nullptr));
        label_30->setText(QCoreApplication::translate("Options", "Intel Channels:", nullptr));
        labelFontSize->setText(QCoreApplication::translate("Options", "Font Size:", nullptr));
        label_8->setText(QCoreApplication::translate("Options", "Avatar Caching (days):", nullptr));
        labelFontSize_2->setText(QCoreApplication::translate("Options", "Font:", nullptr));
        addIntelButton->setText(QCoreApplication::translate("Options", "+", nullptr));
        delIntelButton->setText(QCoreApplication::translate("Options", "-", nullptr));
        labelFontSize_3->setText(QCoreApplication::translate("Options", "Show Avatar:", nullptr));
        checkAvatar->setText(QString());
        fontComboBox->setCurrentText(QCoreApplication::translate("Options", "Arial", nullptr));
        label_5->setText(QCoreApplication::translate("Options", "Message History:", nullptr));
        label_7->setText(QCoreApplication::translate("Options", "(0 = Keep all)", nullptr));
        label_9->setText(QCoreApplication::translate("Options", "(0 = Do not override)", nullptr));
        options->setTabText(options->indexOf(tabMessages), QCoreApplication::translate("Options", "Messages", nullptr));
        label_10->setText(QCoreApplication::translate("Options", "ChatLogs:", nullptr));
        logsButton->setText(QCoreApplication::translate("Options", "...", nullptr));
        labelFontSize_4->setText(QCoreApplication::translate("Options", "Reload recent intel messages on restart:", nullptr));
        checkOldIntel->setText(QString());
        label_28->setText(QCoreApplication::translate("Options", "Maximum entries per channel to read on restart:", nullptr));
        label_29->setText(QString());
        label_23->setText(QCoreApplication::translate("Options", "Update Interval:", nullptr));
        label_22->setText(QCoreApplication::translate("Options", "msecs", nullptr));
        label_25->setText(QCoreApplication::translate("Options", "<html><head/><body><p><span style=\" font-weight:600;\">Note:</span></p></body></html>", nullptr));
        label_24->setText(QCoreApplication::translate("Options", "<html><head/><body><p>The update interval affects how often the poller checks the active logs when using the fallback poller. The fallback poller is currently used on Windows only. Linux uses an operating system hook to enable immediate updates.</p></body></html>", nullptr));
        options->setTabText(options->indexOf(tabPoller), QCoreApplication::translate("Options", "Poller", nullptr));
        label_35->setText(QCoreApplication::translate("Options", "Style:", nullptr));
        options->setTabText(options->indexOf(tab_2), QCoreApplication::translate("Options", "User Interface", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Options", "Updates", nullptr));
        checkUpdates->setText(QCoreApplication::translate("Options", "Check for application updates at startup.", nullptr));
        buttonCheck->setText(QCoreApplication::translate("Options", "Check Now", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Options", "Audio", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Options", "Backend:", nullptr));
        radioAudioSFML->setText(QCoreApplication::translate("Options", "SFML (OpenAL)", nullptr));
        radioAudioQt->setText(QCoreApplication::translate("Options", "&Qt", nullptr));
        checkDisableMusic->setText(QCoreApplication::translate("Options", "Disable music on About window", nullptr));
        options->setTabText(options->indexOf(tabUpdates), QCoreApplication::translate("Options", "Advanced", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
