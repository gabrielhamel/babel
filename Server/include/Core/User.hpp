/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** User
*/

#pragma once

#include "INetworkClient.hpp"

namespace bbl::srv
{

    class User
    {
        private:
            INetworkClient *_client;
            bool _isLogged;
        public:
            User(INetworkClient *client);
            ~User();
            User(const User &) = delete;
            User &operator=(const User &) = delete;
            void signin();
            bool isLogged() const;
            INetworkClient *getNetworkPart() const;
    };

}
