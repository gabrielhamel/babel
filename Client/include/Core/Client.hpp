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
            std::pair<bool, std::string> readResponse();
            bool _logged;
            std::string _username;
        public:
            Client(ITcpClient *tcpConnection);
            ~Client();
            Client(const Client &) = delete;
            Client &operator=(const Client &) = delete;
            bool isLogged() const;
            void registration(const std::string &username, const std::string &password);
            void login(const std::string &username, const std::string &password);
            void logout();
    };

}
