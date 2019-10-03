/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** NetworkManager
*/

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "CommandParser.hpp"
#include "NetworkManager.hpp"

using namespace bbl::srv;

NetworkManager::NetworkManager(IStorage *database) :
_database(database)
{

}

NetworkManager::~NetworkManager()
{

}

void NetworkManager::newClient(INetworkClient *client)
{
    _clients.push_back(new User(client));
    std::cout << client->getId() << " New incomming connection" << std::endl;
}

void NetworkManager::removeClient(INetworkClient *client)
{
    for (auto elem : _clients) {
        if (elem->getNetworkPart() == client) {
            auto ptr = elem;
            _clients.erase(std::find(_clients.begin(), _clients.end(), elem));
            delete ptr;
            break;
        }
    }
    std::cout << client->getId() << " disconnected" << std::endl;
}

void NetworkManager::recvData(INetworkClient *client, const std::string &data)
{
    std::string copy = data;
    boost::replace_all(copy, "\n", "\\n");
    std::cout << client->getId() << " say: '" << copy << "'" << std::endl;
    for (auto elem : _clients) {
        if (elem->getNetworkPart() == client) {
            CommandParser::parse(_clients, elem, _database, data);
            break;
        }
    }
}
