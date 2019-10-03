/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** User
*/

#include "User.hpp"

using namespace bbl::srv;

User::User(INetworkClient *client) :
_isLogged(false), _client(client)
{

}

User::~User()
{

}

void User::signin()
{
    _isLogged = true;
}

bool User::isLogged() const
{
    return _isLogged;
}

INetworkClient *User::getNetworkPart() const
{
    return _client;
}
