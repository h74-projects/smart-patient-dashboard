#ifndef UI_HPP
#define UI_HPP

#include <qmainwindow.h>
#include <QPushButton>
#include <QDateTime>
#include <QList>
#include <QDebug>
#include <QStackedWidget>
#include <QWidget>

#include "ui_main_window.hpp"
#include "ui_events_window.hpp"
#include "event.hpp"

namespace spd {
    
class UI : public QWidget {

    Q_OBJECT
signals:
    void set_room_num(int a_rnum);

private slots:
    void switch_to_main_screen();
    void switch_to_event_screen(size_t const& a_roomn);

public:
    UI(QWidget* parent = nullptr);
    ~UI();

    void add_event(Event const& a_event);
    void update_event(Event const& a_event, size_t const& a_podition);

    void add_abnorml_event(Event const& a_event);
    void update_abnorml_event(Event const& a_event, size_t const& a_podition);

private:
    void init_screens();
    void init_window();
    void change_window(int const& a_win_num);

private:
    QStackedWidget* m_stacked_widget;
    UIMainWindow* m_main_window;
    UIEventWindow* m_event_window;
    int m_window_num;
};
    
} // namespace spd

#endif //UI_HPP