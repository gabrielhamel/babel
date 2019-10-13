/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** IUdpClient
*/

#pragma once

#include <string>
#include "Packet.hpp"

namespace bbl::cli
{

    class IUdpClient
    {
        public:
            virtual ~IUdpClient() = default;
            virtual void send(const Packet &packet) = 0;
            virtual Packet recv() = 0;
            virtual unsigned short getPort() const = 0;
    };

}
