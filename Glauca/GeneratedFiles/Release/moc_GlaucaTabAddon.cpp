/****************************************************************************
** Meta object code from reading C++ file 'GlaucaTabAddon.h'
**
** Created: Fri Jul 22 15:53:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GlaucaTabAddon.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlaucaTabAddon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GlaucaTabAddon[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   16,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GlaucaTabAddon[] = {
    "GlaucaTabAddon\0\0event,menu\0"
    "contextMenuEvent(QContextMenuEvent*,QMenu*)\0"
};

const QMetaObject GlaucaTabAddon::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GlaucaTabAddon,
      qt_meta_data_GlaucaTabAddon, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlaucaTabAddon::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlaucaTabAddon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlaucaTabAddon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlaucaTabAddon))
        return static_cast<void*>(const_cast< GlaucaTabAddon*>(this));
    return QWidget::qt_metacast(_clname);
}

int GlaucaTabAddon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: contextMenuEvent((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1])),(*reinterpret_cast< QMenu*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
