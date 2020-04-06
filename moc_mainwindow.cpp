/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "signalTargetCoordinate"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "mousepoint"
QT_MOC_LITERAL(4, 46, 17), // "on_circle_clicked"
QT_MOC_LITERAL(5, 64, 17), // "on_clover_clicked"
QT_MOC_LITERAL(6, 82, 21), // "on_Archimedes_clicked"
QT_MOC_LITERAL(7, 104, 16), // "on_snail_clicked"
QT_MOC_LITERAL(8, 121, 21), // "on_scale_valueChanged"
QT_MOC_LITERAL(9, 143, 4), // "arg1"
QT_MOC_LITERAL(10, 148, 30), // "on_intervallength_valueChanged"
QT_MOC_LITERAL(11, 179, 27), // "on_hyperbolicSpiral_clicked"
QT_MOC_LITERAL(12, 207, 22), // "on_aValue_valueChanged"
QT_MOC_LITERAL(13, 230, 19), // "on_Bernulli_clicked"
QT_MOC_LITERAL(14, 250, 25), // "on_stepCount_valueChanged"
QT_MOC_LITERAL(15, 276, 26), // "on_call_calculator_clicked"
QT_MOC_LITERAL(16, 303, 15), // "mousePressEvent"
QT_MOC_LITERAL(17, 319, 25), // "QGraphicsSceneMouseEvent*"
QT_MOC_LITERAL(18, 345, 5) // "event"

    },
    "MainWindow\0signalTargetCoordinate\0\0"
    "mousepoint\0on_circle_clicked\0"
    "on_clover_clicked\0on_Archimedes_clicked\0"
    "on_snail_clicked\0on_scale_valueChanged\0"
    "arg1\0on_intervallength_valueChanged\0"
    "on_hyperbolicSpiral_clicked\0"
    "on_aValue_valueChanged\0on_Bernulli_clicked\0"
    "on_stepCount_valueChanged\0"
    "on_call_calculator_clicked\0mousePressEvent\0"
    "QGraphicsSceneMouseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
      10,    1,   89,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    1,   93,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    1,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalTargetCoordinate((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->on_circle_clicked(); break;
        case 2: _t->on_clover_clicked(); break;
        case 3: _t->on_Archimedes_clicked(); break;
        case 4: _t->on_snail_clicked(); break;
        case 5: _t->on_scale_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_intervallength_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_hyperbolicSpiral_clicked(); break;
        case 8: _t->on_aValue_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_Bernulli_clicked(); break;
        case 10: _t->on_stepCount_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_call_calculator_clicked(); break;
        case 12: _t->mousePressEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalTargetCoordinate)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalTargetCoordinate(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
