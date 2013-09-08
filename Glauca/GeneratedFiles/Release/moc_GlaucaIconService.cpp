/****************************************************************************
** Meta object code from reading C++ file 'GlaucaIconService.h'
**
** Created: Fri Jul 22 15:53:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GlaucaIconService.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlaucaIconService.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GlaucaIconService[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   33,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GlaucaIconService[] = {
    "GlaucaIconService\0\0fileSucceed()\0"
    "id,error\0loadFinished(int,bool)\0"
};

const QMetaObject GlaucaIconService::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GlaucaIconService,
      qt_meta_data_GlaucaIconService, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlaucaIconService::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlaucaIconService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlaucaIconService::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlaucaIconService))
        return static_cast<void*>(const_cast< GlaucaIconService*>(this));
    return QObject::qt_metacast(_clname);
}

int GlaucaIconService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fileSucceed(); break;
        case 1: loadFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GlaucaIconService::fileSucceed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
