/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** CommandParser
*/

#pragma once

#include <memory>
#include <vector>
#include <list>
#include "IStorage.hpp"
#include "User.hpp"
#include "INetworkClient.hpp"

namespace bbl::srv
{

    class CommandParser
    {
        private:
            static std::vector<std::string> split(std::string str, const std::string &delimiter);
        public:
            static void parse(std::vector<User *> _clients, User *current, IStorage *db, const std::string &text);
    };

}
