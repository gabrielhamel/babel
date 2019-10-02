/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** IStorage
*/

#pragma once

#include <string>

namespace bbl::srv
{

    class IStorage
    {
        public:
            virtual ~IStorage() = default;
            virtual void registerUser(const std::string &username, const std::string &password) const = 0;
            virtual void loginUser(const std::string &username, const std::string &password) const = 0;
    };

}
