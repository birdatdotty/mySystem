#include "ws.h"

#include <QDBusInterface>
#include <QJsonDocument>
#include <QJsonObject>

#include <QWebSocket>


void Ws::processTextMessage(QString message) {
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient) {
        // "{\"action\":\"clearCache\"}"
        // {user:"admin",password:"PASS",data:{action:"clearCache",N:1}}
        qInfo() << "message:" << message;

        QJsonObject obj = QJsonDocument::fromJson(message.toUtf8()).object();
        if (obj["user"].toString() == "admin")
            if (obj["password"].toString() == "PASS")
            {
                if (obj["data"].isObject()) {
                    QJsonObject data = obj["data"].toObject();
                    if (data["action"].toString() == "clearCache") {
                        int i = obj["N"].toInt(1);
                        QDBusInterface iface("test.service", "/test", "test.iface", QDBusConnection::systemBus());

                        qInfo() << iface.call("message", "{\"action\":\"clearCache\",\"N\":"+QString::number(i)+"}");

                    }
                }
            }
    }
}
