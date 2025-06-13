/****************************************************************************
** Meta object code from reading C++ file 'modbusworker.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../modbusworker.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbusworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
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
struct qt_meta_tag_ZN12ModbusWorkerE_t {};
} // unnamed namespace

template <> constexpr inline auto ModbusWorker::qt_create_metaobjectdata<qt_meta_tag_ZN12ModbusWorkerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
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
        "QMap<QString,QVariant>",
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

    QtMocHelpers::UintData qt_methods {
        // Signal 'workFinished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'modbusConnected'
        QtMocHelpers::SignalData<void(QString)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'modbusDisconnected'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'receiveCorrect'
        QtMocHelpers::SignalData<void(QString)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Signal 'receiverError'
        QtMocHelpers::SignalData<void(QString)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'connectToDevice'
        QtMocHelpers::SlotData<void(QMap<QString,QVariant>)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'disconnectToDevice'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onModbusStateChanged'
        QtMocHelpers::SlotData<void(QModbusDevice::State)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
        // Slot 'onModbusErrorOccurred'
        QtMocHelpers::SlotData<void(QModbusDevice::Error)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 17, 18 },
        }}),
        // Slot 'modbusSend'
        QtMocHelpers::SlotData<void(int, int, int, QString, QVector<uint16_t>)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 20 }, { QMetaType::Int, 21 }, { QMetaType::Int, 22 }, { QMetaType::QString, 23 },
            { 0x80000000 | 24, 25 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ModbusWorker, qt_meta_tag_ZN12ModbusWorkerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ModbusWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ModbusWorkerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ModbusWorkerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12ModbusWorkerE_t>.metaTypes,
    nullptr
} };

void ModbusWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ModbusWorker *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->workFinished(); break;
        case 1: _t->modbusConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->modbusDisconnected(); break;
        case 3: _t->receiveCorrect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->receiverError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->connectToDevice((*reinterpret_cast< std::add_pointer_t<QMap<QString,QVariant>>>(_a[1]))); break;
        case 6: _t->disconnectToDevice(); break;
        case 7: _t->onModbusStateChanged((*reinterpret_cast< std::add_pointer_t<QModbusDevice::State>>(_a[1]))); break;
        case 8: _t->onModbusErrorOccurred((*reinterpret_cast< std::add_pointer_t<QModbusDevice::Error>>(_a[1]))); break;
        case 9: _t->modbusSend((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QList<uint16_t>>>(_a[5]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ModbusWorker::*)()>(_a, &ModbusWorker::workFinished, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ModbusWorker::*)(QString )>(_a, &ModbusWorker::modbusConnected, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ModbusWorker::*)()>(_a, &ModbusWorker::modbusDisconnected, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ModbusWorker::*)(QString )>(_a, &ModbusWorker::receiveCorrect, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ModbusWorker::*)(QString )>(_a, &ModbusWorker::receiverError, 4))
            return;
    }
}

const QMetaObject *ModbusWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ModbusWorkerE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ModbusWorker::workFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ModbusWorker::modbusConnected(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ModbusWorker::modbusDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ModbusWorker::receiveCorrect(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void ModbusWorker::receiverError(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
