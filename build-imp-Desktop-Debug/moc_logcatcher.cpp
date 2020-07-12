/****************************************************************************
** Meta object code from reading C++ file 'logcatcher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/logcatcher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logcatcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogCatcher_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogCatcher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogCatcher_t qt_meta_stringdata_LogCatcher = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LogCatcher"
QT_MOC_LITERAL(1, 11, 11), // "fileChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "absoluteFilePath"
QT_MOC_LITERAL(4, 41, 15), // "findCurrentLogs"
QT_MOC_LITERAL(5, 57, 8), // "dirNames"
QT_MOC_LITERAL(6, 66, 14), // "gotFileChanged"
QT_MOC_LITERAL(7, 81, 14) // "fallbackPoller"

    },
    "LogCatcher\0fileChanged\0\0absoluteFilePath\0"
    "findCurrentLogs\0dirNames\0gotFileChanged\0"
    "fallbackPoller"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogCatcher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       7,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void LogCatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogCatcher *_t = static_cast<LogCatcher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->findCurrentLogs((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->gotFileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->fallbackPoller(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LogCatcher::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LogCatcher::fileChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject LogCatcher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LogCatcher.data,
      qt_meta_data_LogCatcher,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LogCatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogCatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogCatcher.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LogCatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LogCatcher::fileChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
