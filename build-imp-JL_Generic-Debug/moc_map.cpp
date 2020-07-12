/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/map.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Map_t {
    QByteArrayData data[24];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Map_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Map_t qt_meta_stringdata_Map = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Map"
QT_MOC_LITERAL(1, 4, 9), // "lineAdded"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 2), // "x1"
QT_MOC_LITERAL(4, 18, 2), // "x2"
QT_MOC_LITERAL(5, 21, 2), // "y1"
QT_MOC_LITERAL(6, 24, 2), // "y2"
QT_MOC_LITERAL(7, 27, 15), // "connectionClass"
QT_MOC_LITERAL(8, 43, 8), // "newPilot"
QT_MOC_LITERAL(9, 52, 9), // "pilotName"
QT_MOC_LITERAL(10, 62, 19), // "pilotLocationChange"
QT_MOC_LITERAL(11, 82, 5), // "pilot"
QT_MOC_LITERAL(12, 88, 6), // "system"
QT_MOC_LITERAL(13, 95, 11), // "systemAdded"
QT_MOC_LITERAL(14, 107, 4), // "name"
QT_MOC_LITERAL(15, 112, 8), // "position"
QT_MOC_LITERAL(16, 121, 11), // "systemClass"
QT_MOC_LITERAL(17, 133, 11), // "description"
QT_MOC_LITERAL(18, 145, 18), // "systemColorUpdated"
QT_MOC_LITERAL(19, 164, 5), // "color"
QT_MOC_LITERAL(20, 170, 14), // "systemPosition"
QT_MOC_LITERAL(21, 185, 17), // "systemTimeUpdated"
QT_MOC_LITERAL(22, 203, 4), // "text"
QT_MOC_LITERAL(23, 208, 19) // "updateActiveSystems"

    },
    "Map\0lineAdded\0\0x1\0x2\0y1\0y2\0connectionClass\0"
    "newPilot\0pilotName\0pilotLocationChange\0"
    "pilot\0system\0systemAdded\0name\0position\0"
    "systemClass\0description\0systemColorUpdated\0"
    "color\0systemPosition\0systemTimeUpdated\0"
    "text\0updateActiveSystems"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Map[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   54,    2, 0x06 /* Public */,
       8,    1,   65,    2, 0x06 /* Public */,
      10,    2,   68,    2, 0x06 /* Public */,
      13,    4,   73,    2, 0x06 /* Public */,
      18,    2,   82,    2, 0x06 /* Public */,
      20,    2,   87,    2, 0x06 /* Public */,
      21,    3,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QString,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QPointF, QMetaType::QString, QMetaType::QString,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,   14,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QPointF,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,   14,   22,   19,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Map::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Map *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lineAdded((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 1: _t->newPilot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->pilotLocationChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->systemAdded((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 4: _t->systemColorUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 5: _t->systemPosition((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 6: _t->systemTimeUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 7: _t->updateActiveSystems(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Map::*)(qreal , qreal , qreal , qreal , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::lineAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Map::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::newPilot)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Map::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::pilotLocationChange)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Map::*)(const QString & , QPointF , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::systemAdded)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Map::*)(const QString & , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::systemColorUpdated)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Map::*)(const QString & , QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::systemPosition)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Map::*)(const QString & , const QString & , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::systemTimeUpdated)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Map::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Map.data,
    qt_meta_data_Map,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Map::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Map::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Map.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Map::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Map::lineAdded(qreal _t1, qreal _t2, qreal _t3, qreal _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Map::newPilot(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Map::pilotLocationChange(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Map::systemAdded(const QString & _t1, QPointF _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Map::systemColorUpdated(const QString & _t1, QColor _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Map::systemPosition(const QString & _t1, QPointF _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Map::systemTimeUpdated(const QString & _t1, const QString & _t2, QColor _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
