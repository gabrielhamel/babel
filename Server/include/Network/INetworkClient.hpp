/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** INetworkClient
*/

#pragma once

#include <string>

namespace bbl::srv
{

    class INetworkClient
    {
        public:
            virtual ~INetworkClient() = default;
            virtual void send(const std::string &data) = 0;
            virtual std::size_t getId() const = 0;
    };

}
