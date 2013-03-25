/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      29,    7,    7,    7, 0x08,
      44,    7,    7,    7, 0x08,
      61,    7,    7,    7, 0x08,
     104,    7,    7,    7, 0x08,
     120,  117,    7,    7, 0x08,
     144,    7,    7,    7, 0x08,
     152,    7,    7,    7, 0x08,
     160,    7,    7,    7, 0x08,
     171,    7,    7,    7, 0x08,
     180,    7,    7,    7, 0x08,
     186,    7,    7,    7, 0x08,
     192,    7,    7,    7, 0x08,
     197,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0clickRequestButton()\0"
    "sendToServer()\0readFormServer()\0"
    "displayError(QAbstractSocket::SocketError)\0"
    "setlocalip()\0id\0setip(QListWidgetItem*)\0"
    "call1()\0call2()\0readtime()\0readti()\0"
    "rcu()\0rlk()\0xl()\0sp()\0"
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->clickRequestButton(); break;
        case 1: _t->sendToServer(); break;
        case 2: _t->readFormServer(); break;
        case 3: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->setlocalip(); break;
        case 5: _t->setip((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->call1(); break;
        case 7: _t->call2(); break;
        case 8: _t->readtime(); break;
        case 9: _t->readti(); break;
        case 10: _t->rcu(); break;
        case 11: _t->rlk(); break;
        case 12: _t->xl(); break;
        case 13: _t->sp(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
