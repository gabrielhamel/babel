/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostNetworkServer
*/

#include <memory>
#include <boost/bind.hpp>
#include "BoostNetworkServer.hpp"

using namespace bbl::srv;

BoostNetworkServer::BoostNetworkServer(unsigned short port, ClientService &service) :
_socket(_io), _acceptor(_io, tcp::endpoint(tcp::v6(), port)), _clientService(service)
{
    bindAcceptor();
}

BoostNetworkServer::~BoostNetworkServer()
{

}

void BoostNetworkServer::run()
{
    _io.run();
}

void BoostNetworkServer::bindAcceptor()
{
    boost::shared_ptr<BoostNetworkClient> connection(new BoostNetworkClient(_acceptor, _clientService));
    auto binding = boost::bind(&BoostNetworkServer::acceptHandler, this, connection, placeholders::error);
    _acceptor.async_accept(connection->getSocket(), binding);
}

void BoostNetworkServer::acceptHandler(boost::shared_ptr<BoostNetworkClient> connection, const boost::system::error_code &error)
{
    if (!error) {
        connection->bindRead();
        _clientService.newClient(connection.get());
    }
    else
        delete connection.get();
    bindAcceptor();
}
