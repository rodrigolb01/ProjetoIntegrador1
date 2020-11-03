/****************************************************************************
** Meta object code from reading C++ file 'process.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../newProject/process.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'process.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Process_t {
    QByteArrayData data[17];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Process_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Process_t qt_meta_stringdata_Process = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Process"
QT_MOC_LITERAL(1, 8, 10), // "terminated"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "starved"
QT_MOC_LITERAL(4, 28, 22), // "process_was_terminated"
QT_MOC_LITERAL(5, 51, 2), // "id"
QT_MOC_LITERAL(6, 54, 15), // "process_starved"
QT_MOC_LITERAL(7, 70, 26), // "notify_process_interrupted"
QT_MOC_LITERAL(8, 97, 10), // "process_id"
QT_MOC_LITERAL(9, 108, 24), // "notify_process_execution"
QT_MOC_LITERAL(10, 133, 23), // "notify_process_needs_io"
QT_MOC_LITERAL(11, 157, 2), // "io"
QT_MOC_LITERAL(12, 160, 15), // "notify_io_ready"
QT_MOC_LITERAL(13, 176, 14), // "slotIsOccupied"
QT_MOC_LITERAL(14, 191, 4), // "slot"
QT_MOC_LITERAL(15, 196, 10), // "slotIsFree"
QT_MOC_LITERAL(16, 207, 8) // "gameOver"

    },
    "Process\0terminated\0\0starved\0"
    "process_was_terminated\0id\0process_starved\0"
    "notify_process_interrupted\0process_id\0"
    "notify_process_execution\0"
    "notify_process_needs_io\0io\0notify_io_ready\0"
    "slotIsOccupied\0slot\0slotIsFree\0gameOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Process[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    1,   71,    2, 0x06 /* Public */,
       6,    1,   74,    2, 0x06 /* Public */,
       7,    1,   77,    2, 0x06 /* Public */,
       9,    1,   80,    2, 0x06 /* Public */,
      10,    2,   83,    2, 0x06 /* Public */,
      12,    1,   88,    2, 0x06 /* Public */,
      13,    1,   91,    2, 0x06 /* Public */,
      15,    1,   94,    2, 0x06 /* Public */,
      16,    0,   97,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,   11,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,

       0        // eod
};

void Process::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Process *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->terminated(); break;
        case 1: _t->starved(); break;
        case 2: _t->process_was_terminated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->process_starved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->notify_process_interrupted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->notify_process_execution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->notify_process_needs_io((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->notify_io_ready((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotIsOccupied((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slotIsFree((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->gameOver(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Process::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::terminated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Process::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::starved)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Process::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::process_was_terminated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Process::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::process_starved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Process::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::notify_process_interrupted)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Process::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::notify_process_execution)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Process::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::notify_process_needs_io)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Process::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::notify_io_ready)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Process::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::slotIsOccupied)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Process::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::slotIsFree)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Process::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process::gameOver)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Process::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Process.data,
    qt_meta_data_Process,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Process::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Process::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Process.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Process::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Process::terminated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Process::starved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Process::process_was_terminated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Process::process_starved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Process::notify_process_interrupted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Process::notify_process_execution(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Process::notify_process_needs_io(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Process::notify_io_ready(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Process::slotIsOccupied(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Process::slotIsFree(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Process::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
