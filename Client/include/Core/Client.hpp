/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Client
*/

#pragma once

#include <vector>
#include "ITcpClient.hpp"

namespace bbl::cli
{

    class Client
    {
        private:
            ITcpClient *_tcpConnection;
            bool _logged;
            std::string _username;
            std::pair<bool, std::string> readResponse();
            std::vector<std::string> split(std::string str, const std::string &delimiter) const;
        public:
            Client(ITcpClient *tcpConnection);
            ~Client();
            Client(const Client &) = delete;
            Client &operator=(const Client &) = delete;
            bool isLogged() const;
            void registration(const std::string &username, const std::string &password);
            void login(const std::string &username, const std::string &password);
            void logout();
            void requestInvitation(const std::string &contact);
            void acceptInvitation(const std::string &contact);
            std::vector<std::string> getInvitations();
            std::vector<std::string> getContacts();
    };

}
