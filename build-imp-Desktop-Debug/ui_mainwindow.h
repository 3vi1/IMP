/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(885, 512);
        QFont font;
        font.setFamily(QStringLiteral("FreeSerif"));
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/graphics/impicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setDocumentMode(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionAuto_follow = new QAction(MainWindow);
        actionAuto_follow->setObjectName(QStringLiteral("actionAuto_follow"));
        actionAuto_follow->setCheckable(true);
        actionAuto_follow->setChecked(true);
        actionF_YH5B = new QAction(MainWindow);
        actionF_YH5B->setObjectName(QStringLiteral("actionF_YH5B"));
        actionN_RMSH = new QAction(MainWindow);
        actionN_RMSH->setObjectName(QStringLiteral("actionN_RMSH"));
        actionFindSystem = new QAction(MainWindow);
        actionFindSystem->setObjectName(QStringLiteral("actionFindSystem"));
        actionShow_Bridges = new QAction(MainWindow);
        actionShow_Bridges->setObjectName(QStringLiteral("actionShow_Bridges"));
        actionShow_Bridges->setCheckable(true);
        actionSave_As_Theme = new QAction(MainWindow);
        actionSave_As_Theme->setObjectName(QStringLiteral("actionSave_As_Theme"));
        actionFindMessages = new QAction(MainWindow);
        actionFindMessages->setObjectName(QStringLiteral("actionFindMessages"));
        actionCustomize = new QAction(MainWindow);
        actionCustomize->setObjectName(QStringLiteral("actionCustomize"));
        actionReset_Rotation = new QAction(MainWindow);
        actionReset_Rotation->setObjectName(QStringLiteral("actionReset_Rotation"));
        action_Always_on_Top = new QAction(MainWindow);
        action_Always_on_Top->setObjectName(QStringLiteral("action_Always_on_Top"));
        action_Always_on_Top->setCheckable(true);
        action_Frameless_Window = new QAction(MainWindow);
        action_Frameless_Window->setObjectName(QStringLiteral("action_Frameless_Window"));
        action_Frameless_Window->setCheckable(false);
        action_Overlay_Mode = new QAction(MainWindow);
        action_Overlay_Mode->setObjectName(QStringLiteral("action_Overlay_Mode"));
        action_Overlay_Mode->setCheckable(true);
        action_Overlay_Mode->setChecked(false);
        action_Menu_Toggle = new QAction(MainWindow);
        action_Menu_Toggle->setObjectName(QStringLiteral("action_Menu_Toggle"));
        actionToggle_Message_List = new QAction(MainWindow);
        actionToggle_Message_List->setObjectName(QStringLiteral("actionToggle_Message_List"));
        actionTest_Message = new QAction(MainWindow);
        actionTest_Message->setObjectName(QStringLiteral("actionTest_Message"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        mapView = new SvgMapView(centralWidget);
        mapView->setObjectName(QStringLiteral("mapView"));
        sizePolicy.setHeightForWidth(mapView->sizePolicy().hasHeightForWidth());
        mapView->setSizePolicy(sizePolicy);
        mapView->setMinimumSize(QSize(0, 0));
        mapView->setAutoFillBackground(true);

        gridLayout_2->addWidget(mapView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 885, 24));
        QFont font1;
        font1.setFamily(QStringLiteral("Tahoma"));
        font1.setBold(true);
        font1.setWeight(75);
        menuBar->setFont(font1);
        menuBar->setAutoFillBackground(true);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QStringLiteral("menuDebug"));
        menuMap = new QMenu(menuBar);
        menuMap->setObjectName(QStringLiteral("menuMap"));
        menuFind = new QMenu(menuBar);
        menuFind->setObjectName(QStringLiteral("menuFind"));
        menuTheme = new QMenu(menuBar);
        menuTheme->setObjectName(QStringLiteral("menuTheme"));
        menuPilots = new QMenu(menuBar);
        menuPilots->setObjectName(QStringLiteral("menuPilots"));
        menu_Window = new QMenu(menuBar);
        menu_Window->setObjectName(QStringLiteral("menu_Window"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setAutoFillBackground(true);
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy1);
        dockWidget->setAutoFillBackground(true);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidgetContents->setAutoFillBackground(true);
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listView = new ChatView(dockWidgetContents);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy2);
        listView->setBaseSize(QSize(0, 64));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
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
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "IMP", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About IMP...", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionOptions->setText(QApplication::translate("MainWindow", "&Options", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOptions->setToolTip(QApplication::translate("MainWindow", "Change IMP options and configuration.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionAuto_follow->setText(QApplication::translate("MainWindow", "Auto-follow", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAuto_follow->setToolTip(QApplication::translate("MainWindow", "Recenter map when changing systems.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionF_YH5B->setText(QApplication::translate("MainWindow", "F-YH5B", Q_NULLPTR));
        actionN_RMSH->setText(QApplication::translate("MainWindow", "N-RMSH", Q_NULLPTR));
        actionFindSystem->setText(QApplication::translate("MainWindow", "&System (Ctrl+F)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionFindSystem->setToolTip(QApplication::translate("MainWindow", "Locate a system by name or partial name.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionShow_Bridges->setText(QApplication::translate("MainWindow", "Show &Bridges", Q_NULLPTR));
        actionSave_As_Theme->setText(QApplication::translate("MainWindow", "Save &As Theme", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSave_As_Theme->setToolTip(QApplication::translate("MainWindow", "Save current theme customizations.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionFindMessages->setText(QApplication::translate("MainWindow", "Messages", Q_NULLPTR));
        actionCustomize->setText(QApplication::translate("MainWindow", "&Customize", Q_NULLPTR));
        actionReset_Rotation->setText(QApplication::translate("MainWindow", "&Reset Rotation", Q_NULLPTR));
        action_Always_on_Top->setText(QApplication::translate("MainWindow", "Always on &Top", Q_NULLPTR));
        action_Frameless_Window->setText(QApplication::translate("MainWindow", "Frameless &Window (w)", Q_NULLPTR));
        action_Overlay_Mode->setText(QApplication::translate("MainWindow", "&Overlay Mode (o)", Q_NULLPTR));
        action_Menu_Toggle->setText(QApplication::translate("MainWindow", "&Menu Toggle (m)", Q_NULLPTR));
        actionToggle_Message_List->setText(QApplication::translate("MainWindow", "Toggle Message List (L)", Q_NULLPTR));
        actionTest_Message->setText(QApplication::translate("MainWindow", "Test Message", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("MainWindow", "&Settings", Q_NULLPTR));
        menuDebug->setTitle(QApplication::translate("MainWindow", "Debug", Q_NULLPTR));
        menuMap->setTitle(QApplication::translate("MainWindow", "&Map", Q_NULLPTR));
        menuFind->setTitle(QApplication::translate("MainWindow", "&Find", Q_NULLPTR));
        menuTheme->setTitle(QApplication::translate("MainWindow", "&Theme", Q_NULLPTR));
        menuPilots->setTitle(QApplication::translate("MainWindow", "&Pilots", Q_NULLPTR));
        menu_Window->setTitle(QApplication::translate("MainWindow", "&Window", Q_NULLPTR));
        menu_View->setTitle(QApplication::translate("MainWindow", "&View", Q_NULLPTR));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "All Messages:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
