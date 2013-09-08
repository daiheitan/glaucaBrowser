/****************************************************************************
** Meta object code from reading C++ file 'GlaucaUrlAction.h'
**
** Created: Fri Jul 22 15:53:54 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GlaucaUrlAction.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlaucaUrlAction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MenuAction[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      29,   11,   11,   11, 0x05,
      51,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   11,   11,   11, 0x0a,
      76,   11,   11,   11, 0x0a,
      91,   87,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MenuAction[] = {
    "MenuAction\0\0clicked(QString)\0"
    "openInNewTabRequest()\0deleteRequest()\0"
    "handle()\0openMenu()\0act\0"
    "handleMenuRequest(QAction*)\0"
};

const QMetaObject MenuAction::staticMetaObject = {
    { &QAction::staticMetaObject, qt_meta_stringdata_MenuAction,
      qt_meta_data_MenuAction, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MenuAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MenuAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MenuAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuAction))
        return static_cast<void*>(const_cast< MenuAction*>(this));
    return QAction::qt_metacast(_clname);
}

int MenuAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: openInNewTabRequest(); break;
        case 2: deleteRequest(); break;
        case 3: handle(); break;
        case 4: openMenu(); break;
        case 5: handleMenuRequest((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MenuAction::clicked(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MenuAction::openInNewTabRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MenuAction::deleteRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
static const uint qt_meta_data_MenuRestoreAction[] = {

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
      19,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MenuRestoreAction[] = {
    "MenuRestoreAction\0\0handle()\0"
};

const QMetaObject MenuRestoreAction::staticMetaObject = {
    { &QAction::staticMetaObject, qt_meta_stringdata_MenuRestoreAction,
      qt_meta_data_MenuRestoreAction, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MenuRestoreAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MenuRestoreAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MenuRestoreAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuRestoreAction))
        return static_cast<void*>(const_cast< MenuRestoreAction*>(this));
    return QAction::qt_metacast(_clname);
}

int MenuRestoreAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handle(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
