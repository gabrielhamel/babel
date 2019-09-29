/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostNetworkClient
*/

#pragma once

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "INetworkClient.hpp"
#include "NetworkManager.hpp"

using namespace boost::asio;
using namespace ip;

namespace bbl::srv
{

    class BoostNetworkClient : public INetworkClient, public boost::enable_shared_from_this<BoostNetworkClient>
    {
        private:
            tcp::socket _socket;
            bool _connected;
            streambuf _buffer;
            NetworkManager &_NetworkManager;
        public:
            BoostNetworkClient(basic_socket_acceptor<tcp> &ec, NetworkManager &service);
            ~BoostNetworkClient();
            BoostNetworkClient(const BoostNetworkClient &) = delete;
            BoostNetworkClient &operator=(const BoostNetworkClient &) = delete;
            void send(const std::string &data);
            tcp::socket &getSocket();
            void bindRead();
            std::size_t getId() const;
            void disconnect(const std::string &message);
            void readHandler(const boost::system::error_code &error, std::size_t bytes_transferred);
            void writeHandler(const boost::system::error_code &error, std::size_t bytes_transferred);
    };

}
