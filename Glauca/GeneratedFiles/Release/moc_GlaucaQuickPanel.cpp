/****************************************************************************
** Meta object code from reading C++ file 'GlaucaQuickPanel.h'
**
** Created: Fri Jul 22 15:53:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GlaucaQuickPanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlaucaQuickPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GlaucaQuickPanel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      25,   17,   17,   17, 0x05,
      35,   17,   17,   17, 0x05,
      42,   17,   17,   17, 0x05,
      56,   52,   17,   17, 0x05,
      68,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,   17,   17,   17, 0x0a,
      89,   17,   17,   17, 0x0a,
     105,   17,   17,   17, 0x0a,
     121,   17,   17,   17, 0x0a,
     146,  138,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GlaucaQuickPanel[] = {
    "GlaucaQuickPanel\0\0back()\0forward()\0"
    "stop()\0refresh()\0url\0go(QString)\0"
    "home()\0upBarAction()\0downBarAction()\0"
    "leftBarAction()\0rightBarAction()\0"
    "old,now\0handleFocus(QWidget*,QWidget*)\0"
};

const QMetaObject GlaucaQuickPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GlaucaQuickPanel,
      qt_meta_data_GlaucaQuickPanel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlaucaQuickPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlaucaQuickPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlaucaQuickPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlaucaQuickPanel))
        return static_cast<void*>(const_cast< GlaucaQuickPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int GlaucaQuickPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: back(); break;
        case 1: forward(); break;
        case 2: stop(); break;
        case 3: refresh(); break;
        case 4: go((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: home(); break;
        case 6: upBarAction(); break;
        case 7: downBarAction(); break;
        case 8: leftBarAction(); break;
        case 9: rightBarAction(); break;
        case 10: handleFocus((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void GlaucaQuickPanel::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GlaucaQuickPanel::forward()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GlaucaQuickPanel::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GlaucaQuickPanel::refresh()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GlaucaQuickPanel::go(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GlaucaQuickPanel::home()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
