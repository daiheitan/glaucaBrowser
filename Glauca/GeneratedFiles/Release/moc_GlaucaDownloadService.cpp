/****************************************************************************
** Meta object code from reading C++ file 'GlaucaDownloadService.h'
**
** Created: Fri Jul 22 15:54:02 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GlaucaDownloadService.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlaucaDownloadService.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_downloadBarItem[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      25,   16,   16,   16, 0x05,
      33,   16,   16,   16, 0x05,
      46,   16,   16,   16, 0x05,
      59,   16,   16,   16, 0x05,
      68,   16,   16,   16, 0x05,
      79,   16,   16,   16, 0x05,
      90,   16,   16,   16, 0x05,
     100,   16,   16,   16, 0x05,
     111,   16,   16,   16, 0x05,
     138,  123,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     177,  170,   16,   16, 0x08,
     201,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_downloadBarItem[] = {
    "downloadBarItem\0\0pause()\0conti()\0"
    "openFolder()\0reDownload()\0cancel()\0"
    "openFile()\0copyLink()\0delFile()\0"
    "finished()\0readyRead()\0received,total\0"
    "downloadProgress(qint64,qint64)\0action\0"
    "menuTriggered(QAction*)\0copyLinkLocation()\0"
};

const QMetaObject downloadBarItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_downloadBarItem,
      qt_meta_data_downloadBarItem, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &downloadBarItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *downloadBarItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *downloadBarItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_downloadBarItem))
        return static_cast<void*>(const_cast< downloadBarItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int downloadBarItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pause(); break;
        case 1: conti(); break;
        case 2: openFolder(); break;
        case 3: reDownload(); break;
        case 4: cancel(); break;
        case 5: openFile(); break;
        case 6: copyLink(); break;
        case 7: delFile(); break;
        case 8: finished(); break;
        case 9: readyRead(); break;
        case 10: downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 11: menuTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 12: copyLinkLocation(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void downloadBarItem::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void downloadBarItem::conti()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void downloadBarItem::openFolder()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void downloadBarItem::reDownload()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void downloadBarItem::cancel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void downloadBarItem::openFile()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void downloadBarItem::copyLink()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void downloadBarItem::delFile()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void downloadBarItem::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void downloadBarItem::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void downloadBarItem::downloadProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
static const uint qt_meta_data_downloadView[] = {

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

static const char qt_meta_stringdata_downloadView[] = {
    "downloadView\0"
};

const QMetaObject downloadView::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_downloadView,
      qt_meta_data_downloadView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &downloadView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *downloadView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *downloadView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_downloadView))
        return static_cast<void*>(const_cast< downloadView*>(this));
    return QObject::qt_metacast(_clname);
}

int downloadView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_downloadController[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      43,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_downloadController[] = {
    "downloadController\0\0pathWinConfirmAction()\0"
    "pathBtnPressed()\0"
};

const QMetaObject downloadController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_downloadController,
      qt_meta_data_downloadController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &downloadController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *downloadController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *downloadController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_downloadController))
        return static_cast<void*>(const_cast< downloadController*>(this));
    return QObject::qt_metacast(_clname);
}

int downloadController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pathWinConfirmAction(); break;
        case 1: pathBtnPressed(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_downloadModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   15,   14,   14, 0x0a,
      54,   14,   14,   14, 0x0a,
      73,   14,   14,   14, 0x0a,
     102,   92,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_downloadModel[] = {
    "downloadModel\0\0path,url\0"
    "downloadProcess(QString,QUrl)\0"
    "downloadFinished()\0readyReadContent()\0"
    "got,total\0downloadProgressAction(qint64,qint64)\0"
};

const QMetaObject downloadModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_downloadModel,
      qt_meta_data_downloadModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &downloadModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *downloadModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *downloadModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_downloadModel))
        return static_cast<void*>(const_cast< downloadModel*>(this));
    return QObject::qt_metacast(_clname);
}

int downloadModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: downloadProcess((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QUrl(*)>(_a[2]))); break;
        case 1: downloadFinished(); break;
        case 2: readyReadContent(); break;
        case 3: downloadProgressAction((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_downloadBarController[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      41,   22,   22,   22, 0x0a,
      62,   22,   22,   22, 0x0a,
      80,   22,   22,   22, 0x0a,
     105,   22,   22,   22, 0x0a,
     126,   22,   22,   22, 0x0a,
     154,  149,   22,   22, 0x0a,
     201,   22,   22,   22, 0x0a,
     227,   22,   22,   22, 0x0a,
     247,   22,   22,   22, 0x0a,
     264,   22,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_downloadBarController[] = {
    "downloadBarController\0\0pauseBtnPressed()\0"
    "continueBtnPressed()\0abortBtnPressed()\0"
    "openFilePathBtnPressed()\0openFileBtnPressed()\0"
    "deleteFileBtnPressed()\0item\0"
    "deleteDownloadItemBtnPressed(downloadBarItem*)\0"
    "deleteAllItemBtnPressed()\0restartBtnPressed()\0"
    "updateBarSpeed()\0updateBarPercent()\0"
};

const QMetaObject downloadBarController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_downloadBarController,
      qt_meta_data_downloadBarController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &downloadBarController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *downloadBarController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *downloadBarController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_downloadBarController))
        return static_cast<void*>(const_cast< downloadBarController*>(this));
    return QObject::qt_metacast(_clname);
}

int downloadBarController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pauseBtnPressed(); break;
        case 1: continueBtnPressed(); break;
        case 2: abortBtnPressed(); break;
        case 3: openFilePathBtnPressed(); break;
        case 4: openFileBtnPressed(); break;
        case 5: deleteFileBtnPressed(); break;
        case 6: deleteDownloadItemBtnPressed((*reinterpret_cast< downloadBarItem*(*)>(_a[1]))); break;
        case 7: deleteAllItemBtnPressed(); break;
        case 8: restartBtnPressed(); break;
        case 9: updateBarSpeed(); break;
        case 10: updateBarPercent(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
