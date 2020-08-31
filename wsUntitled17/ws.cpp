#include "ws.h"

#include <QWebSocket>

Ws::Ws (quint16 port, QObject *parent)
    : QObject(parent),
      m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Server"),
                                              QWebSocketServer::NonSecureMode,
                                              this))
{
    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &Ws::onNewConnection);
    }
}

Ws::~Ws () {
    delete m_pWebSocketServer;
}

void Ws::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &Ws::processTextMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &Ws::socketDisconnected);

    m_clients << pSocket;
    changeConnList();
}

void Ws::socketDisconnected() {
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient) {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
    changeConnList();
}

void Ws::changeConnList() {
    clientsList.clear();
    for (QWebSocket* c: m_clients) {
        clientsList.append(c->peerAddress().toString() +
                           ":" +
                           QString::number( c->peerPort() ));
    }
    qInfo() << clientsList;
}

