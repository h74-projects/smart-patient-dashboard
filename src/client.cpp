#include "client.hpp"
#include "event.hpp"
#include "client_manager.hpp"
#include <iostream>

namespace spd {

Client::Client()
: m_is_eactive{false}
{
}

void Client::connect_to_server(const QString &address, quint16 port) 
{

    m_manager.connect_to_server(address, port);
}

void Client::run_app()
{
    //ask client manager if event is active
    m_is_eactive = m_manager.is_event_active();
    receive_event();
}

void Client::receive_event()
{
    while(m_is_eactive) {
        m_ui.show_event(m_manager.current_event().getTimestamp()
                        , m_manager.current_event().getEventType()
                        , m_manager.current_event().getEventData()
                        , m_manager.current_event().getEventLocation());
        m_is_eactive = false;
    }
}

} // namespace spd
