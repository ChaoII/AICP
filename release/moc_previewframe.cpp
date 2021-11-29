/****************************************************************************
** Meta object code from reading C++ file 'previewframe.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/previewframe.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'previewframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PreviewFrame_t {
    const uint offsetsAndSize[36];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PreviewFrame_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PreviewFrame_t qt_meta_stringdata_PreviewFrame = {
    {
QT_MOC_LITERAL(0, 12), // "PreviewFrame"
QT_MOC_LITERAL(13, 38), // "on_treeView_customContextMenu..."
QT_MOC_LITERAL(52, 0), // ""
QT_MOC_LITERAL(53, 3), // "pos"
QT_MOC_LITERAL(57, 22), // "on_actionAdd_triggered"
QT_MOC_LITERAL(80, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(106, 23), // "on_processCapturedImage"
QT_MOC_LITERAL(130, 3), // "img"
QT_MOC_LITERAL(134, 10), // "labelIndex"
QT_MOC_LITERAL(145, 25), // "on_treeView_doubleClicked"
QT_MOC_LITERAL(171, 11), // "QModelIndex"
QT_MOC_LITERAL(183, 5), // "index"
QT_MOC_LITERAL(189, 23), // "on_actionPlay_triggered"
QT_MOC_LITERAL(213, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(237, 23), // "on_tbFullScreen_clicked"
QT_MOC_LITERAL(261, 22), // "on_tbCutWindow_clicked"
QT_MOC_LITERAL(284, 20), // "on_tbOpenAll_clicked"
QT_MOC_LITERAL(305, 21) // "on_tbCloseAll_clicked"

    },
    "PreviewFrame\0on_treeView_customContextMenuRequested\0"
    "\0pos\0on_actionAdd_triggered\0"
    "on_actionDelete_triggered\0"
    "on_processCapturedImage\0img\0labelIndex\0"
    "on_treeView_doubleClicked\0QModelIndex\0"
    "index\0on_actionPlay_triggered\0"
    "on_actionStop_triggered\0on_tbFullScreen_clicked\0"
    "on_tbCutWindow_clicked\0on_tbOpenAll_clicked\0"
    "on_tbCloseAll_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PreviewFrame[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x08,    1 /* Private */,
       4,    0,   83,    2, 0x08,    3 /* Private */,
       5,    0,   84,    2, 0x08,    4 /* Private */,
       6,    2,   85,    2, 0x08,    5 /* Private */,
       9,    1,   90,    2, 0x08,    8 /* Private */,
      12,    0,   93,    2, 0x08,   10 /* Private */,
      13,    0,   94,    2, 0x08,   11 /* Private */,
      14,    0,   95,    2, 0x08,   12 /* Private */,
      15,    0,   96,    2, 0x08,   13 /* Private */,
      16,    0,   97,    2, 0x08,   14 /* Private */,
      17,    0,   98,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PreviewFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PreviewFrame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_treeView_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->on_actionAdd_triggered(); break;
        case 2: _t->on_actionDelete_triggered(); break;
        case 3: _t->on_processCapturedImage((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_treeView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_actionPlay_triggered(); break;
        case 6: _t->on_actionStop_triggered(); break;
        case 7: _t->on_tbFullScreen_clicked(); break;
        case 8: _t->on_tbCutWindow_clicked(); break;
        case 9: _t->on_tbOpenAll_clicked(); break;
        case 10: _t->on_tbCloseAll_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject PreviewFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PreviewFrame.offsetsAndSize,
    qt_meta_data_PreviewFrame,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PreviewFrame_t
, QtPrivate::TypeAndForceComplete<PreviewFrame, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PreviewFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PreviewFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PreviewFrame.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PreviewFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
