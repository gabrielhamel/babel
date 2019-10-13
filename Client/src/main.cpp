/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include <iostream>
#include "../include/Graphic/MainWindow.hpp"

using namespace bbl::cli::graphics;

int main(int argc, char **argv)
{
    int res;

    try {
        QApplication application(argc, argv);
        MainWindow window;
        window.show();
        res = application.exec();
    } catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
        return 84;
    }
    return res;
}

// #include <iostream>
// #include "BoostUdpClient.hpp"
// #include "Client.hpp"
// #include "Packet.hpp"
// #include "AudioManager.hpp"

// using namespace bbl::cli;

// int main(int argc, char *argv[])
// {
//     try {
//         AudioManager *audiomanager = new AudioManager();
//         auto client = new BoostUdpClient("127.0.0.1", atoi(argv[1]));
//         if (std::string(argv[2]) == "write") {
//             while (1) {
//                 audiomanager->startRecord();
//                 float *data = audiomanager->getDataSamples();
//                 client->send(Packet((const unsigned char *)data, audiomanager->getSizeSamples()));
//             }
//         }
//         else if (std::string(argv[2]) == "read") {
//             while (1) {
//                 auto res = client->recv().getData();
//                 audiomanager->setDataSamples((float *)res.data());
//                 audiomanager->playRecord();
//             }
//         }
//     } catch (std::exception &err) {
//         std::cerr << err.what() << std::endl;
//     }
//     return 0;
// }
