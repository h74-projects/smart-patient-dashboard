#include "client_manager.hpp"
#include "event.hpp"
#include "ui.hpp"

namespace spd {

ClientManager::ClientManager()
: m_socket{std::make_unique<QTcpSocket>(this)}
, m_block_size{0}
, m_event{Event("","","")}
, m_is_eactive{false}
{
    m_serverListener = new QTcpServer(this);
    connect(m_serverListener, &QTcpServer::newConnection, this, &ClientManager::onNewConnection);
    m_serverListener->listen(QHostAddress::LocalHost, 5555);

    connect(m_socket.get(), &QTcpSocket::readyRead, this, &ClientManager::onDataReceived);

    connect(m_socket.get(), &QTcpSocket::connected, [=](){
        qDebug() << "Connected to server!";
    });

    connect(m_socket.get(), &QTcpSocket::disconnected, [=](){
        qDebug() << "Disconnected from server!";
    });

    connect(m_socket.get(), static_cast<void (QTcpSocket::*)(QTcpSocket::SocketError)>(&QTcpSocket::error), [=](QTcpSocket::SocketError error){
        Q_UNUSED(error);
        qDebug() << "Connection Error:" << m_socket->errorString();
    });
}


ClientManager::~ClientManager()
{
    m_socket->close();
    delete m_serverListener;
}


void ClientManager::onDataReceived() 
{
    QTcpSocket* sourceSocket = qobject_cast<QTcpSocket*>(sender());

    if (!sourceSocket) {
        qDebug() << "Invalid source socket.";
        m_is_eactive = false;
        return;
    }

    if (sourceSocket == m_socket.get()) {
        qDebug() << "Data received from m_socket.";

        if (m_socket->state() != QTcpSocket::ConnectedState) {
            qDebug() << "Client socket not in connected state!";
            m_is_eactive = false;
            return;
        }
    } else if (sourceSocket == m_incomingSocket) {
        qDebug() << "Data received from m_incomingSocket.";
    } else {
        qDebug() << "Data received from an unknown socket.";
        m_is_eactive = false;
        return;
    }

    QDataStream in(sourceSocket);

    if (m_block_size == 0) {
        if (sourceSocket->bytesAvailable() < (int)sizeof(quint16)) {
            m_is_eactive = false;
            return; 
        }
        in >> m_block_size;
    }

    if (sourceSocket->bytesAvailable() < m_block_size) {
        qDebug() << "Not enough data available yet. Waiting for more...";
        m_is_eactive = false;
        return;
    }

    QDateTime timeStamp;
    QString eventType;
    QString eventData;
    QString eventLocation;
    in >> timeStamp >> eventType >> eventData >> eventLocation;
    
    qDebug() << "Received Event in CLIENT:";
    qDebug() << "Timestamp:" << timeStamp;
    qDebug() << "Event Type:" << eventType;
    qDebug() << "Event Data:" << eventData;
    qDebug() << "Event Location:" << eventLocation;

    m_event = Event(eventType, eventData, eventLocation);

    m_is_eactive = true;

    //emit newDataReceived(timeStamp, eventType, eventData, eventLocation);

    m_block_size = 0; // Reset block size for next message
}


void ClientManager::connect_to_server(const QString &address, quint16 port)
{
    m_socket->connectToHost(address, port);
}

Event const&ClientManager::current_event() const
{
    return m_event;
}

bool ClientManager::is_event_active() const
{
    return m_is_eactive;
}

void ClientManager::onNewConnection() {
    qDebug() << "Incoming connection detected in ClientManager!";
    m_incomingSocket = m_serverListener->nextPendingConnection();
    connect(m_incomingSocket, &QTcpSocket::readyRead, this, &ClientManager::onDataReceived);
}


} // namespace spd