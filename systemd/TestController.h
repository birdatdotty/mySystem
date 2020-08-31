#ifndef TEST_CONTROLLER_H
#define TEST_CONTROLLER_H

#include <QObject>
#include <QDBusContext>
#include <QDBusConnection>
#include <QDebug>

class TestController: public QObject, protected QDBusContext {
	Q_OBJECT
	Q_CLASSINFO("D-Bus Interface", "test.iface") // Имя интерфейса

public:
    Q_INVOKABLE int message(QString msg);

private slots:
    int clearCash(int i = 1);

};

#endif // TEST_CONTROLLER_H
