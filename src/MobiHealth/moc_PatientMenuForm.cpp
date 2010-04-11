/****************************************************************************
** Meta object code from reading C++ file 'PatientMenuForm.h'
**
** Created: Sun Apr 11 11:48:03 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "PatientMenuForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PatientMenuForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PatientMenuForm[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      34,   16,   16,   16, 0x08,
      57,   16,   16,   16, 0x08,
      78,   16,   16,   16, 0x08,
      97,   16,   16,   16, 0x08,
     123,   16,   16,   16, 0x08,
     143,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PatientMenuForm[] = {
    "PatientMenuForm\0\0backButtonSlot()\0"
    "anagraficaButtonSlot()\0contactsButtonSlot()\0"
    "imagesButtonSlot()\0medicalReportButtonSlot()\0"
    "historyButtonSlot()\0pathologiesButtonSlot()\0"
};

const QMetaObject PatientMenuForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PatientMenuForm,
      qt_meta_data_PatientMenuForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PatientMenuForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PatientMenuForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PatientMenuForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PatientMenuForm))
        return static_cast<void*>(const_cast< PatientMenuForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int PatientMenuForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: backButtonSlot(); break;
        case 1: anagraficaButtonSlot(); break;
        case 2: contactsButtonSlot(); break;
        case 3: imagesButtonSlot(); break;
        case 4: medicalReportButtonSlot(); break;
        case 5: historyButtonSlot(); break;
        case 6: pathologiesButtonSlot(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
