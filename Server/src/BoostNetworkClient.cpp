/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostNetworkClient
*/

#include <boost/bind.hpp>
#include "BoostNetworkClient.hpp"

using namespace bbl::srv;

BoostNetworkClient::BoostNetworkClient(basic_socket_acceptor<tcp> &ec, NetworkManager &service) :
_socket(ec.get_executor()), _connected(false), _NetworkManager(service)
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
    if (_connected == false)
        _connected = true;
    auto binding = boost::bind(&BoostNetworkClient::readHandler, shared_from_this(), placeholders::error, placeholders::bytes_transferred);
    async_read_until(_socket, _buffer, "\0", binding);
}

std::size_t BoostNetworkClient::getId() const
{
    const BoostNetworkClient *ptr = this;
    return reinterpret_cast<std::size_t>(ptr);
}

void BoostNetworkClient::readHandler(const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (error) {
        disconnect(error.message());
        return;
    }
    std::ostringstream ss;
    ss << &_buffer;
    std::string message = ss.str();
    _NetworkManager.recvData(this, message);
    bindRead();
}

void BoostNetworkClient::writeHandler(const boost::system::error_code &error, std::size_t bytes_transferred)
{
    if (error)
        disconnect(error.message());
}

void BoostNetworkClient::send(const std::string &data)
{
    auto binding = boost::bind(&BoostNetworkClient::writeHandler, shared_from_this(), placeholders::error, placeholders::bytes_transferred);
    _socket.async_write_some(buffer(data, data.length()), binding);
}

void BoostNetworkClient::disconnect(const std::string &message)
{
    _NetworkManager.removeClient(this);
    _socket.close();
    _connected = false;
}
