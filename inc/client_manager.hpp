#ifndef CLIENT_MANAGER_HPP
#define CLIENT_MANAGER_HPP

#include <QObject>
#include <QList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QDateTime>
#include <memory>

#include "event.hpp"
#include "ui.hpp"

namespace spd {

class Client; // forward declaration

class ClientManager : public QObject {

    Q_OBJECT

public:
    ClientManager();
    ~ClientManager();

    ClientManager(ClientManager const& a_other) = delete;
    ClientManager& operator=(ClientManager const& a_other) = delete;

    void connect_to_server(const QString &address, quint16 port);

    Event const& current_event() const;
    bool is_event_active() const;

signals:
    void newDataReceived(QDateTime, QString, QString, QString);

private slots:
    void onDataReceived();
    void onNewConnection();

private:
    std::unique_ptr<QTcpSocket> m_socket;
    quint16 m_block_size;
    QTcpServer *m_serverListener;
    QTcpSocket *m_incomingSocket;
    Event m_event;
    bool m_is_eactive;
};

} // namespace name

#endif //CLIENT_MANAGER_HPP