#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <QString>
#include <memory>
#include "client_manager.hpp"
#include "ui.hpp"
#include "event.hpp"

namespace spd {
class Client {
public:
    Client();

    void connect_to_server(const QString &address, quint16 port);
    void run_app();
    
private:
    void receive_event();
private:
    ClientManager m_manager;
    UI m_ui;
    bool m_is_eactive;
    //List User; <-id,name,password
};

} // namespace spd

#endif //CLIENT_HPP

