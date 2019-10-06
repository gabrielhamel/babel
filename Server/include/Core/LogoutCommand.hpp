/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** LogoutCommand
*/

#pragma once

#include <vector>
#include <iostream>
#include "IStorage.hpp"
#include "User.hpp"

namespace bbl::srv
{

    class LogoutCommand
    {
        public:
            static void run(std::vector<User *> _clients, User *current, IStorage *db, const std::vector<std::string> &av)
            {
                if (current->isLogged() == false) {
                    current->getNetworkPart()->send("KO User already logged out\n");
                    return;
                }
                current->signout();
                current->getNetworkPart()->send("OK User logged out\n");
            }
    };

}
