/****************************************************************************
** Meta object code from reading C++ file 'GlaucaBookmarkService.h'
**
** Created: Fri Jul 22 17:29:17 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GlaucaBookmarkService.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlaucaBookmarkService.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GlaucaBookmarkController[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   26,   25,   25, 0x0a,
      66,   60,   25,   25, 0x0a,
     102,   97,   25,   25, 0x0a,
     131,   25,   25,   25, 0x0a,
     155,   25,   25,   25, 0x0a,
     180,   25,   25,   25, 0x0a,
     210,  205,   25,   25, 0x0a,
     245,   25,   25,   25, 0x0a,
     267,   25,   25,   25, 0x0a,
     286,   25,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GlaucaBookmarkController[] = {
    "GlaucaBookmarkController\0\0tab\0"
    "setCurrentTab(GlaucaTabPage*)\0model\0"
    "setModel(GlaucaBookmarkModel*)\0view\0"
    "setView(GlaucaBookmarkView*)\0"
    "addBookmarkBtnPressed()\0"
    "saveBookmarkBtnPressed()\0"
    "addNewFolderBtnPressed()\0item\0"
    "varifyFolderName(QTreeWidgetItem*)\0"
    "delFolderBtnPressed()\0cancelBtnPressed()\0"
    "refreshBookmarkIcon()\0"
};

const QMetaObject GlaucaBookmarkController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GlaucaBookmarkController,
      qt_meta_data_GlaucaBookmarkController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GlaucaBookmarkController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GlaucaBookmarkController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GlaucaBookmarkController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GlaucaBookmarkController))
        return static_cast<void*>(const_cast< GlaucaBookmarkController*>(this));
    return QObject::qt_metacast(_clname);
}

int GlaucaBookmarkController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setCurrentTab((*reinterpret_cast< GlaucaTabPage*(*)>(_a[1]))); break;
        case 1: setModel((*reinterpret_cast< GlaucaBookmarkModel*(*)>(_a[1]))); break;
        case 2: setView((*reinterpret_cast< GlaucaBookmarkView*(*)>(_a[1]))); break;
        case 3: addBookmarkBtnPressed(); break;
        case 4: saveBookmarkBtnPressed(); break;
        case 5: addNewFolderBtnPressed(); break;
        case 6: varifyFolderName((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 7: delFolderBtnPressed(); break;
        case 8: cancelBtnPressed(); break;
        case 9: refreshBookmarkIcon(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
