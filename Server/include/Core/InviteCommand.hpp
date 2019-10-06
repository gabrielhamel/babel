/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** InviteCommand
*/

#pragma once

#include <vector>
#include <iostream>
#include "IStorage.hpp"
#include "User.hpp"

namespace bbl::srv
{

    class InviteCommand
    {
        public:
            static void run(std::vector<User *> _clients, User *current, IStorage *db, const std::vector<std::string> &av)
            {
                if (current->isLogged() == false) {
                    current->getNetworkPart()->send("KO You are not logged\n");
                    return;
                }
                try {
                    db->addRequest(current->getUsername(), av[1]);
                }
                catch (const std::exception &error) {
                    current->getNetworkPart()->send("KO " + std::string(error.what()) + "\n");
                    return;
                }
                current->getNetworkPart()->send("OK Request done\n");
            }
    };

}
