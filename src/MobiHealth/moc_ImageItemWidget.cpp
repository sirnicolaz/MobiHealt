/****************************************************************************
** Meta object code from reading C++ file 'ImageItemWidget.h'
**
** Created: Sun Apr 11 11:47:55 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ImageItemWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageItemWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageItemWidget[] = {

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
      17,   16,   16,   16, 0x08,
      32,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImageItemWidget[] = {
    "ImageItemWidget\0\0viewNoteSlot()\0"
    "viewImageSlot()\0"
};

const QMetaObject ImageItemWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageItemWidget,
      qt_meta_data_ImageItemWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageItemWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageItemWidget))
        return static_cast<void*>(const_cast< ImageItemWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: viewNoteSlot(); break;
        case 1: viewImageSlot(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
