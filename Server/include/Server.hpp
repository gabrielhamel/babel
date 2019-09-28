/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** example
*/

#pragma once

#include <boost/asio.hpp>
#include <set>
#include "Connection.hpp"

using namespace boost::asio;
using namespace ip;

namespace bbl::srv
{

    class Server
    {
        private:
            io_service _io;
            tcp::socket _socket;
            tcp::acceptor _acceptor;
            std::set<boost::shared_ptr<Connection>> _connections;
            void prepareNewConnection();
            void acceptHandler(boost::shared_ptr<Connection> connection, const boost::system::error_code &error);
            void readHandler(const boost::system::error_code &error, std::size_t bytes_transferred);
        public:
            Server(unsigned short port);
            void run();
    };

}
