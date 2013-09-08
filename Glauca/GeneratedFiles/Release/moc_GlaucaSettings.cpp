/****************************************************************************
** Meta object code from reading C++ file 'GlaucaSettings.h'
**
** Created: Fri Jul 22 15:53:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GlaucaSettings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlaucaSettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GlaucaSettings[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   15,   15,   15, 0x0a,
      60,   15,   15,   15, 0x0a,
      76,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GlaucaSettings[] = {
    "GlaucaSettings\0\0currentPageReuqest()\0"
    "glaucaSettingsWindow()\0writeSettings()\0"
    "handleHomepageBtnAction()\0"
};

const QMetaObject GlaucaSettings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GlaucaSettings,
      qt_meta_data_GlaucaSettings, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlaucaSettings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlaucaSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlaucaSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlaucaSettings))
        return static_cast<void*>(const_cast< GlaucaSettings*>(this));
    if (!strcmp(_clname, "Ui_settingStack"))
        return static_cast< Ui_settingStack*>(const_cast< GlaucaSettings*>(this));
    return QWidget::qt_metacast(_clname);
}

int GlaucaSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentPageReuqest(); break;
        case 1: glaucaSettingsWindow(); break;
        case 2: writeSettings(); break;
        case 3: handleHomepageBtnAction(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GlaucaSettings::currentPageReuqest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
