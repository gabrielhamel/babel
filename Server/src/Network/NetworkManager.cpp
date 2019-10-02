/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** NetworkManager
*/

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "NetworkManager.hpp"

using namespace bbl::srv;

NetworkManager::NetworkManager()
{

}

NetworkManager::~NetworkManager()
{

}

void NetworkManager::newClient(INetworkClient *client)
{
    _clients.push_back(client);
    std::cout << client->getId() << " New incomming connection" << std::endl;
}

void NetworkManager::removeClient(INetworkClient *client)
{
    std::remove(_clients.begin(), _clients.end(), client);
    std::cout << client->getId() << " disconnected" << std::endl;
}

void NetworkManager::recvData(INetworkClient *client, const std::string &data)
{
    std::string copy = data;
    boost::replace_all(copy, "\n", "\\n");
    std::cout << client->getId() << " say: '" << copy << "'" << std::endl;
}
