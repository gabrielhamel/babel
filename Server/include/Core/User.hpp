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
            std::string _username;
        public:
            User(INetworkClient *client);
            ~User();
            User(const User &) = delete;
            User &operator=(const User &) = delete;
            bool isLogged() const;
            void signin(const std::string &username);
            void signout();
            INetworkClient *getNetworkPart() const;
    };

}
