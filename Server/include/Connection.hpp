/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Connection
*/

#pragma once

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace boost::asio;
using namespace ip;

namespace bbl::srv
{

    class Connection : public boost::enable_shared_from_this<Connection>
    {
        private:
            tcp::socket _socket;
            bool _init;
            char _buffer[1024];
            void readHandler(const boost::system::error_code &error, std::size_t bytes_transferred);
            Connection(basic_socket_acceptor<tcp> &ec);
        public:
            ~Connection();
            static boost::shared_ptr<Connection> create(basic_socket_acceptor<tcp> &ec);
            void set();
            std::size_t getId() const;
            tcp::socket &getSocket();
    };

}
