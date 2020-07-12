/****************************************************************************
** Meta object code from reading C++ file 'asyncinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/asyncinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asyncinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AsyncInfo_t {
    QByteArrayData data[22];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AsyncInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AsyncInfo_t qt_meta_stringdata_AsyncInfo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AsyncInfo"
QT_MOC_LITERAL(1, 10, 11), // "resultReady"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "PilotEntry*"
QT_MOC_LITERAL(4, 35, 10), // "pilotEntry"
QT_MOC_LITERAL(5, 46, 14), // "kosResultReady"
QT_MOC_LITERAL(6, 61, 4), // "name"
QT_MOC_LITERAL(7, 66, 15), // "QList<KosEntry>"
QT_MOC_LITERAL(8, 82, 7), // "entries"
QT_MOC_LITERAL(9, 90, 14), // "kosCheckFailed"
QT_MOC_LITERAL(10, 105, 14), // "rblResultReady"
QT_MOC_LITERAL(11, 120, 3), // "kos"
QT_MOC_LITERAL(12, 124, 7), // "corpNum"
QT_MOC_LITERAL(13, 132, 11), // "idRetrieved"
QT_MOC_LITERAL(14, 144, 14), // "rblIdRetrieved"
QT_MOC_LITERAL(15, 159, 16), // "rblInfoRetrieved"
QT_MOC_LITERAL(16, 176, 15), // "pixmapRetrieved"
QT_MOC_LITERAL(17, 192, 5), // "error"
QT_MOC_LITERAL(18, 198, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(19, 226, 3), // "err"
QT_MOC_LITERAL(20, 230, 16), // "gotKosCheckReply"
QT_MOC_LITERAL(21, 247, 20) // "gotKosCheckCorpReply"

    },
    "AsyncInfo\0resultReady\0\0PilotEntry*\0"
    "pilotEntry\0kosResultReady\0name\0"
    "QList<KosEntry>\0entries\0kosCheckFailed\0"
    "rblResultReady\0kos\0corpNum\0idRetrieved\0"
    "rblIdRetrieved\0rblInfoRetrieved\0"
    "pixmapRetrieved\0error\0QNetworkReply::NetworkError\0"
    "err\0gotKosCheckReply\0gotKosCheckCorpReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AsyncInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    2,   77,    2, 0x06 /* Public */,
       9,    1,   82,    2, 0x06 /* Public */,
      10,    3,   85,    2, 0x06 /* Public */,
      10,    2,   92,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   97,    2, 0x0a /* Public */,
      14,    0,   98,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x0a /* Public */,
      16,    0,  100,    2, 0x0a /* Public */,
      17,    1,  101,    2, 0x0a /* Public */,
      20,    0,  104,    2, 0x0a /* Public */,
      21,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Int,    6,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    6,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AsyncInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AsyncInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resultReady((*reinterpret_cast< PilotEntry*(*)>(_a[1]))); break;
        case 1: _t->kosResultReady((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QList<KosEntry>(*)>(_a[2]))); break;
        case 2: _t->kosCheckFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->rblResultReady((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->rblResultReady((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->idRetrieved(); break;
        case 6: _t->rblIdRetrieved(); break;
        case 7: _t->rblInfoRetrieved(); break;
        case 8: _t->pixmapRetrieved(); break;
        case 9: _t->error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 10: _t->gotKosCheckReply(); break;
        case 11: _t->gotKosCheckCorpReply(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AsyncInfo::*)(PilotEntry * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AsyncInfo::resultReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AsyncInfo::*)(const QString & , const QList<KosEntry> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AsyncInfo::kosResultReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AsyncInfo::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AsyncInfo::kosCheckFailed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AsyncInfo::*)(const QString & , bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AsyncInfo::rblResultReady)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AsyncInfo::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AsyncInfo.data,
    qt_meta_data_AsyncInfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AsyncInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AsyncInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AsyncInfo.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AsyncInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void AsyncInfo::resultReady(PilotEntry * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AsyncInfo::kosResultReady(const QString & _t1, const QList<KosEntry> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AsyncInfo::kosCheckFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AsyncInfo::rblResultReady(const QString & _t1, bool _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
