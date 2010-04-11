/****************************************************************************
** Meta object code from reading C++ file 'MainMenuForm.h'
**
** Created: Sun Apr 11 12:17:33 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainMenuForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainMenuForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainMenuForm[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      34,   13,   13,   13, 0x08,
      52,   13,   13,   13, 0x08,
      70,   13,   13,   13, 0x08,
      90,   13,   13,   13, 0x08,
     111,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainMenuForm[] = {
    "MainMenuForm\0\0patientButtonSlot()\0"
    "examsButtonSlot()\0notesButtonSlot()\0"
    "accountButtonSlot()\0patientChangedSlot()\0"
    "logoutButtonSlot()\0"
};

const QMetaObject MainMenuForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainMenuForm,
      qt_meta_data_MainMenuForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainMenuForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainMenuForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainMenuForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenuForm))
        return static_cast<void*>(const_cast< MainMenuForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainMenuForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: patientButtonSlot(); break;
        case 1: examsButtonSlot(); break;
        case 2: notesButtonSlot(); break;
        case 3: accountButtonSlot(); break;
        case 4: patientChangedSlot(); break;
        case 5: logoutButtonSlot(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
