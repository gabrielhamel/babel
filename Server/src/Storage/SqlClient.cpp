/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** SqlClient
*/

#include <stdexcept>
#include "SqlClient.hpp"

using namespace bbl::srv;

SqlClient::SqlClient(const std::string &database) :
_db(nullptr)
{
    int rc = sqlite3_open(database.c_str(), &_db);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    sqlite3_stmt *res = nullptr;
    rc = sqlite3_prepare(_db, "CREATE TABLE IF NOT EXISTS Users (username varchar(32) NOT NULL, password varchar(32) NOT NULL, PRIMARY KEY (username));", -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
}

SqlClient::~SqlClient()
{
    sqlite3_close(_db);
}

void SqlClient::registerUser(const std::string &username, const std::string &password) const
{
    std::string query = "INSERT INTO Users VALUES (@username, @password)";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@username");
    sqlite3_bind_text(res, idx, username.c_str(), username.length() + 1, nullptr);
    idx = sqlite3_bind_parameter_index(res, "@password");
    sqlite3_bind_text(res, idx, password.c_str(), password.length() + 1, nullptr);
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    if (rc != SQLITE_DONE)
        throw std::runtime_error(sqlite3_errstr(rc));
}

void SqlClient::loginUser(const std::string &username, const std::string &password) const
{
    std::string query = "SELECT * FROM Users WHERE username = @username AND password = @password";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@username");
    sqlite3_bind_text(res, idx, username.c_str(), username.length() + 1, nullptr);
    idx = sqlite3_bind_parameter_index(res, "@password");
    sqlite3_bind_text(res, idx, password.c_str(), password.length() + 1, nullptr);
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    if (rc == SQLITE_DONE)
        throw std::runtime_error("Username or password invalid");
    else if (rc != SQLITE_ROW)
        throw std::runtime_error(sqlite3_errstr(rc));
}
