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
            virtual std::vector<std::string> getContacts(const std::string &username) const = 0;
            virtual std::vector<std::string> getRequests(const std::string &username) const = 0;
            virtual void addRequest(const std::string &owner, const std::string &contact) const = 0;
            virtual void acceptRequest(const std::string &owner, const std::string &contact) const = 0;
    };

}
