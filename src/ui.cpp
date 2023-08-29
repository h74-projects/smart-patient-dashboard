#include "ui.hpp"
#include <QTextBrowser>
#include <QDateTime>
#include <memory>
#include <iostream>
#include <QDebug>
#include <QPainter>
#include "const_and_enums.hpp"
#include "ui_main_window.hpp"
#include <QResizeEvent>

namespace spd {

UI::UI()
: m_main_window{m_window}
{
    init_window();
    init_room();
    m_window.show();
}

void UI::show_event(QDateTime const& a_timeStamp, QString const& a_eventType, QString const& a_eventData, QString const& a_eventLocation)
{
    QString message = "Received Event in CLIENT:\nTimestamp: "
                         + a_timeStamp.toString("hh:mm:ss") + "\n"
                         + a_eventType + "\n" 
                         + a_eventData + "\n" 
                         + a_eventLocation + "\n";
    m_rooms[0]->setText(message);
}

void UI::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    this->resize(event->size());
    m_main_window.resizeEvent(*this);
    m_main_window.resize(this->size());
}

void UI::init_window()
{
    m_window.setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_window.setWindowTitle(WINDOW_TITLE);
}

void UI::init_room()
{
    m_rooms.append(new QPushButton("Room 1", &m_window));
    m_rooms[0]->setGeometry(360, 45, 80, 80);
}

} // namespace spd

