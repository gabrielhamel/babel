/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** SqlClient
*/

#pragma once

#include <string>
#include <vector>
#include <sqlite3.h>
#include "IStorage.hpp"

namespace bbl::srv
{

    class SqlClient : public IStorage
    {
        private:
            sqlite3 *_db;
            bool userExist(const std::string &username) const;
            void addContact(const std::string &owner, const std::string &contact) const;
        public:
            SqlClient(const std::string &database);
            ~SqlClient();
            SqlClient(const SqlClient &) = delete;
            SqlClient &operator=(const SqlClient &) = delete;
            void registerUser(const std::string &username, const std::string &password) const;
            void loginUser(const std::string &username, const std::string &password) const;
            std::vector<std::string> getContacts(const std::string &username) const;
            std::vector<std::string> getRequests(const std::string &username) const;
            void addRequest(const std::string &owner, const std::string &contact) const;
            void acceptRequest(const std::string &owner, const std::string &contact) const;
    };

}
