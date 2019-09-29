/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** INetworkServer
*/

#pragma once

#include <string>

namespace bbl::srv
{

    class INetworkServer
    {
        public:
            virtual ~INetworkServer() = default;
            virtual void run() = 0;
    };

}
