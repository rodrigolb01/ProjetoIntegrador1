/****************************************************************************
** Meta object code from reading C++ file 'mainmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../newProject/mainmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainMenu_t {
    QByteArrayData data[12];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainMenu_t qt_meta_stringdata_mainMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mainMenu"
QT_MOC_LITERAL(1, 9, 9), // "closeMenu"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 30), // "on_pushButton_campaign_clicked"
QT_MOC_LITERAL(4, 51, 30), // "on_pushButton_survival_clicked"
QT_MOC_LITERAL(5, 82, 28), // "on_pushButton_logout_clicked"
QT_MOC_LITERAL(6, 111, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 133, 13), // "game_finished"
QT_MOC_LITERAL(8, 147, 13), // "logged_player"
QT_MOC_LITERAL(9, 161, 8), // "username"
QT_MOC_LITERAL(10, 170, 16), // "closeLvSelection"
QT_MOC_LITERAL(11, 187, 16) // "closeStatsWindow"

    },
    "mainMenu\0closeMenu\0\0on_pushButton_campaign_clicked\0"
    "on_pushButton_survival_clicked\0"
    "on_pushButton_logout_clicked\0"
    "on_pushButton_clicked\0game_finished\0"
    "logged_player\0username\0closeLvSelection\0"
    "closeStatsWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    1,   65,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeMenu(); break;
        case 1: _t->on_pushButton_campaign_clicked(); break;
        case 2: _t->on_pushButton_survival_clicked(); break;
        case 3: _t->on_pushButton_logout_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->game_finished(); break;
        case 6: _t->logged_player((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->closeLvSelection(); break;
        case 8: _t->closeStatsWindow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mainMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainMenu::closeMenu)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mainMenu::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_mainMenu.data,
    qt_meta_data_mainMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainMenu.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int mainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void mainMenu::closeMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
