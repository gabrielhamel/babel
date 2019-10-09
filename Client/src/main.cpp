/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include "../include/Graphic/MainWindow.hpp"
#include "AudioManager.hpp"

using namespace bbl::cli::graphic;

// int main(int ac, char **av)
// {
//     AudioManager *audiomanager = new AudioManager();
//     float *data;

//     audiomanager->startRecord();
//     data = audiomanager->getDataSamples();
//     //sendData
//     //RecupData
//     audiomanager->setDataSamples(data);
//     audiomanager->playRecord();
//     return (0);
// }

// int main(int argc, char **argv)
// {
//     if (argc != 3)
//         return (84);
//     QApplication a(argc, argv);
//     MainWindow w(argv[1], atoi(argv[2]));

//     w.show();
//     return a.exec();
// }

// #include <iostream>
// #include "BoostTcpClient.hpp"
// #include "Client.hpp"

// using namespace bbl::cli;
// #include <QtWidgets/QApplication>
// #include "../include/Graphic/MainWindow.hpp"

// using namespace bbl::cli::graphic;

// int main(int argc, char *argv[])
// {
//     if (argc != 3)
//         return (84);
//     QApplication a(argc, argv);
//     MainWindow w(argv[1], atoi(argv[2]));

//     w.show();
//     return a.exec();
// }

#include <iostream>
#include "BoostUdpClient.hpp"
#include "Client.hpp"
#include "Packet.hpp"

using namespace bbl::cli;

int main(int argc, char *argv[])
{
    try {
        AudioManager *audiomanager = new AudioManager();
        auto client = new BoostUdpClient("127.0.0.1", atoi(argv[1]));
        if (std::string(argv[2]) == "write") {
            audiomanager->startRecord();
            float *data = audiomanager->getDataSamples();
            client->send(Packet((const unsigned char *)data, audiomanager->getSizeSamples()));
        }
        else if (std::string(argv[2]) == "read") {
            auto res = client->recv().getData();
            audiomanager->setDataSamples((float *)res.data());
            audiomanager->playRecord();
        }
    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
    }
    return 0;
}
