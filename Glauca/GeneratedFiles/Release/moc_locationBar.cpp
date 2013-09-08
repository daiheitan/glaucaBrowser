/****************************************************************************
** Meta object code from reading C++ file 'locationBar.h'
**
** Created: Fri Jul 22 15:53:53 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../locationBar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'locationBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_locationBar[] = {

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
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_locationBar[] = {
    "locationBar\0\0returnPressed()\0"
    "changeLocation()\0"
};

const QMetaObject locationBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_locationBar,
      qt_meta_data_locationBar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &locationBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *locationBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *locationBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_locationBar))
        return static_cast<void*>(const_cast< locationBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int locationBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: returnPressed(); break;
        case 1: changeLocation(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void locationBar::returnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
