/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Connection
*/

#include <boost/bind.hpp>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "Connection.hpp"

using namespace bbl::srv;

Connection::Connection(basic_socket_acceptor<tcp> &ec) :
_socket(ec.get_executor()), _init(false)
{

}

Connection::~Connection()
{
    std::cout << getId() << " disconnected" << std::endl;
}

void Connection::set()
{
    if (!_init) {
        std::cout << "New incomming connection: " << getId() << std::endl;
        _init = true;
    }
    memset(_buffer, 0, 1024);
    auto binding = boost::bind(&Connection::readHandler, shared_from_this(), placeholders::error, placeholders::bytes_transferred);
    _socket.async_read_some(buffer(_buffer, 1024), binding);
}

void Connection::readHandler(const boost::system::error_code &error, std::size_t bytes_transferred)
{
    std::string message(_buffer);
    boost::replace_all(message, "\n", "\\n");
    std::cout << getId() << " say: '" << message << "'" << std::endl;
    set();
}

boost::shared_ptr<Connection> Connection::create(basic_socket_acceptor<tcp> &ec)
{
    return boost::shared_ptr<Connection>(new Connection(ec));
}

tcp::socket &Connection::getSocket()
{
    return _socket;
}

std::size_t Connection::getId() const
{
    const Connection *ptr = this;
    return reinterpret_cast<std::size_t>(ptr);
}
