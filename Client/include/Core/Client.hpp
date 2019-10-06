/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Client
*/

#pragma once

#include "ITcpClient.hpp"

namespace bbl::cli
{

    class Client
    {
        private:
            ITcpClient *_tcpConnection;
        public:
            Client(ITcpClient *tcpConnection);
            ~Client();
            Client(const Client &) = delete;
            Client &operator=(const Client &) = delete;
    };

}
