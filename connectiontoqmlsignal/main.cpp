#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>

#include "myclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:///Main.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    QObject *item = view.rootObject();
    MyClass myClass;

    // Connect a QString data type slot
    QObject::connect(item, SIGNAL(qmlSignal(QString)),
                     &myClass, SLOT(cppSlot(QString)));

    // Connect a generic slot
    QObject::connect(item, SIGNAL(qmlSignalGeneric(QVariant)),
                         &myClass, SLOT(cppSlotForGenericData(QVariant)));

    view.show();
    return app.exec();
}

