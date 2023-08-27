#include "ui.hpp"
#include <QTextBrowser>
#include <QDateTime>
#include <memory>
#include <iostream>
#include <QDebug>

namespace spd {

UI::UI()
{
   initwindow();
}

void UI::show_event(QDateTime const& a_timeStamp, QString const& a_eventType, QString const& a_eventData, QString const& a_eventLocation)
{
    QString message = "Received Event in CLIENT:\nTimestamp: "
                         + a_timeStamp.toString("hh:mm:ss") + "\n"
                         + a_eventType + "\n" 
                         + a_eventData + "\n" 
                         + a_eventLocation + "\n";
    m_event.get()->setText(message);
    m_window.show();
}

void UI::initwindow()
{
    m_window.resize(800, 600);
    m_window.setWindowTitle("Simple example");
    m_event.reset(new QTextBrowser(&m_window));
    m_event.get()->setGeometry(10, 10, 120, 80);
    m_window.show();
}

} // namespace spd

