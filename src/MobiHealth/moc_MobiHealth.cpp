/****************************************************************************
** Meta object code from reading C++ file 'MobiHealth.h'
**
** Created: Sun Apr 11 16:13:03 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MobiHealth.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MobiHealth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MobiHealth[] = {

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
      12,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MobiHealth[] = {
    "MobiHealth\0\0loginSlot()\0"
};

const QMetaObject MobiHealth::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MobiHealth,
      qt_meta_data_MobiHealth, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MobiHealth::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MobiHealth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MobiHealth::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MobiHealth))
        return static_cast<void*>(const_cast< MobiHealth*>(this));
    return QWidget::qt_metacast(_clname);
}

int MobiHealth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loginSlot(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
