#ifndef CONN_H
#define CONN_H

#include <QObject>
#include <QWebSocketServer>

class Ws: public QObject
{
public:
    explicit Ws(quint16 port, QObject *parent = nullptr);
    ~Ws();

signals:
    void closed();

private slots:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();

    void changeConnList();

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket*> m_clients;
    QStringList clientsList;
};

#endif // CONN_H

