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

BoostUdpClient::BoostUdpClient(const std::string &ipv4, unsigned short port, bool is_receiver) :
_socket(_io), _ipv4(ipv4), _port(port), _is_receiver(is_receiver), _endpoint(nullptr)
{
    _socket.open(udp::v4());
    if (is_receiver) {
        _endpoint = new udp::endpoint(udp::v4(), 0);
        _socket.bind(*_endpoint);
        _port = _socket.local_endpoint().port();
        _ipv4 = _socket.local_endpoint().address().to_string();
    }
    else
        _endpoint = new udp::endpoint(address_v4::from_string(_ipv4), _port);
}

BoostUdpClient::~BoostUdpClient()
{
    _socket.close();
    delete _endpoint;
}

void BoostUdpClient::send(const Packet &packet)
{
    auto &data = packet.getData();
    std::size_t size = data.size() / 65506 + 1;
    for (size_t i = 0; i < size; i++) {
        bool next = (i == size - 1) ? false : true;
        std::vector<unsigned char> tmp = std::vector<unsigned char>(data.begin() + i * 65506, data.begin() + (i + 1) * 65506);
        tmp.insert(tmp.begin(), next);
        if (next)
            usleep(200);
        _socket.send_to(buffer(tmp), *_endpoint);
    }
}

Packet BoostUdpClient::recv()
{
    std::vector<unsigned char> res;
    bool next = false;
    do {
        _socket.wait(socket_base::wait_read);
        std::size_t size = _socket.available();
        std::vector<unsigned char> tmp(size);
        _socket.receive(buffer(tmp, size));
        res.insert(res.end(), tmp.begin() + 1, tmp.end());
        next = tmp[0];
    } while (next == true);
    Packet packet(res);
    return packet;
}

unsigned short BoostUdpClient::getPort() const
{
    return _port;
}

std::string BoostUdpClient::getAddress() const
{
    return _ipv4;
}
