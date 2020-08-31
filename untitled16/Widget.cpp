#include "Widget.h"

#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusMessage>

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      labelCache(new QLabel("cache")),
      btnCache(new QPushButton("очистить"))
{
    mainLayout.addWidget(labelCache,0,0);
    mainLayout.addWidget(btnCache,0,1);

    connect(btnCache, &QPushButton::released,
            this, &Widget::clearCache);

    setLayout(&mainLayout);
}

void Widget::clearCache() {
    QDBusInterface iface("test.service", "/test", "test.iface", QDBusConnection::systemBus());

    qInfo() << iface.call("message", "{\"action\":\"clearCache\"}");
}
