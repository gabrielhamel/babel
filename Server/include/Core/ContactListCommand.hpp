/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** ContactListCommand
*/

#pragma once

#include <vector>
#include <iostream>
#include "IStorage.hpp"
#include "User.hpp"

namespace bbl::srv
{

    class ContactListCommand
    {
        public:
            static void run(std::vector<User *> _clients, User *current, IStorage *db, const std::vector<std::string> &av)
            {
                std::string response = "OK";

                if (current->isLogged() == false) {
                    current->getNetworkPart()->send("KO You are not logged\n");
                    return;
                }
                try {
                    auto rqs = db->getContacts(current->getUsername());
                    for (auto rq : rqs)
                        response.append(" " + rq);
                }
                catch (const std::exception &error) {
                    current->getNetworkPart()->send("KO " + std::string(error.what()) + "\n");
                    return;
                }
                current->getNetworkPart()->send(response + "\n");
            }
    };

}
