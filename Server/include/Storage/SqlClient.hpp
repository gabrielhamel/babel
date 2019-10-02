/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** SqlClient
*/

#pragma once

#include <string>
#include <sqlite3.h>
#include "IStorage.hpp"

namespace bbl::srv
{

    class SqlClient : public IStorage
    {
        private:
            sqlite3 *_db;
        public:
            SqlClient(const std::string &database);
            ~SqlClient();
            SqlClient(const SqlClient &) = delete;
            SqlClient &operator=(const SqlClient &) = delete;
            void registerUser(const std::string &username, const std::string &password) const;
            void loginUser(const std::string &username, const std::string &password) const;
    };

}
