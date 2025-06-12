/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "modbusConnect",
    "",
    "settings",
    "modbusDisconnect",
    "modbusSend",
    "slaveAddress",
    "startAddress",
    "quantity",
    "functionCode",
    "QList<uint16_t>",
    "values",
    "on_CloseBtn_clicked",
    "on_MaxBtn_clicked",
    "on_MinBtn_clicked",
    "on_toolBtn_clicked",
    "on_idBtn_clicked",
    "on_comConnect_clicked",
    "on_comDisconnect_clicked",
    "on_addTaskBtn_clicked",
    "on_functionCode_currentIndexChanged",
    "index",
    "on_deleteTaskBtn_clicked",
    "on_cycleCheck_stateChanged",
    "arg1",
    "on_cleanBtn_clicked",
    "on_singleBtn_clicked",
    "on_QssBtn_clicked",
    "changeStyle",
    "style"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[60];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[17];
    char stringdata5[11];
    char stringdata6[13];
    char stringdata7[13];
    char stringdata8[9];
    char stringdata9[13];
    char stringdata10[16];
    char stringdata11[7];
    char stringdata12[20];
    char stringdata13[18];
    char stringdata14[18];
    char stringdata15[19];
    char stringdata16[17];
    char stringdata17[22];
    char stringdata18[25];
    char stringdata19[22];
    char stringdata20[36];
    char stringdata21[6];
    char stringdata22[25];
    char stringdata23[27];
    char stringdata24[5];
    char stringdata25[20];
    char stringdata26[21];
    char stringdata27[18];
    char stringdata28[12];
    char stringdata29[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "modbusConnect"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 8),  // "settings"
        QT_MOC_LITERAL(35, 16),  // "modbusDisconnect"
        QT_MOC_LITERAL(52, 10),  // "modbusSend"
        QT_MOC_LITERAL(63, 12),  // "slaveAddress"
        QT_MOC_LITERAL(76, 12),  // "startAddress"
        QT_MOC_LITERAL(89, 8),  // "quantity"
        QT_MOC_LITERAL(98, 12),  // "functionCode"
        QT_MOC_LITERAL(111, 15),  // "QList<uint16_t>"
        QT_MOC_LITERAL(127, 6),  // "values"
        QT_MOC_LITERAL(134, 19),  // "on_CloseBtn_clicked"
        QT_MOC_LITERAL(154, 17),  // "on_MaxBtn_clicked"
        QT_MOC_LITERAL(172, 17),  // "on_MinBtn_clicked"
        QT_MOC_LITERAL(190, 18),  // "on_toolBtn_clicked"
        QT_MOC_LITERAL(209, 16),  // "on_idBtn_clicked"
        QT_MOC_LITERAL(226, 21),  // "on_comConnect_clicked"
        QT_MOC_LITERAL(248, 24),  // "on_comDisconnect_clicked"
        QT_MOC_LITERAL(273, 21),  // "on_addTaskBtn_clicked"
        QT_MOC_LITERAL(295, 35),  // "on_functionCode_currentIndexC..."
        QT_MOC_LITERAL(331, 5),  // "index"
        QT_MOC_LITERAL(337, 24),  // "on_deleteTaskBtn_clicked"
        QT_MOC_LITERAL(362, 26),  // "on_cycleCheck_stateChanged"
        QT_MOC_LITERAL(389, 4),  // "arg1"
        QT_MOC_LITERAL(394, 19),  // "on_cleanBtn_clicked"
        QT_MOC_LITERAL(414, 20),  // "on_singleBtn_clicked"
        QT_MOC_LITERAL(435, 17),  // "on_QssBtn_clicked"
        QT_MOC_LITERAL(453, 11),  // "changeStyle"
        QT_MOC_LITERAL(465, 5)   // "style"
    },
    "MainWindow",
    "modbusConnect",
    "",
    "settings",
    "modbusDisconnect",
    "modbusSend",
    "slaveAddress",
    "startAddress",
    "quantity",
    "functionCode",
    "QList<uint16_t>",
    "values",
    "on_CloseBtn_clicked",
    "on_MaxBtn_clicked",
    "on_MinBtn_clicked",
    "on_toolBtn_clicked",
    "on_idBtn_clicked",
    "on_comConnect_clicked",
    "on_comDisconnect_clicked",
    "on_addTaskBtn_clicked",
    "on_functionCode_currentIndexChanged",
    "index",
    "on_deleteTaskBtn_clicked",
    "on_cycleCheck_stateChanged",
    "arg1",
    "on_cleanBtn_clicked",
    "on_singleBtn_clicked",
    "on_QssBtn_clicked",
    "changeStyle",
    "style"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x06,    1 /* Public */,
       4,    0,  125,    2, 0x06,    3 /* Public */,
       5,    5,  126,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,  137,    2, 0x08,   10 /* Private */,
      13,    0,  138,    2, 0x08,   11 /* Private */,
      14,    0,  139,    2, 0x08,   12 /* Private */,
      15,    0,  140,    2, 0x08,   13 /* Private */,
      16,    0,  141,    2, 0x08,   14 /* Private */,
      17,    0,  142,    2, 0x08,   15 /* Private */,
      18,    0,  143,    2, 0x08,   16 /* Private */,
      19,    0,  144,    2, 0x08,   17 /* Private */,
      20,    1,  145,    2, 0x08,   18 /* Private */,
      22,    0,  148,    2, 0x08,   20 /* Private */,
      23,    1,  149,    2, 0x08,   21 /* Private */,
      25,    0,  152,    2, 0x08,   23 /* Private */,
      26,    0,  153,    2, 0x08,   24 /* Private */,
      27,    0,  154,    2, 0x08,   25 /* Private */,
      28,    1,  155,    2, 0x08,   26 /* Private */,

 // signals: parameters
    QMetaType::Int, QMetaType::QVariantMap,    3,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 10,    6,    7,    8,    9,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'modbusConnect'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<QString,QVariant>, std::false_type>,
        // method 'modbusDisconnect'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'modbusSend'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<uint16_t>, std::false_type>,
        // method 'on_CloseBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_MaxBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_MinBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_idBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comDisconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addTaskBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_functionCode_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_deleteTaskBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cycleCheck_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_cleanBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_singleBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_QssBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeStyle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->modbusConnect((*reinterpret_cast< std::add_pointer_t<QMap<QString,QVariant>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->modbusDisconnect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->modbusSend((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QList<uint16_t>>>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_CloseBtn_clicked(); break;
        case 4: _t->on_MaxBtn_clicked(); break;
        case 5: _t->on_MinBtn_clicked(); break;
        case 6: _t->on_toolBtn_clicked(); break;
        case 7: _t->on_idBtn_clicked(); break;
        case 8: _t->on_comConnect_clicked(); break;
        case 9: _t->on_comDisconnect_clicked(); break;
        case 10: _t->on_addTaskBtn_clicked(); break;
        case 11: _t->on_functionCode_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->on_deleteTaskBtn_clicked(); break;
        case 13: _t->on_cycleCheck_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_cleanBtn_clicked(); break;
        case 15: _t->on_singleBtn_clicked(); break;
        case 16: _t->on_QssBtn_clicked(); break;
        case 17: _t->changeStyle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (MainWindow::*)(QMap<QString,QVariant> );
            if (_t _q_method = &MainWindow::modbusConnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = int (MainWindow::*)();
            if (_t _q_method = &MainWindow::modbusDisconnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = int (MainWindow::*)(int , int , int , QString , QVector<uint16_t> );
            if (_t _q_method = &MainWindow::modbusSend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
int MainWindow::modbusConnect(QMap<QString,QVariant> _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int MainWindow::modbusDisconnect()
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
int MainWindow::modbusSend(int _t1, int _t2, int _t3, QString _t4, QVector<uint16_t> _t5)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}
QT_WARNING_POP
