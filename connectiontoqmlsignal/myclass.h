#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QQuickItem>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
public:
    MyClass(QObject *parent = 0);

public slots:
    // This is a slot for QString only
    void cppSlot(const QString &msg) {
        qDebug() << "Called the C++ slot with message:" << msg;
    }

    // This is the slot for a generic data type
    void cppSlotForGenericData(const QVariant &v) {
        qDebug() << "Called the C++ slot with value:" << v;

        QQuickItem *item = qobject_cast<QQuickItem*>(v.value<QObject*>());
        qDebug() << "Item dimensions:" << item->width() << item->height();
    }
};

#endif // MYCLASS_H
