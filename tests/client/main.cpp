#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "client.hpp"
#include "ui.hpp"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug() << "Starting Client...";

    spd::Client client;  // Client object is instantiated, and its manager is automatically constructed.
    
    client.connect_to_server("127.0.0.1", 5555);
    client.run_app();

    return app.exec(); // Let the application run
}
