/****************************************************************************
** Meta object code from reading C++ file 'ActionsMenu.h'
**
** Created: Mon Mar 1 22:06:46 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ActionsMenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ActionsMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QPushButtonWithID[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   18,   18,   18, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QPushButtonWithID[] = {
    "QPushButtonWithID\0\0clickedWithID(int)\0"
    "clickWithID()\0"
};

const QMetaObject QPushButtonWithID::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_QPushButtonWithID,
      qt_meta_data_QPushButtonWithID, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QPushButtonWithID::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QPushButtonWithID::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QPushButtonWithID::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPushButtonWithID))
        return static_cast<void*>(const_cast< QPushButtonWithID*>(this));
    return QPushButton::qt_metacast(_clname);
}

int QPushButtonWithID::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clickedWithID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: clickWithID(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QPushButtonWithID::clickedWithID(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_ActionsMenu[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ActionsMenu[] = {
    "ActionsMenu\0\0showAction(int)\0"
};

const QMetaObject ActionsMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ActionsMenu,
      qt_meta_data_ActionsMenu, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ActionsMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ActionsMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ActionsMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ActionsMenu))
        return static_cast<void*>(const_cast< ActionsMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int ActionsMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
