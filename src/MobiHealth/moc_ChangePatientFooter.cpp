/****************************************************************************
** Meta object code from reading C++ file 'ChangePatientFooter.h'
**
** Created: Sun Apr 11 11:48:01 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ChangePatientFooter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChangePatientFooter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChangePatientFooter[] = {

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
      21,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChangePatientFooter[] = {
    "ChangePatientFooter\0\0changePatientButtonSlot()\0"
};

const QMetaObject ChangePatientFooter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChangePatientFooter,
      qt_meta_data_ChangePatientFooter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChangePatientFooter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChangePatientFooter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChangePatientFooter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChangePatientFooter))
        return static_cast<void*>(const_cast< ChangePatientFooter*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChangePatientFooter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changePatientButtonSlot(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
