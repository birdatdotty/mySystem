/****************************************************************************
** Meta object code from reading C++ file 'TestController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TestController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestController_t {
    QByteArrayData data[8];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestController_t qt_meta_stringdata_TestController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TestController"
QT_MOC_LITERAL(1, 15, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 31, 10), // "test.iface"
QT_MOC_LITERAL(3, 42, 9), // "clearCash"
QT_MOC_LITERAL(4, 52, 0), // ""
QT_MOC_LITERAL(5, 53, 1), // "i"
QT_MOC_LITERAL(6, 55, 7), // "message"
QT_MOC_LITERAL(7, 63, 3) // "msg"

    },
    "TestController\0D-Bus Interface\0"
    "test.iface\0clearCash\0\0i\0message\0msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestController[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       3,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    1,   31,    4, 0x08 /* Private */,
       3,    0,   34,    4, 0x28 /* Private | MethodCloned */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   35,    4, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Int, QMetaType::Int,    5,
    QMetaType::Int,

 // methods: parameters
    QMetaType::Int, QMetaType::QString,    7,

       0        // eod
};

void TestController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->clearCash((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->clearCash();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->message((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TestController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TestController.data,
    qt_meta_data_TestController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestController.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QDBusContext"))
        return static_cast< QDBusContext*>(this);
    return QObject::qt_metacast(_clname);
}

int TestController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
