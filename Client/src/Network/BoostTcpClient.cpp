/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostTcpClient
*/

#include "BoostTcpClient.hpp"

using namespace bbl::cli;

BoostTcpClient::BoostTcpClient(const std::string &ipv4, unsigned short port) :
_socket(_io)
{
    _socket.connect(tcp::endpoint(address_v4::from_string(ipv4), port));
}

BoostTcpClient::~BoostTcpClient()
{

}

void BoostTcpClient::send(const std::string &data)
{
    _socket.write_some(buffer(data));
}

std::string BoostTcpClient::recv()
{
    streambuf buff;
    std::ostringstream ss;

    read_until(_socket, buff, "\0");
    ss << &buff;
    return ss.str();
}
