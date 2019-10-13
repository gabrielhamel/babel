/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** SqlClient
*/

#include <stdexcept>
#include <algorithm>
#include "SqlClient.hpp"

using namespace bbl::srv;

SqlClient::SqlClient(const std::string &database) :
_db(nullptr)
{
    int rc = sqlite3_open(database.c_str(), &_db);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    sqlite3_stmt *res = nullptr;
    rc = sqlite3_prepare(_db,
    "CREATE TABLE IF NOT EXISTS Users (username varchar(32) NOT NULL, password varchar(32) NOT NULL, PRIMARY KEY (username));"
    , -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    res = nullptr;
    rc = sqlite3_prepare(_db,
    "CREATE TABLE IF NOT EXISTS Contacts (owner VARCHAR(32) NOT NULL, contact VARCHAR(32) NOT NULL);"
    , -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    res = nullptr;
    rc = sqlite3_prepare(_db,
    "CREATE TABLE IF NOT EXISTS Invitations (owner VARCHAR(32) NOT NULL, contact VARCHAR(32) NOT NULL);"
    , -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    res = nullptr;
    rc = sqlite3_prepare(_db,
    "CREATE TABLE IF NOT EXISTS UdpSettings (owner VARCHAR(32) NOT NULL, ipv4 VARCHAR(32) NOT NULL, port VARCHAR(32) NOT NULL);"
    , -1, &res, nullptr);
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

bool SqlClient::userExist(const std::string &username) const
{
    std::string query = "SELECT * FROM Users WHERE username = @username";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@username");
    sqlite3_bind_text(res, idx, username.c_str(), username.length() + 1, nullptr);
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    if (rc == SQLITE_DONE)
        return false;
    else if (rc == SQLITE_ROW)
        return true;
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

std::vector<std::string> SqlClient::getContacts(const std::string &username) const
{
    if (userExist(username) == false)
        throw std::runtime_error("Invalid username");
    std::vector<std::string> tab_contacts;
    std::string query = "SELECT contact FROM Contacts WHERE owner = @username";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@username");
    sqlite3_bind_text(res, idx, username.c_str(), username.length() + 1, nullptr);
    rc = sqlite3_step(res);
    if (rc == SQLITE_DONE)
        return tab_contacts;
    else if (rc != SQLITE_ROW)
        throw std::runtime_error(sqlite3_errstr(rc));
    do {
        tab_contacts.push_back((const char *)sqlite3_column_text(res, 0));
    } while (sqlite3_step(res) == SQLITE_ROW);
    sqlite3_finalize(res);
    return tab_contacts;
}

std::vector<std::string> SqlClient::getRequests(const std::string &username) const
{
    if (userExist(username) == false)
        throw std::runtime_error("Invalid username");
    std::vector<std::string> tab_contacts;
    std::string query = "SELECT owner FROM Invitations WHERE contact = @username";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@username");
    sqlite3_bind_text(res, idx, username.c_str(), username.length() + 1, nullptr);
    rc = sqlite3_step(res);
    if (rc == SQLITE_DONE)
        return tab_contacts;
    else if (rc != SQLITE_ROW)
        throw std::runtime_error(sqlite3_errstr(rc));
    do {
        tab_contacts.push_back((const char *)sqlite3_column_text(res, 0));
    } while (sqlite3_step(res) == SQLITE_ROW);
    sqlite3_finalize(res);
    return tab_contacts;
}

void SqlClient::addContact(const std::string &owner, const std::string &contact) const
{
    if (owner == contact)
        throw std::runtime_error("You cannot be your friend =)");
    if (userExist(owner) == false)
        throw std::runtime_error("Invalid username");
    if (userExist(contact) == false)
        throw std::runtime_error("Contact not exist");
    auto contacts = getContacts(owner);
    if (std::find(contacts.begin(), contacts.end(), contact) != contacts.end())
        throw std::runtime_error(contact + " is already your friend");
    std::string query = "INSERT INTO Contacts VALUES (@owner, @contact)";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@owner");
    sqlite3_bind_text(res, idx, owner.c_str(), owner.length() + 1, nullptr);
    idx = sqlite3_bind_parameter_index(res, "@contact");
    sqlite3_bind_text(res, idx, contact.c_str(), contact.length() + 1, nullptr);
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    if (rc != SQLITE_DONE)
        throw std::runtime_error(sqlite3_errstr(rc));
}

void SqlClient::addRequest(const std::string &owner, const std::string &contact) const
{
    if (owner == contact)
        throw std::runtime_error("You cannot be your friend =)");
    if (userExist(owner) == false)
        throw std::runtime_error("Invalid username");
    if (userExist(contact) == false)
        throw std::runtime_error("Contact not exist");
    auto contacts = getContacts(contact);
    if (std::find(contacts.begin(), contacts.end(), owner) != contacts.end())
        throw std::runtime_error(contact + " is already your friend");
    auto requests = getRequests(contact);
    if (std::find(requests.begin(), requests.end(), owner) != requests.end())
        throw std::runtime_error(contact + " is already requested");
    std::string query = "INSERT INTO Invitations VALUES (@owner, @contact)";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@owner");
    sqlite3_bind_text(res, idx, owner.c_str(), owner.length() + 1, nullptr);
    idx = sqlite3_bind_parameter_index(res, "@contact");
    sqlite3_bind_text(res, idx, contact.c_str(), contact.length() + 1, nullptr);
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    if (rc != SQLITE_DONE)
        throw std::runtime_error(sqlite3_errstr(rc));
}

void SqlClient::acceptRequest(const std::string &owner, const std::string &contact) const
{
    if (owner == contact)
        throw std::runtime_error("You cannot be your friend =)");
    if (userExist(owner) == false)
        throw std::runtime_error("Invalid username");
    if (userExist(contact) == false)
        throw std::runtime_error("Contact not exist");
    auto requests = getRequests(owner);
    if (std::find(requests.begin(), requests.end(), contact) == requests.end())
        throw std::runtime_error(contact + " is not requested");
    std::string query = "DELETE FROM Invitations WHERE owner = @owner AND contact = @contact";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@contact");
    sqlite3_bind_text(res, idx, owner.c_str(), owner.length() + 1, nullptr);
    idx = sqlite3_bind_parameter_index(res, "@owner");
    sqlite3_bind_text(res, idx, contact.c_str(), contact.length() + 1, nullptr);
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    if (rc != SQLITE_DONE)
        throw std::runtime_error(sqlite3_errstr(rc));
    query = "DELETE FROM Invitations WHERE owner = @contact AND contact = @owner";
    res = nullptr;
    rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    idx = sqlite3_bind_parameter_index(res, "@contact");
    sqlite3_bind_text(res, idx, owner.c_str(), owner.length() + 1, nullptr);
    idx = sqlite3_bind_parameter_index(res, "@owner");
    sqlite3_bind_text(res, idx, contact.c_str(), contact.length() + 1, nullptr);
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    if (rc != SQLITE_DONE)
        throw std::runtime_error(sqlite3_errstr(rc));
    addContact(owner, contact);
    addContact(contact, owner);
}

void SqlClient::setUdpParameters(const std::string &owner, const std::string &ipv4, const std::string &port) const
{
    if (userExist(owner) == false)
        throw std::runtime_error("Invalid username");
    std::string query = "DELETE FROM UdpSettings WHERE owner = @owner";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@owner");
    sqlite3_bind_text(res, idx, owner.c_str(), owner.length() + 1, nullptr);
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    if (rc != SQLITE_DONE)
        throw std::runtime_error(sqlite3_errstr(rc));
    query = "INSERT INTO UdpSettings VALUES (@owner, @ipv4, @port)";
    res = nullptr;
    rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    idx = sqlite3_bind_parameter_index(res, "@owner");
    sqlite3_bind_text(res, idx, owner.c_str(), owner.length() + 1, nullptr);
    idx = sqlite3_bind_parameter_index(res, "@ipv4");
    sqlite3_bind_text(res, idx, ipv4.c_str(), ipv4.length() + 1, nullptr);
    idx = sqlite3_bind_parameter_index(res, "@port");
    sqlite3_bind_text(res, idx, port.c_str(), port.length() + 1, nullptr);
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
    if (rc != SQLITE_DONE)
        throw std::runtime_error(sqlite3_errstr(rc));
}

std::array<std::string, 2> SqlClient::getUdpParameters(const std::string &owner, const std::string &me) const
{
    if (userExist(owner) == false)
        throw std::runtime_error("Invalid username");
    auto contacts = getContacts(me);
    if (std::find(contacts.begin(), contacts.end(), owner) == contacts.end())
        throw std::runtime_error(owner + " is not your friend");
    std::array<std::string, 2> tab_contacts;
    std::string query = "SELECT ipv4, port FROM UdpSettings WHERE owner = @owner";
    sqlite3_stmt *res = nullptr;
    int rc = sqlite3_prepare_v2(_db, query.c_str(), -1, &res, nullptr);
    if (rc != SQLITE_OK)
        throw std::runtime_error(sqlite3_errstr(rc));
    int idx = sqlite3_bind_parameter_index(res, "@owner");
    sqlite3_bind_text(res, idx, owner.c_str(), owner.length() + 1, nullptr);
    rc = sqlite3_step(res);
    if (rc == SQLITE_DONE)
        throw std::runtime_error("This user doesn't have udp settings");
    else if (rc != SQLITE_ROW)
        throw std::runtime_error(sqlite3_errstr(rc));
    tab_contacts[0] = (const char *)sqlite3_column_text(res, 0);
    tab_contacts[1] = (const char *)sqlite3_column_text(res, 1);
    sqlite3_finalize(res);
    return tab_contacts;
}
