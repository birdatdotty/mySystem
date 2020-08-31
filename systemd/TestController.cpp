#include "TestController.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

int TestController::message(QString msg)
{
    qInfo() << "Q_INVOKABLE int message(QString msg)" << msg;
    QJsonObject obj = QJsonDocument::fromJson(msg.toUtf8()).object();
    if (obj["action"].toString() == "clearCache")
        return clearCash(obj["N"].toInt(1));

    return -1;

//    return clearCash();
}

int TestController::clearCash(int i)
{
    QString i_str = QString::number(i);
    QFile drop_caches("/proc/sys/vm/drop_caches");
    if (drop_caches.open(QIODevice::WriteOnly)) {
        if (system("sync") != 0)
            return 1;
        drop_caches.write(i_str.toUtf8());
        drop_caches.flush();
        return 0;
    }
    return 2;
}
