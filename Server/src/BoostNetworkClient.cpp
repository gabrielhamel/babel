/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostNetworkClient
*/

#include <iostream>
#include <boost/bind.hpp>
#include <boost/algorithm/string.hpp>
#include "BoostNetworkClient.hpp"

using namespace bbl::srv;

BoostNetworkClient::BoostNetworkClient(basic_socket_acceptor<tcp> &ec) :
_socket(ec.get_executor()), _connected(false)
{

}

BoostNetworkClient::~BoostNetworkClient()
{

}

tcp::socket &BoostNetworkClient::getSocket()
{
    return _socket;
}

void BoostNetworkClient::bindRead()
{
    if (_connected == false) {
        std::cout << "New incomming connection: " << getId() << std::endl;
        _connected = true;
    }
    _dataReaded.fill(0);
    auto binding = boost::bind(&BoostNetworkClient::readHandler, shared_from_this(), placeholders::error, placeholders::bytes_transferred);
    _socket.async_read_some(buffer(_dataReaded, READ_SIZE), binding);
}

std::size_t BoostNetworkClient::getId() const
{
    const BoostNetworkClient *ptr = this;
    return reinterpret_cast<std::size_t>(ptr);
}

void BoostNetworkClient::readHandler(const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (error == error::eof) {
        std::cout << getId() << " disconnected" << std::endl;
        _socket.close();
        _connected = false;
        return;
    }
    std::string message(std::begin(_dataReaded), std::end(_dataReaded));
    boost::replace_all(message, "\n", "\\n");
    std::cout << getId() << " say: '" << message << "'" << std::endl;
    bindRead();
}

void BoostNetworkClient::send(const std::string &data) const
{

}

std::string BoostNetworkClient::recv() const
{
    return "";
}
