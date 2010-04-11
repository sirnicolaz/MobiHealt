/****************************************************************************
** Meta object code from reading C++ file 'SelectSearchMenu.h'
**
** Created: Sun Apr 11 17:24:46 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SelectSearchMenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SelectSearchMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SelectSearchMenu[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      37,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SelectSearchMenu[] = {
    "SelectSearchMenu\0\0qrCodeButtonSlot()\0"
    "searchButtonSlot()\0"
};

const QMetaObject SelectSearchMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SelectSearchMenu,
      qt_meta_data_SelectSearchMenu, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SelectSearchMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SelectSearchMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SelectSearchMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectSearchMenu))
        return static_cast<void*>(const_cast< SelectSearchMenu*>(this));
    if (!strcmp(_clname, "MCoeMessageObserver"))
        return static_cast< MCoeMessageObserver*>(const_cast< SelectSearchMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int SelectSearchMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: qrCodeButtonSlot(); break;
        case 1: searchButtonSlot(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
