/****************************************************************************
** Meta object code from reading C++ file 'CentralWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../GorelikMV_13_12/CentralWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CentralWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CentralWidget_t {
    QByteArrayData data[16];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CentralWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CentralWidget_t qt_meta_stringdata_CentralWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CentralWidget"
QT_MOC_LITERAL(1, 14, 20), // "changeDiagramPicture"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 19), // "changeStatusBarInfo"
QT_MOC_LITERAL(4, 56, 16), // "enableOpenOption"
QT_MOC_LITERAL(5, 73, 17), // "enableCloseOption"
QT_MOC_LITERAL(6, 91, 16), // "enableSaveOption"
QT_MOC_LITERAL(7, 108, 11), // "drawPicture"
QT_MOC_LITERAL(8, 120, 8), // "slotOpen"
QT_MOC_LITERAL(9, 129, 8), // "slotSave"
QT_MOC_LITERAL(10, 138, 10), // "slotSaveAs"
QT_MOC_LITERAL(11, 149, 9), // "slotClose"
QT_MOC_LITERAL(12, 159, 18), // "slotChoosePenColor"
QT_MOC_LITERAL(13, 178, 20), // "slotChooseBrushColor"
QT_MOC_LITERAL(14, 199, 18), // "slotChangePenWidth"
QT_MOC_LITERAL(15, 218, 19) // "slotButtonOkClicked"

    },
    "CentralWidget\0changeDiagramPicture\0\0"
    "changeStatusBarInfo\0enableOpenOption\0"
    "enableCloseOption\0enableSaveOption\0"
    "drawPicture\0slotOpen\0slotSave\0slotSaveAs\0"
    "slotClose\0slotChoosePenColor\0"
    "slotChooseBrushColor\0slotChangePenWidth\0"
    "slotButtonOkClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CentralWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    2,   85,    2, 0x06 /* Public */,
       4,    0,   90,    2, 0x06 /* Public */,
       5,    0,   91,    2, 0x06 /* Public */,
       6,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   93,    2, 0x0a /* Public */,
       8,    0,   94,    2, 0x0a /* Public */,
       9,    0,   95,    2, 0x0a /* Public */,
      10,    0,   96,    2, 0x0a /* Public */,
      11,    0,   97,    2, 0x0a /* Public */,
      12,    0,   98,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    0,  100,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
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

void CentralWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CentralWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeDiagramPicture(); break;
        case 1: _t->changeStatusBarInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->enableOpenOption(); break;
        case 3: _t->enableCloseOption(); break;
        case 4: _t->enableSaveOption(); break;
        case 5: _t->drawPicture(); break;
        case 6: _t->slotOpen(); break;
        case 7: _t->slotSave(); break;
        case 8: _t->slotSaveAs(); break;
        case 9: _t->slotClose(); break;
        case 10: _t->slotChoosePenColor(); break;
        case 11: _t->slotChooseBrushColor(); break;
        case 12: _t->slotChangePenWidth(); break;
        case 13: _t->slotButtonOkClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CentralWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CentralWidget::changeDiagramPicture)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CentralWidget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CentralWidget::changeStatusBarInfo)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CentralWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CentralWidget::enableOpenOption)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CentralWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CentralWidget::enableCloseOption)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CentralWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CentralWidget::enableSaveOption)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CentralWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CentralWidget.data,
    qt_meta_data_CentralWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CentralWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CentralWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CentralWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CentralWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CentralWidget::changeDiagramPicture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CentralWidget::changeStatusBarInfo(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CentralWidget::enableOpenOption()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CentralWidget::enableCloseOption()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CentralWidget::enableSaveOption()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
