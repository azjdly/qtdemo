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
    "modbusStart",
    "",
    "settings",
    "on_CloseBtn_clicked",
    "on_MaxBtn_clicked",
    "on_MinBtn_clicked",
    "on_toolBtn_clicked",
    "on_idBtn_clicked",
    "on_comConnect_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[20];
    char stringdata5[18];
    char stringdata6[18];
    char stringdata7[19];
    char stringdata8[17];
    char stringdata9[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 11),  // "modbusStart"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 8),  // "settings"
        QT_MOC_LITERAL(33, 19),  // "on_CloseBtn_clicked"
        QT_MOC_LITERAL(53, 17),  // "on_MaxBtn_clicked"
        QT_MOC_LITERAL(71, 17),  // "on_MinBtn_clicked"
        QT_MOC_LITERAL(89, 18),  // "on_toolBtn_clicked"
        QT_MOC_LITERAL(108, 16),  // "on_idBtn_clicked"
        QT_MOC_LITERAL(125, 21)   // "on_comConnect_clicked"
    },
    "MainWindow",
    "modbusStart",
    "",
    "settings",
    "on_CloseBtn_clicked",
    "on_MaxBtn_clicked",
    "on_MinBtn_clicked",
    "on_toolBtn_clicked",
    "on_idBtn_clicked",
    "on_comConnect_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   59,    2, 0x08,    3 /* Private */,
       5,    0,   60,    2, 0x08,    4 /* Private */,
       6,    0,   61,    2, 0x08,    5 /* Private */,
       7,    0,   62,    2, 0x08,    6 /* Private */,
       8,    0,   63,    2, 0x08,    7 /* Private */,
       9,    0,   64,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Int, QMetaType::QVariantMap,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        // method 'modbusStart'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<QString,QVariant>, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->modbusStart((*reinterpret_cast< std::add_pointer_t<QMap<QString,QVariant>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->on_CloseBtn_clicked(); break;
        case 2: _t->on_MaxBtn_clicked(); break;
        case 3: _t->on_MinBtn_clicked(); break;
        case 4: _t->on_toolBtn_clicked(); break;
        case 5: _t->on_idBtn_clicked(); break;
        case 6: _t->on_comConnect_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (MainWindow::*)(QMap<QString,QVariant> );
            if (_t _q_method = &MainWindow::modbusStart; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
int MainWindow::modbusStart(QMap<QString,QVariant> _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_WARNING_POP
