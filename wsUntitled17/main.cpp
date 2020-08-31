#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusInterface>

#include "ws.h"

#include <QDebug>

#define SERVICE_NAME "wstest.service"
#define OBJECT_PATH "/test"

#define PORT 9999


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Создаём соединение с системной шиной D-Bus
    QDBusConnection conn = QDBusConnection::systemBus();

    // Регистрируем сервис
    if (! conn.registerService(SERVICE_NAME)) {
        qDebug() << "Error:" <<  conn.lastError().message();
        exit(EXIT_FAILURE);
    }

    Ws ws(PORT);
    // Регистрируем контроллер
    conn.registerObject(OBJECT_PATH, &ws, QDBusConnection::ExportAllContents);

    return a.exec();
}
