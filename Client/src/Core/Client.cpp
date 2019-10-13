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

std::vector<std::string> Client::split(std::string str, const std::string &delimiter) const
{
    std::size_t pos = 0;
    std::string token;
    std::vector<std::string> list;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        if (token != "")
            list.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    if (str != "")
        list.push_back(str);
    return list;
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

void Client::requestInvitation(const std::string &contact)
{
    _tcpConnection->send("INVITE_CONTACT " + contact + "\n");
    auto res = readResponse();
    if (res.first == false)
        throw std::runtime_error(res.second);
}

void Client::acceptInvitation(const std::string &contact)
{
    _tcpConnection->send("ACCEPT_INVITE " + contact + "\n");
    auto res = readResponse();
    if (res.first == false)
        throw std::runtime_error(res.second);
}

std::vector<std::string> Client::getInvitations()
{
    _tcpConnection->send("GET_INVITE\n");
    auto res = readResponse();
    if (res.first == false)
        throw std::runtime_error(res.second);
    return split(res.second, " ");
}

std::vector<std::string> Client::getContacts()
{
    _tcpConnection->send("CONTACT_LIST\n");
    auto res = readResponse();
    if (res.first == false)
        throw std::runtime_error(res.second);
    return split(res.second, " ");
}

void Client::setUdpSetting(const std::string &ipv4, unsigned short port)
{
    _tcpConnection->send("SET_UDP " + ipv4 + " " + std::to_string(port) + "\n");
    auto res = readResponse();
    if (res.first == false)
        throw std::runtime_error(res.second);
}

std::pair<std::string, unsigned short> Client::getUdpSettings(const std::string &contact)
{
    _tcpConnection->send("GET_UDP " + contact + "\n");
    auto res = readResponse();
    if (res.first == false)
        throw std::runtime_error(res.second);
    auto str = split(res.second, " ");
    auto result = std::pair<std::string, unsigned short>(str[0], std::stoi(str[1]));
    return result;
}
