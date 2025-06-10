/****************************************************************************
** Meta object code from reading C++ file 'modbusworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../modbusworker.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbusworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSModbusWorkerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSModbusWorkerENDCLASS = QtMocHelpers::stringData(
    "ModbusWorker",
    "workFinished",
    "",
    "modbusConnected",
    "portName",
    "modbusDisconnected",
    "connectToDevice",
    "settings",
    "disconnectToDevice"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSModbusWorkerENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[9];
    char stringdata5[19];
    char stringdata6[16];
    char stringdata7[9];
    char stringdata8[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSModbusWorkerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSModbusWorkerENDCLASS_t qt_meta_stringdata_CLASSModbusWorkerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "ModbusWorker"
        QT_MOC_LITERAL(13, 12),  // "workFinished"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 15),  // "modbusConnected"
        QT_MOC_LITERAL(43, 8),  // "portName"
        QT_MOC_LITERAL(52, 18),  // "modbusDisconnected"
        QT_MOC_LITERAL(71, 15),  // "connectToDevice"
        QT_MOC_LITERAL(87, 8),  // "settings"
        QT_MOC_LITERAL(96, 18)   // "disconnectToDevice"
    },
    "ModbusWorker",
    "workFinished",
    "",
    "modbusConnected",
    "portName",
    "modbusDisconnected",
    "connectToDevice",
    "settings",
    "disconnectToDevice"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSModbusWorkerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    1,   45,    2, 0x06,    2 /* Public */,
       5,    0,   48,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   49,    2, 0x0a,    5 /* Public */,
       8,    0,   52,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString,    4,
    QMetaType::Int,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariantMap,    7,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ModbusWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSModbusWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSModbusWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSModbusWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ModbusWorker, std::true_type>,
        // method 'workFinished'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'modbusConnected'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'modbusDisconnected'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'connectToDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<QString,QVariant>, std::false_type>,
        // method 'disconnectToDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ModbusWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModbusWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->workFinished();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->modbusConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->modbusDisconnected();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->connectToDevice((*reinterpret_cast< std::add_pointer_t<QMap<QString,QVariant>>>(_a[1]))); break;
        case 4: _t->disconnectToDevice(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (ModbusWorker::*)();
            if (_t _q_method = &ModbusWorker::workFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = int (ModbusWorker::*)(QString );
            if (_t _q_method = &ModbusWorker::modbusConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = int (ModbusWorker::*)();
            if (_t _q_method = &ModbusWorker::modbusDisconnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ModbusWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSModbusWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModbusWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
int ModbusWorker::workFinished()
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int ModbusWorker::modbusConnected(QString _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
int ModbusWorker::modbusDisconnected()
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}
QT_WARNING_POP
