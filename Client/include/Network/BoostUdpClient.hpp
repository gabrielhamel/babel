/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostTcpClient
*/

#pragma once

#include <boost/asio.hpp>
#include "ITcpClient.hpp"
#include "Packet.hpp"

using namespace boost::asio;
using namespace ip;

namespace bbl::cli {

    class BoostUdpClient
    {
        private:
            io_service _io;
            udp::socket _socket;
            std::string _ipv4;
            unsigned short _port;
        public:
            BoostUdpClient(const std::string &ipv4, unsigned short port);
            ~BoostUdpClient();
            BoostUdpClient(const BoostUdpClient &) = delete;
            BoostUdpClient &operator=(const BoostUdpClient &) = delete;
            void send(const Packet &packet);
            Packet recv();
    };

}
