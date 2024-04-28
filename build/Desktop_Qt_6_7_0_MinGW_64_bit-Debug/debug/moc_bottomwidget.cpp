/****************************************************************************
** Meta object code from reading C++ file 'bottomwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../bottomwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bottomwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBottomWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSBottomWidgetENDCLASS = QtMocHelpers::stringData(
    "BottomWidget",
    "sendFrame",
    "",
    "cv::Mat",
    "mat",
    "signalNum",
    "val",
    "startRunning",
    "VideoStruct",
    "video",
    "signalStop",
    "slotsAddPicture",
    "slotsInference",
    "slotsAddModel",
    "slotsAddVideo",
    "receivResult",
    "num",
    "slotCheckVideo",
    "slotCheckPicture",
    "slotCapFrame",
    "slotStopVideo",
    "slotExit"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBottomWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,
       5,    1,  101,    2, 0x06,    3 /* Public */,
       7,    1,  104,    2, 0x06,    5 /* Public */,
      10,    1,  107,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  110,    2, 0x0a,    9 /* Public */,
      12,    0,  111,    2, 0x0a,   10 /* Public */,
      13,    0,  112,    2, 0x0a,   11 /* Public */,
      14,    0,  113,    2, 0x0a,   12 /* Public */,
      15,    2,  114,    2, 0x0a,   13 /* Public */,
      17,    1,  119,    2, 0x08,   16 /* Private */,
      18,    1,  122,    2, 0x08,   18 /* Private */,
      19,    0,  125,    2, 0x08,   20 /* Private */,
      20,    0,  126,    2, 0x08,   21 /* Private */,
      21,    0,  127,    2, 0x08,   22 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,   16,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BottomWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSBottomWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBottomWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBottomWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BottomWidget, std::true_type>,
        // method 'sendFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<cv::Mat, std::false_type>,
        // method 'signalNum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'startRunning'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<VideoStruct, std::false_type>,
        // method 'signalStop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<VideoStruct, std::false_type>,
        // method 'slotsAddPicture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotsInference'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotsAddModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotsAddVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receivResult'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<cv::Mat, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotCheckVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotCheckPicture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotCapFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotStopVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotExit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BottomWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BottomWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendFrame((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1]))); break;
        case 1: _t->signalNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->startRunning((*reinterpret_cast< std::add_pointer_t<VideoStruct>>(_a[1]))); break;
        case 3: _t->signalStop((*reinterpret_cast< std::add_pointer_t<VideoStruct>>(_a[1]))); break;
        case 4: _t->slotsAddPicture(); break;
        case 5: _t->slotsInference(); break;
        case 6: _t->slotsAddModel(); break;
        case 7: _t->slotsAddVideo(); break;
        case 8: _t->receivResult((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->slotCheckVideo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->slotCheckPicture((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->slotCapFrame(); break;
        case 12: _t->slotStopVideo(); break;
        case 13: _t->slotExit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BottomWidget::*)(cv::Mat );
            if (_t _q_method = &BottomWidget::sendFrame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)(int );
            if (_t _q_method = &BottomWidget::signalNum; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)(VideoStruct );
            if (_t _q_method = &BottomWidget::startRunning; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BottomWidget::*)(VideoStruct );
            if (_t _q_method = &BottomWidget::signalStop; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *BottomWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BottomWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBottomWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BottomWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void BottomWidget::sendFrame(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BottomWidget::signalNum(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BottomWidget::startRunning(VideoStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BottomWidget::signalStop(VideoStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
