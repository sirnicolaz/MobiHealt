/****************************************************************************
** Meta object code from reading C++ file 'CameraWidget.h'
**
** Created: Sun Apr 11 11:47:48 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CameraWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CameraWidget[] = {

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
      14,   13,   13,   13, 0x08,
      27,   13,   13,   13, 0x08,
      41,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CameraWidget[] = {
    "CameraWidget\0\0zoomInSlot()\0zoomOutSlot()\0"
    "captureSlot()\0"
};

const QMetaObject CameraWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CameraWidget,
      qt_meta_data_CameraWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CameraWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CameraWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CameraWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraWidget))
        return static_cast<void*>(const_cast< CameraWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CameraWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: zoomInSlot(); break;
        case 1: zoomOutSlot(); break;
        case 2: captureSlot(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
