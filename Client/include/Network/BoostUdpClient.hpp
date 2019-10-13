/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostTcpClient
*/

#pragma once

#include <boost/asio.hpp>
#include "IUdpClient.hpp"

using namespace boost::asio;
using namespace ip;

namespace bbl::cli {

    class BoostUdpClient : public IUdpClient
    {
        private:
            io_service _io;
            udp::socket _socket;
            std::string _ipv4;
            unsigned short _port;
            bool _is_receiver;
            udp::endpoint *_endpoint;
        public:
            BoostUdpClient(const std::string &ipv4, unsigned short port, bool is_receiver);
            ~BoostUdpClient();
            BoostUdpClient(const BoostUdpClient &) = delete;
            BoostUdpClient &operator=(const BoostUdpClient &) = delete;
            void send(const Packet &packet);
            Packet recv();
            unsigned short getPort() const;
            std::string getAddress() const;
            void close();
    };

}
