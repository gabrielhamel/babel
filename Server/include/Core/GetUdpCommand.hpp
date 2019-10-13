/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** GetUdpCommand
*/

#pragma once

#include <vector>
#include <iostream>
#include "IStorage.hpp"
#include "User.hpp"

namespace bbl::srv
{

    class GetUdpCommand
    {
        public:
            static void run(std::vector<User *> _clients, User *current, IStorage *db, const std::vector<std::string> &av)
            {
                if (current->isLogged() == false) {
                    current->getNetworkPart()->send("KO You are not logged\n");
                    return;
                }
                try {
                    auto array = db->getUdpParameters(av[1], current->getUsername());
                    current->getNetworkPart()->send("OK " + array[0] + " " + array[1] + "\n");
                }
                catch (const std::exception &error) {
                    current->getNetworkPart()->send("KO " + std::string(error.what()) + "\n");
                    return;
                }
            }
    };

}
