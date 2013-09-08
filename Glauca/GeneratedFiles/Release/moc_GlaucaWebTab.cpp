/****************************************************************************
** Meta object code from reading C++ file 'GlaucaWebTab.h'
**
** Created: Fri Jul 22 17:47:58 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GlaucaWebTab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlaucaWebTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GlaucaWebTab[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      32,   13,   13,   13, 0x05,
      45,   13,   13,   13, 0x05,
      64,   59,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      83,   13,   13,   13, 0x0a,
      94,   13,   13,   13, 0x0a,
     115,  107,   13,   13, 0x0a,
     154,  148,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GlaucaWebTab[] = {
    "GlaucaWebTab\0\0urlChanged(QUrl&)\0"
    "buffLoaded()\0loadStarted()\0flag\0"
    "loadFinished(bool)\0loadIcon()\0"
    "createIcon()\0request\0"
    "downloadRequest(QNetworkRequest)\0reply\0"
    "unsupportedContent(QNetworkReply*)\0"
};

const QMetaObject GlaucaWebTab::staticMetaObject = {
    { &GlaucaTabPage::staticMetaObject, qt_meta_stringdata_GlaucaWebTab,
      qt_meta_data_GlaucaWebTab, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlaucaWebTab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlaucaWebTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlaucaWebTab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlaucaWebTab))
        return static_cast<void*>(const_cast< GlaucaWebTab*>(this));
    return GlaucaTabPage::qt_metacast(_clname);
}

int GlaucaWebTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GlaucaTabPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: urlChanged((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 1: buffLoaded(); break;
        case 2: loadStarted(); break;
        case 3: loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: loadIcon(); break;
        case 5: createIcon(); break;
        case 6: downloadRequest((*reinterpret_cast< const QNetworkRequest(*)>(_a[1]))); break;
        case 7: unsupportedContent((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GlaucaWebTab::urlChanged(QUrl & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GlaucaWebTab::buffLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GlaucaWebTab::loadStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GlaucaWebTab::loadFinished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
