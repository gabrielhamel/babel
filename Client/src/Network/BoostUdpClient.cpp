/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** BoostUdpClient
*/

#include <iostream>
#include <string>
#include "BoostUdpClient.hpp"

using namespace bbl::cli;

BoostUdpClient::BoostUdpClient(const std::string &ipv4, unsigned short port) :
_socket(_io), _ipv4(ipv4), _port(port)
{
    _socket.open(udp::v4());
}

BoostUdpClient::~BoostUdpClient()
{
    _socket.close();
}

void BoostUdpClient::send(const Packet &packet)
{
    auto &data = packet.getData();
    std::size_t size = data.size() / 65506 + 1;
    for (size_t i = 0; i < size; i++) {
        bool next = (i == size - 1) ? false : true;
        std::vector<unsigned char> tmp = std::vector<unsigned char>(data.begin() + i * 65506, data.begin() + (i + 1) * 65506);
        tmp.insert(tmp.begin(), next);
        usleep(200);
        _socket.send_to(buffer(tmp), udp::endpoint(address_v4::from_string(_ipv4), _port));
    }
}

Packet BoostUdpClient::recv()
{
    udp::endpoint endpoint = udp::endpoint(udp::v4(), _port);
    std::vector<unsigned char> res;
    _socket.bind(endpoint);
    bool next = false;
    do {
        _socket.wait(socket_base::wait_read);
        std::size_t size = _socket.available();
        std::vector<unsigned char> tmp(size);
        _socket.receive_from(buffer(tmp, size), endpoint);
        res.insert(res.end(), tmp.begin() + 1, tmp.end());
        next = tmp[0];
    } while (next == true);
    _socket.close();
    _socket.open(udp::v4());
    Packet packet(res);
    return packet;
}
