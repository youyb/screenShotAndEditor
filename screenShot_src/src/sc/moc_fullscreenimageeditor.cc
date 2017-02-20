/****************************************************************************
** Meta object code from reading C++ file 'fullscreenimageeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fullscreenimageeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fullscreenimageeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FullScreenImageEditor_t {
    QByteArrayData data[15];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FullScreenImageEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FullScreenImageEditor_t qt_meta_stringdata_FullScreenImageEditor = {
    {
QT_MOC_LITERAL(0, 0, 21), // "FullScreenImageEditor"
QT_MOC_LITERAL(1, 22, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(4, 65, 20), // "on_penButton_clicked"
QT_MOC_LITERAL(5, 86, 21), // "on_undoButton_clicked"
QT_MOC_LITERAL(6, 108, 21), // "on_ovalButton_clicked"
QT_MOC_LITERAL(7, 130, 21), // "on_rectButton_clicked"
QT_MOC_LITERAL(8, 152, 22), // "on_arrowButton_clicked"
QT_MOC_LITERAL(9, 175, 15), // "on_color_picked"
QT_MOC_LITERAL(10, 191, 22), // "on_colorButton_clicked"
QT_MOC_LITERAL(11, 214, 23), // "on_mosaicButton_clicked"
QT_MOC_LITERAL(12, 238, 26), // "on_sizeButtonLarge_clicked"
QT_MOC_LITERAL(13, 265, 27), // "on_sizeButtonNormal_clicked"
QT_MOC_LITERAL(14, 293, 26) // "on_sizeButtonSmall_clicked"

    },
    "FullScreenImageEditor\0on_okButton_clicked\0"
    "\0on_saveButton_clicked\0on_penButton_clicked\0"
    "on_undoButton_clicked\0on_ovalButton_clicked\0"
    "on_rectButton_clicked\0on_arrowButton_clicked\0"
    "on_color_picked\0on_colorButton_clicked\0"
    "on_mosaicButton_clicked\0"
    "on_sizeButtonLarge_clicked\0"
    "on_sizeButtonNormal_clicked\0"
    "on_sizeButtonSmall_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FullScreenImageEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FullScreenImageEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FullScreenImageEditor *_t = static_cast<FullScreenImageEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_okButton_clicked(); break;
        case 1: _t->on_saveButton_clicked(); break;
        case 2: _t->on_penButton_clicked(); break;
        case 3: _t->on_undoButton_clicked(); break;
        case 4: _t->on_ovalButton_clicked(); break;
        case 5: _t->on_rectButton_clicked(); break;
        case 6: _t->on_arrowButton_clicked(); break;
        case 7: _t->on_color_picked(); break;
        case 8: _t->on_colorButton_clicked(); break;
        case 9: _t->on_mosaicButton_clicked(); break;
        case 10: _t->on_sizeButtonLarge_clicked(); break;
        case 11: _t->on_sizeButtonNormal_clicked(); break;
        case 12: _t->on_sizeButtonSmall_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FullScreenImageEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FullScreenImageEditor.data,
      qt_meta_data_FullScreenImageEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FullScreenImageEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FullScreenImageEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FullScreenImageEditor.stringdata0))
        return static_cast<void*>(const_cast< FullScreenImageEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FullScreenImageEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
