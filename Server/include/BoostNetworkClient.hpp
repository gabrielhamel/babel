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

#define READ_SIZE 4096

using namespace boost::asio;
using namespace ip;

namespace bbl::srv
{

    class BoostNetworkClient : public INetworkClient, public boost::enable_shared_from_this<BoostNetworkClient>
    {
        private:
            tcp::socket _socket;
            bool _connected;
            std::array<unsigned char, READ_SIZE> _dataReaded;
        public:
            BoostNetworkClient(basic_socket_acceptor<tcp> &ec);
            ~BoostNetworkClient();
            BoostNetworkClient(const BoostNetworkClient &) = delete;
            BoostNetworkClient &operator=(const BoostNetworkClient &) = delete;
            void send(const std::string &data) const;
            std::string recv() const;
            tcp::socket &getSocket();
            void bindRead();
            std::size_t getId() const;
            void readHandler(const boost::system::error_code &error, std::size_t bytes_transferred);
    };

}
