/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "chatview.h"
#include "svgmapview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionOptions;
    QAction *actionAuto_follow;
    QAction *actionF_YH5B;
    QAction *actionN_RMSH;
    QAction *actionFindSystem;
    QAction *actionShow_Bridges;
    QAction *actionSave_As_Theme;
    QAction *actionFindMessages;
    QAction *actionCustomize;
    QAction *actionReset_Rotation;
    QAction *action_Always_on_Top;
    QAction *action_Frameless_Window;
    QAction *action_Overlay_Mode;
    QAction *action_Menu_Toggle;
    QAction *actionToggle_Message_List;
    QAction *actionTest_Message;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    SvgMapView *mapView;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuOptions;
    QMenu *menuDebug;
    QMenu *menuMap;
    QMenu *menuFind;
    QMenu *menuTheme;
    QMenu *menuPilots;
    QMenu *menu_Window;
    QMenu *menu_View;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    ChatView *listView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(885, 512);
        QFont font;
        font.setFamily(QString::fromUtf8("FreeSerif"));
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graphics/impicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setDocumentMode(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actionAuto_follow = new QAction(MainWindow);
        actionAuto_follow->setObjectName(QString::fromUtf8("actionAuto_follow"));
        actionAuto_follow->setCheckable(true);
        actionAuto_follow->setChecked(true);
        actionF_YH5B = new QAction(MainWindow);
        actionF_YH5B->setObjectName(QString::fromUtf8("actionF_YH5B"));
        actionN_RMSH = new QAction(MainWindow);
        actionN_RMSH->setObjectName(QString::fromUtf8("actionN_RMSH"));
        actionFindSystem = new QAction(MainWindow);
        actionFindSystem->setObjectName(QString::fromUtf8("actionFindSystem"));
        actionShow_Bridges = new QAction(MainWindow);
        actionShow_Bridges->setObjectName(QString::fromUtf8("actionShow_Bridges"));
        actionShow_Bridges->setCheckable(true);
        actionSave_As_Theme = new QAction(MainWindow);
        actionSave_As_Theme->setObjectName(QString::fromUtf8("actionSave_As_Theme"));
        actionFindMessages = new QAction(MainWindow);
        actionFindMessages->setObjectName(QString::fromUtf8("actionFindMessages"));
        actionCustomize = new QAction(MainWindow);
        actionCustomize->setObjectName(QString::fromUtf8("actionCustomize"));
        actionReset_Rotation = new QAction(MainWindow);
        actionReset_Rotation->setObjectName(QString::fromUtf8("actionReset_Rotation"));
        action_Always_on_Top = new QAction(MainWindow);
        action_Always_on_Top->setObjectName(QString::fromUtf8("action_Always_on_Top"));
        action_Always_on_Top->setCheckable(true);
        action_Frameless_Window = new QAction(MainWindow);
        action_Frameless_Window->setObjectName(QString::fromUtf8("action_Frameless_Window"));
        action_Frameless_Window->setCheckable(false);
        action_Overlay_Mode = new QAction(MainWindow);
        action_Overlay_Mode->setObjectName(QString::fromUtf8("action_Overlay_Mode"));
        action_Overlay_Mode->setCheckable(true);
        action_Overlay_Mode->setChecked(false);
        action_Menu_Toggle = new QAction(MainWindow);
        action_Menu_Toggle->setObjectName(QString::fromUtf8("action_Menu_Toggle"));
        actionToggle_Message_List = new QAction(MainWindow);
        actionToggle_Message_List->setObjectName(QString::fromUtf8("actionToggle_Message_List"));
        actionTest_Message = new QAction(MainWindow);
        actionTest_Message->setObjectName(QString::fromUtf8("actionTest_Message"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        mapView = new SvgMapView(centralWidget);
        mapView->setObjectName(QString::fromUtf8("mapView"));
        sizePolicy.setHeightForWidth(mapView->sizePolicy().hasHeightForWidth());
        mapView->setSizePolicy(sizePolicy);
        mapView->setMinimumSize(QSize(0, 0));
        mapView->setAutoFillBackground(true);

        gridLayout_2->addWidget(mapView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 885, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tahoma"));
        font1.setBold(true);
        font1.setWeight(75);
        menuBar->setFont(font1);
        menuBar->setAutoFillBackground(true);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QString::fromUtf8("menuDebug"));
        menuMap = new QMenu(menuBar);
        menuMap->setObjectName(QString::fromUtf8("menuMap"));
        menuFind = new QMenu(menuBar);
        menuFind->setObjectName(QString::fromUtf8("menuFind"));
        menuTheme = new QMenu(menuBar);
        menuTheme->setObjectName(QString::fromUtf8("menuTheme"));
        menuPilots = new QMenu(menuBar);
        menuPilots->setObjectName(QString::fromUtf8("menuPilots"));
        menu_Window = new QMenu(menuBar);
        menu_Window->setObjectName(QString::fromUtf8("menu_Window"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setAutoFillBackground(true);
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy1);
        dockWidget->setAutoFillBackground(true);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidgetContents->setAutoFillBackground(true);
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listView = new ChatView(dockWidgetContents);
        listView->setObjectName(QString::fromUtf8("listView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy2);
        listView->setBaseSize(QSize(0, 64));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        listView->setFont(font2);
        listView->setAutoFillBackground(true);
        listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView->setAlternatingRowColors(true);
        listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        listView->setProperty("isWrapping", QVariant(false));
        listView->setResizeMode(QListView::Adjust);
        listView->setWordWrap(true);
        listView->setSelectionRectVisible(true);

        gridLayout->addWidget(listView, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        menuBar->addAction(menuPilots->menuAction());
        menuBar->addAction(menuFind->menuAction());
        menuBar->addAction(menuMap->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuTheme->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Window->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuHelp->addAction(actionAbout);
        menuOptions->addAction(actionAuto_follow);
        menuOptions->addAction(actionOptions);
        menuDebug->addAction(actionTest_Message);
        menuFind->addAction(actionFindMessages);
        menuFind->addAction(actionFindSystem);
        menuTheme->addSeparator();
        menuTheme->addAction(actionCustomize);
        menuTheme->addAction(actionSave_As_Theme);
        menu_Window->addAction(action_Always_on_Top);
        menu_Window->addAction(action_Frameless_Window);
        menu_Window->addAction(action_Menu_Toggle);
        menu_Window->addAction(action_Overlay_Mode);
        menu_Window->addAction(actionToggle_Message_List);
        menu_View->addAction(actionShow_Bridges);
        menu_View->addSeparator();
        menu_View->addAction(actionReset_Rotation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "IMP", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "About IMP...", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOptions->setText(QCoreApplication::translate("MainWindow", "&Options", nullptr));
#if QT_CONFIG(tooltip)
        actionOptions->setToolTip(QCoreApplication::translate("MainWindow", "Change IMP options and configuration.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAuto_follow->setText(QCoreApplication::translate("MainWindow", "Auto-follow", nullptr));
#if QT_CONFIG(tooltip)
        actionAuto_follow->setToolTip(QCoreApplication::translate("MainWindow", "Recenter map when changing systems.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionF_YH5B->setText(QCoreApplication::translate("MainWindow", "F-YH5B", nullptr));
        actionN_RMSH->setText(QCoreApplication::translate("MainWindow", "N-RMSH", nullptr));
        actionFindSystem->setText(QCoreApplication::translate("MainWindow", "&System (Ctrl+F)", nullptr));
#if QT_CONFIG(tooltip)
        actionFindSystem->setToolTip(QCoreApplication::translate("MainWindow", "Locate a system by name or partial name.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionShow_Bridges->setText(QCoreApplication::translate("MainWindow", "Show &Bridges", nullptr));
        actionSave_As_Theme->setText(QCoreApplication::translate("MainWindow", "Save &As Theme", nullptr));
#if QT_CONFIG(tooltip)
        actionSave_As_Theme->setToolTip(QCoreApplication::translate("MainWindow", "Save current theme customizations.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFindMessages->setText(QCoreApplication::translate("MainWindow", "Messages", nullptr));
        actionCustomize->setText(QCoreApplication::translate("MainWindow", "&Customize", nullptr));
        actionReset_Rotation->setText(QCoreApplication::translate("MainWindow", "&Reset Rotation", nullptr));
        action_Always_on_Top->setText(QCoreApplication::translate("MainWindow", "Always on &Top", nullptr));
        action_Frameless_Window->setText(QCoreApplication::translate("MainWindow", "Frameless &Window (w)", nullptr));
        action_Overlay_Mode->setText(QCoreApplication::translate("MainWindow", "&Overlay Mode (o)", nullptr));
        action_Menu_Toggle->setText(QCoreApplication::translate("MainWindow", "&Menu Toggle (m)", nullptr));
        actionToggle_Message_List->setText(QCoreApplication::translate("MainWindow", "Toggle Message List (L)", nullptr));
        actionTest_Message->setText(QCoreApplication::translate("MainWindow", "Test Message", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "&Help", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "&Settings", nullptr));
        menuDebug->setTitle(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        menuMap->setTitle(QCoreApplication::translate("MainWindow", "&Map", nullptr));
        menuFind->setTitle(QCoreApplication::translate("MainWindow", "&Find", nullptr));
        menuTheme->setTitle(QCoreApplication::translate("MainWindow", "&Theme", nullptr));
        menuPilots->setTitle(QCoreApplication::translate("MainWindow", "&Pilots", nullptr));
        menu_Window->setTitle(QCoreApplication::translate("MainWindow", "&Window", nullptr));
        menu_View->setTitle(QCoreApplication::translate("MainWindow", "&View", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("MainWindow", "All Messages:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
