/****************************************************************************
** Meta object code from reading C++ file 'GenericStep.h'
**
** Created: Sun Apr 11 11:47:52 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GenericStep.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GenericStep.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GenericStep[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      23,   12,   12,   12, 0x08,
      32,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GenericStep[] = {
    "GenericStep\0\0yesSlot()\0noSlot()\0"
    "showViewFinderWidgetSlot()\0"
};

const QMetaObject GenericStep::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GenericStep,
      qt_meta_data_GenericStep, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GenericStep::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GenericStep::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GenericStep::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GenericStep))
        return static_cast<void*>(const_cast< GenericStep*>(this));
    return QWidget::qt_metacast(_clname);
}

int GenericStep::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: yesSlot(); break;
        case 1: noSlot(); break;
        case 2: showViewFinderWidgetSlot(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
