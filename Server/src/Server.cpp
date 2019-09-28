/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Server
*/

#include <iostream>
#include <boost/bind.hpp>
#include "Server.hpp"

using namespace bbl::srv;

Server::Server(unsigned short port) :
_socket(_io), _acceptor(_io, tcp::endpoint(tcp::v6(), port))
{
    prepareNewConnection();
}

void Server::prepareNewConnection()
{
    boost::shared_ptr<Connection> connection = Connection::create(_acceptor);
    _connections.insert(connection);
    auto binding = boost::bind(&Server::acceptHandler, this, connection, placeholders::error);
    _acceptor.async_accept(connection->getSocket(), binding);
}

void Server::acceptHandler(boost::shared_ptr<Connection> connection, const boost::system::error_code &error)
{
    if (!error)
        connection->set();
    else {
        std::cout << "Connection error: " << error.message() << std::endl;
        _connections.erase(connection);
    }
    prepareNewConnection();
}

void Server::run()
{
    _io.run();
}
