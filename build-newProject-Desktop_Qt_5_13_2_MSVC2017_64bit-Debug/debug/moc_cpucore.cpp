/****************************************************************************
** Meta object code from reading C++ file 'cpucore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../newProject/cpucore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cpucore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CpuCore_t {
    QByteArrayData data[11];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CpuCore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CpuCore_t qt_meta_stringdata_CpuCore = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CpuCore"
QT_MOC_LITERAL(1, 8, 14), // "slotIsOccupied"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "slot"
QT_MOC_LITERAL(4, 29, 10), // "slotIsFree"
QT_MOC_LITERAL(5, 40, 12), // "fadeInfoText"
QT_MOC_LITERAL(6, 53, 22), // "process_was_terminated"
QT_MOC_LITERAL(7, 76, 10), // "process_id"
QT_MOC_LITERAL(8, 87, 15), // "process_starved"
QT_MOC_LITERAL(9, 103, 8), // "decrease"
QT_MOC_LITERAL(10, 112, 8) // "increase"

    },
    "CpuCore\0slotIsOccupied\0\0slot\0slotIsFree\0"
    "fadeInfoText\0process_was_terminated\0"
    "process_id\0process_starved\0decrease\0"
    "increase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CpuCore[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    1,   52,    2, 0x0a /* Public */,
       5,    0,   55,    2, 0x0a /* Public */,
       6,    1,   56,    2, 0x0a /* Public */,
       8,    1,   59,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CpuCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CpuCore *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotIsOccupied((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotIsFree((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->fadeInfoText(); break;
        case 3: _t->process_was_terminated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->process_starved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->decrease(); break;
        case 6: _t->increase(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CpuCore::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CpuCore.data,
    qt_meta_data_CpuCore,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CpuCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CpuCore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CpuCore.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return QObject::qt_metacast(_clname);
}

int CpuCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
