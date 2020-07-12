/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[79];
    char stringdata0[1263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "failedGettingRegionFile"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(4, 64, 3), // "err"
QT_MOC_LITERAL(5, 68, 13), // "gotRegionFile"
QT_MOC_LITERAL(6, 82, 23), // "failedGettingBridgeFile"
QT_MOC_LITERAL(7, 106, 13), // "gotBridgeFile"
QT_MOC_LITERAL(8, 120, 11), // "fileChanged"
QT_MOC_LITERAL(9, 132, 16), // "absoluteFilePath"
QT_MOC_LITERAL(10, 149, 19), // "gotAutoPeriodChange"
QT_MOC_LITERAL(11, 169, 5), // "msecs"
QT_MOC_LITERAL(12, 175, 9), // "gotAvatar"
QT_MOC_LITERAL(13, 185, 11), // "PilotEntry*"
QT_MOC_LITERAL(14, 197, 10), // "pilotEntry"
QT_MOC_LITERAL(15, 208, 11), // "gotKosError"
QT_MOC_LITERAL(16, 220, 9), // "pilotName"
QT_MOC_LITERAL(17, 230, 11), // "gotKosReply"
QT_MOC_LITERAL(18, 242, 15), // "QList<KosEntry>"
QT_MOC_LITERAL(19, 258, 7), // "entries"
QT_MOC_LITERAL(20, 266, 11), // "gotRblReply"
QT_MOC_LITERAL(21, 278, 4), // "name"
QT_MOC_LITERAL(22, 283, 3), // "rbl"
QT_MOC_LITERAL(23, 287, 7), // "corpNum"
QT_MOC_LITERAL(24, 295, 11), // "gotEssReply"
QT_MOC_LITERAL(25, 307, 19), // "gotMapRefreshChange"
QT_MOC_LITERAL(26, 327, 11), // "gotNewPilot"
QT_MOC_LITERAL(27, 339, 22), // "gotPollerRefreshChange"
QT_MOC_LITERAL(28, 362, 19), // "gotStyleSheetChange"
QT_MOC_LITERAL(29, 382, 9), // "styleName"
QT_MOC_LITERAL(30, 392, 14), // "gotSystemClick"
QT_MOC_LITERAL(31, 407, 12), // "findLocation"
QT_MOC_LITERAL(32, 420, 10), // "systemName"
QT_MOC_LITERAL(33, 431, 13), // "linkActivated"
QT_MOC_LITERAL(34, 445, 4), // "link"
QT_MOC_LITERAL(35, 450, 13), // "logDirChanged"
QT_MOC_LITERAL(36, 464, 3), // "dir"
QT_MOC_LITERAL(37, 468, 10), // "gotOpacity"
QT_MOC_LITERAL(38, 479, 5), // "delta"
QT_MOC_LITERAL(39, 485, 8), // "mapMoved"
QT_MOC_LITERAL(40, 494, 12), // "saveSettings"
QT_MOC_LITERAL(41, 507, 10), // "changeFont"
QT_MOC_LITERAL(42, 518, 8), // "fontName"
QT_MOC_LITERAL(43, 527, 8), // "fontSize"
QT_MOC_LITERAL(44, 536, 16), // "clipboardUpdated"
QT_MOC_LITERAL(45, 553, 14), // "displayAppcast"
QT_MOC_LITERAL(46, 568, 1), // "s"
QT_MOC_LITERAL(47, 570, 2), // "ba"
QT_MOC_LITERAL(48, 573, 11), // "mapSelected"
QT_MOC_LITERAL(49, 585, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(50, 610, 26), // "on_actionOptions_triggered"
QT_MOC_LITERAL(51, 637, 30), // "on_actionAuto_follow_triggered"
QT_MOC_LITERAL(52, 668, 29), // "on_actionFindSystem_triggered"
QT_MOC_LITERAL(53, 698, 31), // "on_actionShow_Bridges_triggered"
QT_MOC_LITERAL(54, 730, 7), // "checked"
QT_MOC_LITERAL(55, 738, 32), // "on_actionSave_As_Theme_triggered"
QT_MOC_LITERAL(56, 771, 31), // "on_actionFindMessages_triggered"
QT_MOC_LITERAL(57, 803, 28), // "on_actionCustomize_triggered"
QT_MOC_LITERAL(58, 832, 33), // "on_actionReset_Rotation_trigg..."
QT_MOC_LITERAL(59, 866, 33), // "on_action_Always_on_Top_trigg..."
QT_MOC_LITERAL(60, 900, 32), // "on_action_Overlay_Mode_triggered"
QT_MOC_LITERAL(61, 933, 36), // "on_action_Frameless_Window_tr..."
QT_MOC_LITERAL(62, 970, 31), // "on_action_Menu_Toggle_triggered"
QT_MOC_LITERAL(63, 1002, 38), // "on_actionToggle_Message_List_..."
QT_MOC_LITERAL(64, 1041, 31), // "on_actionTest_Message_triggered"
QT_MOC_LITERAL(65, 1073, 25), // "on_listView_doubleClicked"
QT_MOC_LITERAL(66, 1099, 5), // "index"
QT_MOC_LITERAL(67, 1105, 15), // "onPilotLocation"
QT_MOC_LITERAL(68, 1121, 13), // "pilotSelected"
QT_MOC_LITERAL(69, 1135, 14), // "processMessage"
QT_MOC_LITERAL(70, 1150, 11), // "MessageInfo"
QT_MOC_LITERAL(71, 1162, 7), // "message"
QT_MOC_LITERAL(72, 1170, 15), // "receiveMessages"
QT_MOC_LITERAL(73, 1186, 18), // "QList<MessageInfo>"
QT_MOC_LITERAL(74, 1205, 8), // "messages"
QT_MOC_LITERAL(75, 1214, 13), // "themeSelected"
QT_MOC_LITERAL(76, 1228, 15), // "updateChangelog"
QT_MOC_LITERAL(77, 1244, 3), // "url"
QT_MOC_LITERAL(78, 1248, 14) // "updatePosition"

    },
    "MainWindow\0failedGettingRegionFile\0\0"
    "QNetworkReply::NetworkError\0err\0"
    "gotRegionFile\0failedGettingBridgeFile\0"
    "gotBridgeFile\0fileChanged\0absoluteFilePath\0"
    "gotAutoPeriodChange\0msecs\0gotAvatar\0"
    "PilotEntry*\0pilotEntry\0gotKosError\0"
    "pilotName\0gotKosReply\0QList<KosEntry>\0"
    "entries\0gotRblReply\0name\0rbl\0corpNum\0"
    "gotEssReply\0gotMapRefreshChange\0"
    "gotNewPilot\0gotPollerRefreshChange\0"
    "gotStyleSheetChange\0styleName\0"
    "gotSystemClick\0findLocation\0systemName\0"
    "linkActivated\0link\0logDirChanged\0dir\0"
    "gotOpacity\0delta\0mapMoved\0saveSettings\0"
    "changeFont\0fontName\0fontSize\0"
    "clipboardUpdated\0displayAppcast\0s\0ba\0"
    "mapSelected\0on_actionAbout_triggered\0"
    "on_actionOptions_triggered\0"
    "on_actionAuto_follow_triggered\0"
    "on_actionFindSystem_triggered\0"
    "on_actionShow_Bridges_triggered\0checked\0"
    "on_actionSave_As_Theme_triggered\0"
    "on_actionFindMessages_triggered\0"
    "on_actionCustomize_triggered\0"
    "on_actionReset_Rotation_triggered\0"
    "on_action_Always_on_Top_triggered\0"
    "on_action_Overlay_Mode_triggered\0"
    "on_action_Frameless_Window_triggered\0"
    "on_action_Menu_Toggle_triggered\0"
    "on_actionToggle_Message_List_triggered\0"
    "on_actionTest_Message_triggered\0"
    "on_listView_doubleClicked\0index\0"
    "onPilotLocation\0pilotSelected\0"
    "processMessage\0MessageInfo\0message\0"
    "receiveMessages\0QList<MessageInfo>\0"
    "messages\0themeSelected\0updateChangelog\0"
    "url\0updatePosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  264,    2, 0x0a /* Public */,
       5,    0,  267,    2, 0x0a /* Public */,
       6,    1,  268,    2, 0x0a /* Public */,
       7,    0,  271,    2, 0x0a /* Public */,
       8,    1,  272,    2, 0x0a /* Public */,
      10,    1,  275,    2, 0x0a /* Public */,
      12,    1,  278,    2, 0x0a /* Public */,
      15,    1,  281,    2, 0x0a /* Public */,
      17,    2,  284,    2, 0x0a /* Public */,
      20,    3,  289,    2, 0x0a /* Public */,
      20,    2,  296,    2, 0x2a /* Public | MethodCloned */,
      24,    2,  301,    2, 0x0a /* Public */,
      25,    1,  306,    2, 0x0a /* Public */,
      26,    1,  309,    2, 0x0a /* Public */,
      27,    1,  312,    2, 0x0a /* Public */,
      28,    1,  315,    2, 0x0a /* Public */,
      30,    1,  318,    2, 0x0a /* Public */,
      31,    1,  321,    2, 0x0a /* Public */,
      33,    1,  324,    2, 0x0a /* Public */,
      35,    1,  327,    2, 0x0a /* Public */,
      37,    1,  330,    2, 0x0a /* Public */,
      39,    0,  333,    2, 0x0a /* Public */,
      40,    0,  334,    2, 0x0a /* Public */,
      41,    2,  335,    2, 0x08 /* Private */,
      44,    0,  340,    2, 0x08 /* Private */,
      45,    2,  341,    2, 0x08 /* Private */,
      48,    0,  346,    2, 0x08 /* Private */,
      49,    0,  347,    2, 0x08 /* Private */,
      50,    0,  348,    2, 0x08 /* Private */,
      51,    0,  349,    2, 0x08 /* Private */,
      52,    0,  350,    2, 0x08 /* Private */,
      53,    1,  351,    2, 0x08 /* Private */,
      55,    0,  354,    2, 0x08 /* Private */,
      56,    0,  355,    2, 0x08 /* Private */,
      57,    0,  356,    2, 0x08 /* Private */,
      58,    0,  357,    2, 0x08 /* Private */,
      59,    0,  358,    2, 0x08 /* Private */,
      60,    0,  359,    2, 0x08 /* Private */,
      61,    0,  360,    2, 0x08 /* Private */,
      62,    0,  361,    2, 0x08 /* Private */,
      63,    0,  362,    2, 0x08 /* Private */,
      64,    0,  363,    2, 0x08 /* Private */,
      65,    1,  364,    2, 0x08 /* Private */,
      67,    2,  367,    2, 0x08 /* Private */,
      68,    0,  372,    2, 0x08 /* Private */,
      69,    1,  373,    2, 0x08 /* Private */,
      72,    1,  376,    2, 0x08 /* Private */,
      75,    0,  379,    2, 0x08 /* Private */,
      76,    1,  380,    2, 0x08 /* Private */,
      78,    0,  383,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 18,   16,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Int,   21,   22,   23,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   21,   22,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 18,   21,   19,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void, QMetaType::QString,   36,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   42,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,   46,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   54,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   66,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   16,   32,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 70,   71,
    QMetaType::Void, 0x80000000 | 73,   74,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   77,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->failedGettingRegionFile((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 1: _t->gotRegionFile(); break;
        case 2: _t->failedGettingBridgeFile((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 3: _t->gotBridgeFile(); break;
        case 4: _t->fileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->gotAutoPeriodChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->gotAvatar((*reinterpret_cast< PilotEntry*(*)>(_a[1]))); break;
        case 7: _t->gotKosError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->gotKosReply((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QList<KosEntry>(*)>(_a[2]))); break;
        case 9: _t->gotRblReply((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->gotRblReply((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->gotEssReply((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QList<KosEntry>(*)>(_a[2]))); break;
        case 12: _t->gotMapRefreshChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->gotNewPilot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->gotPollerRefreshChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->gotStyleSheetChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->gotSystemClick((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->findLocation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->linkActivated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->logDirChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->gotOpacity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->mapMoved(); break;
        case 22: _t->saveSettings(); break;
        case 23: _t->changeFont((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->clipboardUpdated(); break;
        case 25: _t->displayAppcast((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 26: _t->mapSelected(); break;
        case 27: _t->on_actionAbout_triggered(); break;
        case 28: _t->on_actionOptions_triggered(); break;
        case 29: _t->on_actionAuto_follow_triggered(); break;
        case 30: _t->on_actionFindSystem_triggered(); break;
        case 31: _t->on_actionShow_Bridges_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_actionSave_As_Theme_triggered(); break;
        case 33: _t->on_actionFindMessages_triggered(); break;
        case 34: _t->on_actionCustomize_triggered(); break;
        case 35: _t->on_actionReset_Rotation_triggered(); break;
        case 36: _t->on_action_Always_on_Top_triggered(); break;
        case 37: _t->on_action_Overlay_Mode_triggered(); break;
        case 38: _t->on_action_Frameless_Window_triggered(); break;
        case 39: _t->on_action_Menu_Toggle_triggered(); break;
        case 40: _t->on_actionToggle_Message_List_triggered(); break;
        case 41: _t->on_actionTest_Message_triggered(); break;
        case 42: _t->on_listView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 43: _t->onPilotLocation((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 44: _t->pilotSelected(); break;
        case 45: _t->processMessage((*reinterpret_cast< MessageInfo(*)>(_a[1]))); break;
        case 46: _t->receiveMessages((*reinterpret_cast< QList<MessageInfo>(*)>(_a[1]))); break;
        case 47: _t->themeSelected(); break;
        case 48: _t->updateChangelog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 49: _t->updatePosition(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
