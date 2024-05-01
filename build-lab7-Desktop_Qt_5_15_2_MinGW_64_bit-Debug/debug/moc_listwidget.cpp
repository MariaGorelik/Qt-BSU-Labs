/****************************************************************************
** Meta object code from reading C++ file 'listwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../lab7/listwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListWidget_t {
    QByteArrayData data[18];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListWidget_t qt_meta_stringdata_ListWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ListWidget"
QT_MOC_LITERAL(1, 11, 10), // "addItemPtr"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "QListWidget*"
QT_MOC_LITERAL(4, 36, 7), // "addItem"
QT_MOC_LITERAL(5, 44, 14), // "renameItemsPtr"
QT_MOC_LITERAL(6, 59, 11), // "renameItems"
QT_MOC_LITERAL(7, 71, 14), // "removeItemsPtr"
QT_MOC_LITERAL(8, 86, 11), // "removeItems"
QT_MOC_LITERAL(9, 98, 10), // "clearItems"
QT_MOC_LITERAL(10, 109, 13), // "movingToRight"
QT_MOC_LITERAL(11, 123, 12), // "movingToLeft"
QT_MOC_LITERAL(12, 136, 14), // "changeIconMode"
QT_MOC_LITERAL(13, 151, 15), // "sortListWidget1"
QT_MOC_LITERAL(14, 167, 15), // "sortListWidget2"
QT_MOC_LITERAL(15, 183, 19), // "changeSelectionMode"
QT_MOC_LITERAL(16, 203, 20), // "disableMovingToRight"
QT_MOC_LITERAL(17, 224, 19) // "disableMovingToLeft"

    },
    "ListWidget\0addItemPtr\0\0QListWidget*\0"
    "addItem\0renameItemsPtr\0renameItems\0"
    "removeItemsPtr\0removeItems\0clearItems\0"
    "movingToRight\0movingToLeft\0changeIconMode\0"
    "sortListWidget1\0sortListWidget2\0"
    "changeSelectionMode\0disableMovingToRight\0"
    "disableMovingToLeft"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       4,    0,   92,    2, 0x08 /* Private */,
       5,    1,   93,    2, 0x08 /* Private */,
       6,    0,   96,    2, 0x08 /* Private */,
       7,    1,   97,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addItemPtr((*reinterpret_cast< QListWidget*(*)>(_a[1]))); break;
        case 1: _t->addItem(); break;
        case 2: _t->renameItemsPtr((*reinterpret_cast< QListWidget*(*)>(_a[1]))); break;
        case 3: _t->renameItems(); break;
        case 4: _t->removeItemsPtr((*reinterpret_cast< QListWidget*(*)>(_a[1]))); break;
        case 5: _t->removeItems(); break;
        case 6: _t->clearItems(); break;
        case 7: _t->movingToRight(); break;
        case 8: _t->movingToLeft(); break;
        case 9: _t->changeIconMode(); break;
        case 10: _t->sortListWidget1(); break;
        case 11: _t->sortListWidget2(); break;
        case 12: _t->changeSelectionMode(); break;
        case 13: _t->disableMovingToRight(); break;
        case 14: _t->disableMovingToLeft(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QListWidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QListWidget* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QListWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ListWidget.data,
    qt_meta_data_ListWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
