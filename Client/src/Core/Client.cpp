/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Client
*/

#include <stdexcept>
#include <iostream>
#include "Client.hpp"

using namespace bbl::cli;

Client::Client(ITcpClient *tcpConnection) :
_tcpConnection(tcpConnection), _logged(false), _username("")
{

}

Client::~Client()
{

}

std::pair<bool, std::string> Client::readResponse()
{
    auto str = _tcpConnection->recv();
    std::pair<bool, std::string> result;

    if (str.length() < 2)
        throw std::runtime_error("Invalid response");
    result.second = str.substr(3, str.length() - 4);
    if (str.substr(0, 2) == "OK")
        result.first = true;
    else
        result.first = false;
    return result;
}

bool Client::isLogged() const
{
    return _logged;
}

void Client::registration(const std::string &username, const std::string &password)
{
    _tcpConnection->send("REGISTER " + username + " " + password + "\n");
    auto res = readResponse();
    if (res.first == false)
        throw std::runtime_error(res.second);
}

void Client::login(const std::string &username, const std::string &password)
{
    _tcpConnection->send("LOGIN " + username + " " + password + "\n");
    auto res = readResponse();
    if (res.first == false)
        throw std::runtime_error(res.second);
    _logged = true;
    _username = username;
}

void Client::logout()
{
    _tcpConnection->send("LOGOUT\n");
    auto res = readResponse();
    if (res.first == false)
        throw std::runtime_error(res.second);
    _logged = false;
    _username = "";
}
