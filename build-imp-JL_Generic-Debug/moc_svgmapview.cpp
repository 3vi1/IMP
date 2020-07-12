/****************************************************************************
** Meta object code from reading C++ file 'svgmapview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/svgmapview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'svgmapview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SvgMapView_t {
    QByteArrayData data[37];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SvgMapView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SvgMapView_t qt_meta_stringdata_SvgMapView = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SvgMapView"
QT_MOC_LITERAL(1, 11, 13), // "systemClicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "name"
QT_MOC_LITERAL(4, 31, 11), // "sendOpacity"
QT_MOC_LITERAL(5, 43, 5), // "delta"
QT_MOC_LITERAL(6, 49, 8), // "mapMoved"
QT_MOC_LITERAL(7, 58, 7), // "showMap"
QT_MOC_LITERAL(8, 66, 6), // "enable"
QT_MOC_LITERAL(9, 73, 11), // "enablePilot"
QT_MOC_LITERAL(10, 85, 5), // "pilot"
QT_MOC_LITERAL(11, 91, 12), // "disablePilot"
QT_MOC_LITERAL(12, 104, 7), // "gotLine"
QT_MOC_LITERAL(13, 112, 2), // "x1"
QT_MOC_LITERAL(14, 115, 2), // "x2"
QT_MOC_LITERAL(15, 118, 2), // "y1"
QT_MOC_LITERAL(16, 121, 2), // "y2"
QT_MOC_LITERAL(17, 124, 15), // "connectionClass"
QT_MOC_LITERAL(18, 140, 9), // "gotSystem"
QT_MOC_LITERAL(19, 150, 8), // "position"
QT_MOC_LITERAL(20, 159, 11), // "systemClass"
QT_MOC_LITERAL(21, 171, 11), // "description"
QT_MOC_LITERAL(22, 183, 17), // "gotSystemPosition"
QT_MOC_LITERAL(23, 201, 13), // "gotSystemTime"
QT_MOC_LITERAL(24, 215, 4), // "text"
QT_MOC_LITERAL(25, 220, 9), // "timeColor"
QT_MOC_LITERAL(26, 230, 14), // "gotSystemColor"
QT_MOC_LITERAL(27, 245, 5), // "color"
QT_MOC_LITERAL(28, 251, 16), // "gotPilotLocation"
QT_MOC_LITERAL(29, 268, 9), // "pilotName"
QT_MOC_LITERAL(30, 278, 10), // "systemName"
QT_MOC_LITERAL(31, 289, 7), // "enabled"
QT_MOC_LITERAL(32, 297, 19), // "gotSystemShapesFile"
QT_MOC_LITERAL(33, 317, 10), // "shapesFile"
QT_MOC_LITERAL(34, 328, 18), // "receiveThemeUpdate"
QT_MOC_LITERAL(35, 347, 13), // "ThemeStorage&"
QT_MOC_LITERAL(36, 361, 1) // "a"

    },
    "SvgMapView\0systemClicked\0\0name\0"
    "sendOpacity\0delta\0mapMoved\0showMap\0"
    "enable\0enablePilot\0pilot\0disablePilot\0"
    "gotLine\0x1\0x2\0y1\0y2\0connectionClass\0"
    "gotSystem\0position\0systemClass\0"
    "description\0gotSystemPosition\0"
    "gotSystemTime\0text\0timeColor\0"
    "gotSystemColor\0color\0gotPilotLocation\0"
    "pilotName\0systemName\0enabled\0"
    "gotSystemShapesFile\0shapesFile\0"
    "receiveThemeUpdate\0ThemeStorage&\0a"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SvgMapView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       6,    0,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   96,    2, 0x0a /* Public */,
       9,    1,   99,    2, 0x0a /* Public */,
      11,    1,  102,    2, 0x0a /* Public */,
      12,    5,  105,    2, 0x0a /* Public */,
      18,    4,  116,    2, 0x0a /* Public */,
      22,    2,  125,    2, 0x0a /* Public */,
      23,    3,  130,    2, 0x0a /* Public */,
      26,    2,  137,    2, 0x0a /* Public */,
      28,    3,  142,    2, 0x0a /* Public */,
      28,    2,  149,    2, 0x2a /* Public | MethodCloned */,
      32,    1,  154,    2, 0x0a /* Public */,
      34,    1,  157,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString,   13,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QPointF, QMetaType::QString, QMetaType::QString,    3,   19,   20,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QPointF,    3,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,    3,   24,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,   27,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   29,   30,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   29,   30,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void, 0x80000000 | 35,   36,

       0        // eod
};

void SvgMapView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SvgMapView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->systemClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sendOpacity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mapMoved(); break;
        case 3: _t->showMap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->enablePilot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->disablePilot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->gotLine((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 7: _t->gotSystem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 8: _t->gotSystemPosition((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 9: _t->gotSystemTime((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 10: _t->gotSystemColor((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 11: _t->gotPilotLocation((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 12: _t->gotPilotLocation((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 13: _t->gotSystemShapesFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->receiveThemeUpdate((*reinterpret_cast< ThemeStorage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SvgMapView::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SvgMapView::systemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SvgMapView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SvgMapView::sendOpacity)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SvgMapView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SvgMapView::mapMoved)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SvgMapView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_SvgMapView.data,
    qt_meta_data_SvgMapView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SvgMapView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SvgMapView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SvgMapView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int SvgMapView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void SvgMapView::systemClicked(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SvgMapView::sendOpacity(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SvgMapView::mapMoved()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
