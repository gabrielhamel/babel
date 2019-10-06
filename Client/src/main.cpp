/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include "../include/MainWindow.hpp"

using namespace bbl::cli::graphic;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}

// #include "BoostTcpClient.hpp"
// #include "Client.hpp"

// using namespace bbl::cli;

// int main(int argc, char *argv[])
// {
//     ITcpClient *client = new BoostTcpClient("127.0.0.1", 8080);
//     Client cli(client);

//     cli.login("gabriel", "lol");
//     cli.logout();
//     return 0;
// }
