/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostNetworkServer
*/

#pragma once

#include <boost/asio.hpp>
#include "INetworkServer.hpp"
#include "NetworkManager.hpp"
#include "BoostNetworkClient.hpp"
#include "NetworkManager.hpp"

using namespace boost::asio;
using namespace ip;

namespace bbl::srv
{

    class BoostNetworkServer : public INetworkServer
    {
        private:
            io_service _io;
            tcp::socket _socket;
            tcp::acceptor _acceptor;
            NetworkManager &_NetworkManager;
            void bindAcceptor();
            void acceptHandler(boost::shared_ptr<BoostNetworkClient> connection, const boost::system::error_code &error);
        public:
            BoostNetworkServer(unsigned short port, NetworkManager &service);
            ~BoostNetworkServer();
            BoostNetworkServer(const BoostNetworkServer &) = delete;
            BoostNetworkServer &operator=(const BoostNetworkServer &) = delete;
            void run();
    };

}
