#ifndef UI_HPP
#define UI_HPP

#include <qmainwindow.h>
#include <memory>
#include <QTextBrowser>
#include <QDateTime>

namespace spd {
    
class UI : public QMainWindow {

Q_OBJECT

public:
    UI();

    void show_event(QDateTime const& a_timeStamp, QString const& a_eventType, QString const& a_eventData, QString const& a_eventLocation);
private:
    void initwindow();

private:
    QWidget m_window;
    QScopedPointer<QTextBrowser> m_event;
};
    
} // namespace spd

#endif //UI_HPP