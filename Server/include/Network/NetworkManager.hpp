/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** NetworkManager
*/

#pragma once

#include <vector>
#include "INetworkClient.hpp"

namespace bbl::srv
{

    class NetworkManager
    {
        private:
            std::vector<INetworkClient *> _clients;
        public:
            NetworkManager();
            ~NetworkManager();
            void newClient(INetworkClient *client);
            void removeClient(INetworkClient *client);
            void recvData(INetworkClient *client, const std::string &data);
            NetworkManager(const NetworkManager &) = delete;
            NetworkManager &operator=(const NetworkManager &) = delete;
    };

}
