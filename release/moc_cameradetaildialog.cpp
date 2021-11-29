/****************************************************************************
** Meta object code from reading C++ file 'cameradetaildialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/cameradetaildialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameradetaildialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CameraDetailDialog_t {
    const uint offsetsAndSize[22];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CameraDetailDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CameraDetailDialog_t qt_meta_stringdata_CameraDetailDialog = {
    {
QT_MOC_LITERAL(0, 18), // "CameraDetailDialog"
QT_MOC_LITERAL(19, 16), // "sendCameraDetail"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 7), // "Camera*"
QT_MOC_LITERAL(45, 6), // "camera"
QT_MOC_LITERAL(52, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(74, 29), // "on_cmbType_currentTextChanged"
QT_MOC_LITERAL(104, 4), // "arg1"
QT_MOC_LITERAL(109, 29), // "on_cmbBand_currentTextChanged"
QT_MOC_LITERAL(139, 30), // "on_cmbBand_currentIndexChanged"
QT_MOC_LITERAL(170, 5) // "index"

    },
    "CameraDetailDialog\0sendCameraDetail\0"
    "\0Camera*\0camera\0on_buttonBox_accepted\0"
    "on_cmbType_currentTextChanged\0arg1\0"
    "on_cmbBand_currentTextChanged\0"
    "on_cmbBand_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraDetailDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   47,    2, 0x08,    3 /* Private */,
       6,    1,   48,    2, 0x08,    4 /* Private */,
       8,    1,   51,    2, 0x08,    6 /* Private */,
       9,    1,   54,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void CameraDetailDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CameraDetailDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendCameraDetail((*reinterpret_cast< Camera*(*)>(_a[1]))); break;
        case 1: _t->on_buttonBox_accepted(); break;
        case 2: _t->on_cmbType_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_cmbBand_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_cmbBand_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CameraDetailDialog::*)(Camera * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CameraDetailDialog::sendCameraDetail)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CameraDetailDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CameraDetailDialog.offsetsAndSize,
    qt_meta_data_CameraDetailDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CameraDetailDialog_t
, QtPrivate::TypeAndForceComplete<CameraDetailDialog, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Camera *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *CameraDetailDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraDetailDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CameraDetailDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CameraDetailDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CameraDetailDialog::sendCameraDetail(Camera * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
