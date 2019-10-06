/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** ITcpClient
*/

#pragma once

#include <string>

namespace bbl::cli
{

    class ITcpClient
    {
        public:
            virtual ~ITcpClient() = default;
            virtual void send(const std::string &data) = 0;
            virtual std::string recv() = 0;
    };

}
