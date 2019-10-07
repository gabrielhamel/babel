/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include "../include/Graphic/MainWindow.hpp"

using namespace bbl::cli::graphic;

int main(int argc, char *argv[])
{
    if (argc != 3)
        return (84);
    QApplication a(argc, argv);
    MainWindow w(argv[1], atoi(argv[2]));

    w.show();
    return a.exec();
}

// #include <iostream>
// #include "BoostTcpClient.hpp"
// #include "Client.hpp"

// using namespace bbl::cli;

// int main(int argc, char *argv[])
// {
//     try {
//         ITcpClient *client = new BoostTcpClient("127.0.0.1", 8080);
//         Client cli(client);

//         cli.login("gabriel", "password");
//         auto cts = cli.getContacts();
//         for (auto &ct : cts)
//             std::cout << ct << std::endl;
//         cli.logout();
//     } catch (std::exception &err) {
//         std::cerr << err.what() << std::endl;
//     }
//     return 0;
// }
