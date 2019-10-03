/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** NetworkManager
*/

#pragma once

#include <string>
#include <vector>
#include "User.hpp"
#include "CommandParser.hpp"

namespace bbl::srv
{

    class NetworkManager
    {
        private:
            IStorage *_database;
            std::vector<User *> _clients;
        public:
            NetworkManager(IStorage *database);
            ~NetworkManager();
            void newClient(INetworkClient *client);
            void removeClient(INetworkClient *client);
            void recvData(INetworkClient *client, const std::string &data);
            NetworkManager(const NetworkManager &) = delete;
            NetworkManager &operator=(const NetworkManager &) = delete;
    };

}
