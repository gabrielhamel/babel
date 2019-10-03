/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** RegisterCommand
*/

#pragma once

#include <vector>
#include <iostream>
#include "IStorage.hpp"
#include "INetworkClient.hpp"

namespace bbl::srv
{

    class RegisterCommand
    {
        public:
            static void run(std::vector<INetworkClient *> _clients, INetworkClient *current, IStorage *db, const std::vector<std::string> &av)
            {
                try {
                    db->registerUser(av[1], av[2]);
                }
                catch (const std::exception &error) {
                    current->send("KO " + std::string(error.what()) + "\n");
                    return;
                }
                current->send("OK registration successful\n");
            }
    };

}
