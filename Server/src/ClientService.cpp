/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** ClientService
*/

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "ClientService.hpp"

using namespace bbl::srv;

ClientService::ClientService()
{

}

ClientService::~ClientService()
{

}

void ClientService::newClient(INetworkClient *client)
{
    _clients.push_back(client);
    std::cout << client->getId() << " New incomming connection" << std::endl;
}

void ClientService::removeClient(INetworkClient *client)
{
    std::remove(_clients.begin(), _clients.end(), client);
    std::cout << client->getId() << " disconnected" << std::endl;
}

void ClientService::recvData(INetworkClient *client, const std::string &data)
{
    std::string copy = data;
    boost::replace_all(copy, "\n", "\\n");
    std::cout << client->getId() << " say: '" << copy << "'" << std::endl;
}
