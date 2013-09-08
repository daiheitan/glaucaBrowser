/****************************************************************************
** Meta object code from reading C++ file 'GlaucaTabs.h'
**
** Created: Fri Jul 22 15:53:55 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GlaucaTabs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlaucaTabs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GlaucaTabPrivate[] = {

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
      25,   18,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GlaucaTabPrivate[] = {
    "GlaucaTabPrivate\0\0action\0"
    "handleMenuRequest(QAction*)\0"
};

const QMetaObject GlaucaTabPrivate::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_GlaucaTabPrivate,
      qt_meta_data_GlaucaTabPrivate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlaucaTabPrivate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlaucaTabPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlaucaTabPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlaucaTabPrivate))
        return static_cast<void*>(const_cast< GlaucaTabPrivate*>(this));
    return QTabBar::qt_metacast(_clname);
}

int GlaucaTabPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleMenuRequest((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_GlaucaTabs[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_GlaucaTabs[] = {
    "GlaucaTabs\0"
};

const QMetaObject GlaucaTabs::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GlaucaTabs,
      qt_meta_data_GlaucaTabs, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlaucaTabs::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlaucaTabs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlaucaTabs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlaucaTabs))
        return static_cast<void*>(const_cast< GlaucaTabs*>(this));
    return QWidget::qt_metacast(_clname);
}

int GlaucaTabs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
