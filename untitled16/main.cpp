#include "MainWindow.h"

#include <QApplication>
#include <QDBusInterface>

int main(int argc, char *argv[])
{
    if (!QDBusConnection::sessionBus().isConnected()) {
        qWarning("Cannot connect to the D-Bus session bus.\n"
                 "Please check your system settings and try again.\n");
        return 1;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QDBusMessage message = QDBusMessage::createSignal("/test",
//                                   "test.service", "ping");

    return a.exec();
}
