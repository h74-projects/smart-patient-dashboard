#include "server_manager.hpp"
#include "room_handler.hpp"
#include "pulse_event_handler.hpp"

ServerManager::ServerManager()
{
    m_simple_server_instance.connect_to_client_manager(QHostAddress::LocalHost, 5555); //random port
    connect(&m_simple_server_instance, &SimpleServer::eventReceived, this, &ServerManager::handleReceivedEvent);
    connect(&m_simple_server_instance, &SimpleServer::requestReceived, this, &ServerManager::send_event);
}



void ServerManager::start_services()
{
    // ALL SERVER TASKS GO HERE
    // simpleServer is already started in ctor

}

void ServerManager::handleReceivedEvent(const Event &event)
{
    EventRouter(event);
}


void ServerManager::EventRouter(const Event &event)
{
    int room_number = event.getEventLocation().toInt();
    // int room_number = 1;
    QString sensor_type = event.getEventType();

    if (!m_room_to_handlers_map.contains(room_number))
    {
        m_room_to_handlers_map[room_number] = std::make_shared<RoomHandler>();
    }

    std::shared_ptr<RoomHandler>& handlers = m_room_to_handlers_map[room_number];

    if (sensor_type == "Pulse")
    {
        if (!m_room_to_handlers_map[room_number]->get_pulse_handler_flag())
        {
            connect(handlers->pulseHandler.get(), &PulseEventHandler::alertGenerated, this, &ServerManager::addAlert);
            connect(handlers->pulseHandler.get(), &PulseEventHandler::eventProcessed, this, &ServerManager::updateEventToRoomMap);
            m_room_to_handlers_map[room_number]->set_pulse_handler_flag(true);
        }
        handlers->pulseHandler->handleEvent(event);
    }

}

void ServerManager::addAlert(const Event& event) 
{
    qDebug() << "enqueued to alerts: " << event.getEventData();
    m_alerts.enqueue(event);
}

void ServerManager::updateEventToRoomMap(int room_number, const Event& event) 
{
    m_event_to_room_map[room_number].enqueue(event);
    
}
    //other sensor types as needed.



void ServerManager::send_event(int room_number) 
{
    qDebug() << "\nRoom number accepterd by send_event function: " << room_number << '\n';
    if(m_event_to_room_map.contains(room_number) && !m_event_to_room_map[room_number].isEmpty()){
        Event dequeued_Event = m_event_to_room_map[room_number].dequeue();
        qDebug() << " sent event" << dequeued_Event.getEventType() << dequeued_Event.getEventType() << '\n'; 
        m_simple_server_instance.forward_event_to_client(dequeued_Event);
        m_event_to_room_map[room_number].clear();
    }
    // int alertsSent = 0;
    if (!m_alerts.isEmpty()) {
        Event alert_event = m_alerts.dequeue();
        m_simple_server_instance.forward_event_to_client(alert_event);
        // alertsSent++;
    }
    m_alerts.clear();

}


