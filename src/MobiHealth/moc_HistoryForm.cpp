/****************************************************************************
** Meta object code from reading C++ file 'HistoryForm.h'
**
** Created: Sun Apr 11 11:47:56 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "HistoryForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HistoryForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HistoryForm[] = {

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
      13,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HistoryForm[] = {
    "HistoryForm\0\0backButtonSlot()\0"
};

const QMetaObject HistoryForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HistoryForm,
      qt_meta_data_HistoryForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HistoryForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HistoryForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HistoryForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HistoryForm))
        return static_cast<void*>(const_cast< HistoryForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int HistoryForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: backButtonSlot(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
