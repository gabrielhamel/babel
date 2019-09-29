/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** ClientService
*/

#pragma once

#include <vector>
#include "INetworkClient.hpp"

namespace bbl::srv
{

    class ClientService
    {
        private:
            std::vector<INetworkClient *> _clients;
        public:
            ClientService();
            ~ClientService();
            void newClient(INetworkClient *client);
            void removeClient(INetworkClient *client);
            void recvData(INetworkClient *client, const std::string &data);
            ClientService(const ClientService &) = delete;
            ClientService &operator=(const ClientService &) = delete;
    };

}
