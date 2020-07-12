/****************************************************************************
** Meta object code from reading C++ file 'msgstyle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/msgstyle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'msgstyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MsgStyle_t {
    QByteArrayData data[10];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MsgStyle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MsgStyle_t qt_meta_stringdata_MsgStyle = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MsgStyle"
QT_MOC_LITERAL(1, 9, 10), // "clearColor"
QT_MOC_LITERAL(2, 20, 9), // "gateColor"
QT_MOC_LITERAL(3, 30, 9), // "infoColor"
QT_MOC_LITERAL(4, 40, 13), // "locationColor"
QT_MOC_LITERAL(5, 54, 9), // "shipColor"
QT_MOC_LITERAL(6, 64, 10), // "stampColor"
QT_MOC_LITERAL(7, 75, 11), // "statusColor"
QT_MOC_LITERAL(8, 87, 11), // "systemColor"
QT_MOC_LITERAL(9, 99, 9) // "warnColor"

    },
    "MsgStyle\0clearColor\0gateColor\0infoColor\0"
    "locationColor\0shipColor\0stampColor\0"
    "statusColor\0systemColor\0warnColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MsgStyle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       9,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QColor, 0x00095103,
       2, QMetaType::QColor, 0x00095103,
       3, QMetaType::QColor, 0x00095103,
       4, QMetaType::QColor, 0x00095103,
       5, QMetaType::QColor, 0x00095103,
       6, QMetaType::QColor, 0x00095103,
       7, QMetaType::QColor, 0x00095103,
       8, QMetaType::QColor, 0x00095103,
       9, QMetaType::QColor, 0x00095103,

       0        // eod
};

void MsgStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        MsgStyle *_t = static_cast<MsgStyle *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->getClearColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getGateColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->getInfoColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->getLocationColor(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->getShipColor(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->getStampColor(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->getStatusColor(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->getSystemColor(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->getWarnColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MsgStyle *_t = static_cast<MsgStyle *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setClearColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setGateColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setInfoColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setLocationColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setShipColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setStampColor(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setStatusColor(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setSystemColor(*reinterpret_cast< QColor*>(_v)); break;
        case 8: _t->setWarnColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MsgStyle::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MsgStyle.data,
      qt_meta_data_MsgStyle,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MsgStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MsgStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MsgStyle.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MsgStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
