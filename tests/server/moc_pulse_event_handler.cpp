/****************************************************************************
** Meta object code from reading C++ file 'pulse_event_handler.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/pulse_event_handler.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pulse_event_handler.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PulseEventHandler_t {
    QByteArrayData data[7];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PulseEventHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PulseEventHandler_t qt_meta_stringdata_PulseEventHandler = {
    {
QT_MOC_LITERAL(0, 0, 17), // "PulseEventHandler"
QT_MOC_LITERAL(1, 18, 14), // "alertGenerated"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "Event"
QT_MOC_LITERAL(4, 40, 5), // "event"
QT_MOC_LITERAL(5, 46, 14), // "eventProcessed"
QT_MOC_LITERAL(6, 61, 11) // "room_number"

    },
    "PulseEventHandler\0alertGenerated\0\0"
    "Event\0event\0eventProcessed\0room_number"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PulseEventHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    2,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    6,    4,

       0        // eod
};

void PulseEventHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PulseEventHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->alertGenerated((*reinterpret_cast< const Event(*)>(_a[1]))); break;
        case 1: _t->eventProcessed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const Event(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PulseEventHandler::*)(const Event & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PulseEventHandler::alertGenerated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PulseEventHandler::*)(int , const Event & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PulseEventHandler::eventProcessed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PulseEventHandler::staticMetaObject = { {
    &EventHandlerBase::staticMetaObject,
    qt_meta_stringdata_PulseEventHandler.data,
    qt_meta_data_PulseEventHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PulseEventHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PulseEventHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PulseEventHandler.stringdata0))
        return static_cast<void*>(this);
    return EventHandlerBase::qt_metacast(_clname);
}

int PulseEventHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EventHandlerBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PulseEventHandler::alertGenerated(const Event & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PulseEventHandler::eventProcessed(int _t1, const Event & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
