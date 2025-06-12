/****************************************************************************
** Meta object code from reading C++ file 'modbusworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../modbusworker.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

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
    "receiveCorrect",
    "data",
    "receiverError",
    "connectToDevice",
    "settings",
    "disconnectToDevice",
    "onModbusStateChanged",
    "QModbusDevice::State",
    "state",
    "onModbusErrorOccurred",
    "QModbusDevice::Error",
    "error",
    "modbusSend",
    "slaveAddress",
    "startAddress",
    "quantity",
    "functionCode",
    "QList<uint16_t>",
    "values"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSModbusWorkerENDCLASS_t {
    uint offsetsAndSizes[50];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[9];
    char stringdata5[19];
    char stringdata6[15];
    char stringdata7[5];
    char stringdata8[14];
    char stringdata9[16];
    char stringdata10[9];
    char stringdata11[19];
    char stringdata12[21];
    char stringdata13[21];
    char stringdata14[6];
    char stringdata15[22];
    char stringdata16[21];
    char stringdata17[6];
    char stringdata18[11];
    char stringdata19[13];
    char stringdata20[13];
    char stringdata21[9];
    char stringdata22[13];
    char stringdata23[16];
    char stringdata24[7];
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
        QT_MOC_LITERAL(71, 14),  // "receiveCorrect"
        QT_MOC_LITERAL(86, 4),  // "data"
        QT_MOC_LITERAL(91, 13),  // "receiverError"
        QT_MOC_LITERAL(105, 15),  // "connectToDevice"
        QT_MOC_LITERAL(121, 8),  // "settings"
        QT_MOC_LITERAL(130, 18),  // "disconnectToDevice"
        QT_MOC_LITERAL(149, 20),  // "onModbusStateChanged"
        QT_MOC_LITERAL(170, 20),  // "QModbusDevice::State"
        QT_MOC_LITERAL(191, 5),  // "state"
        QT_MOC_LITERAL(197, 21),  // "onModbusErrorOccurred"
        QT_MOC_LITERAL(219, 20),  // "QModbusDevice::Error"
        QT_MOC_LITERAL(240, 5),  // "error"
        QT_MOC_LITERAL(246, 10),  // "modbusSend"
        QT_MOC_LITERAL(257, 12),  // "slaveAddress"
        QT_MOC_LITERAL(270, 12),  // "startAddress"
        QT_MOC_LITERAL(283, 8),  // "quantity"
        QT_MOC_LITERAL(292, 12),  // "functionCode"
        QT_MOC_LITERAL(305, 15),  // "QList<uint16_t>"
        QT_MOC_LITERAL(321, 6)   // "values"
    },
    "ModbusWorker",
    "workFinished",
    "",
    "modbusConnected",
    "portName",
    "modbusDisconnected",
    "receiveCorrect",
    "data",
    "receiverError",
    "connectToDevice",
    "settings",
    "disconnectToDevice",
    "onModbusStateChanged",
    "QModbusDevice::State",
    "state",
    "onModbusErrorOccurred",
    "QModbusDevice::Error",
    "error",
    "modbusSend",
    "slaveAddress",
    "startAddress",
    "quantity",
    "functionCode",
    "QList<uint16_t>",
    "values"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSModbusWorkerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    1,   75,    2, 0x06,    2 /* Public */,
       5,    0,   78,    2, 0x06,    4 /* Public */,
       6,    1,   79,    2, 0x06,    5 /* Public */,
       8,    1,   82,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   85,    2, 0x0a,    9 /* Public */,
      11,    0,   88,    2, 0x0a,   11 /* Public */,
      12,    1,   89,    2, 0x0a,   12 /* Public */,
      15,    1,   92,    2, 0x0a,   14 /* Public */,
      18,    5,   95,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString,    4,
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString,    7,
    QMetaType::Int, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariantMap,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 23,   19,   20,   21,   22,   24,

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
        // method 'receiveCorrect'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'receiverError'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'connectToDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<QString,QVariant>, std::false_type>,
        // method 'disconnectToDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onModbusStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModbusDevice::State, std::false_type>,
        // method 'onModbusErrorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModbusDevice::Error, std::false_type>,
        // method 'modbusSend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<uint16_t>, std::false_type>
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
        case 3: { int _r = _t->receiveCorrect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->receiverError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->connectToDevice((*reinterpret_cast< std::add_pointer_t<QMap<QString,QVariant>>>(_a[1]))); break;
        case 6: _t->disconnectToDevice(); break;
        case 7: _t->onModbusStateChanged((*reinterpret_cast< std::add_pointer_t<QModbusDevice::State>>(_a[1]))); break;
        case 8: _t->onModbusErrorOccurred((*reinterpret_cast< std::add_pointer_t<QModbusDevice::Error>>(_a[1]))); break;
        case 9: _t->modbusSend((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QList<uint16_t>>>(_a[5]))); break;
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
        {
            using _t = int (ModbusWorker::*)(QString );
            if (_t _q_method = &ModbusWorker::receiveCorrect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = int (ModbusWorker::*)(QString );
            if (_t _q_method = &ModbusWorker::receiverError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
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

// SIGNAL 3
int ModbusWorker::receiveCorrect(QString _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}

// SIGNAL 4
int ModbusWorker::receiverError(QString _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}
QT_WARNING_POP
