/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostTcpClient
*/

#pragma once

#include <boost/asio.hpp>
#include "ITcpClient.hpp"

using namespace boost::asio;
using namespace ip;

namespace bbl::cli {

    class BoostTcpClient : public ITcpClient
    {
        private:
            io_service _io;
            tcp::socket _socket;
        public:
            BoostTcpClient(const std::string &ipv4, unsigned short port);
            ~BoostTcpClient();
            BoostTcpClient(const BoostTcpClient &) = delete;
            BoostTcpClient &operator=(const BoostTcpClient &) = delete;
            void send(const std::string &data);
            std::string recv();
    };

}
