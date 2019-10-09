/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Packet
*/

#include "Packet.hpp"

using namespace bbl::cli;

Packet::Packet(const std::vector<unsigned char> &data) :
_data(data)
{

}

Packet::Packet(const unsigned char *data, std::size_t length)
{
    _data = std::vector<unsigned char>(data, data + length);
}

Packet::Packet(const Packet &copy)
{
    _data = copy._data;
}

Packet &Packet::operator=(const Packet &copy)
{
    _data = copy._data;
    return *this;
}

void Packet::append(const std::vector<unsigned char> &data)
{
    _data.insert(_data.end(), data.begin(), data.end());
}

void Packet::append(const unsigned char *data, std::size_t length)
{
    auto tmp = std::vector<unsigned char>(data, data + length);
    _data.insert(_data.end(), tmp.begin(), tmp.end());
}

const std::vector<unsigned char> &Packet::getData() const
{
    return _data;
}
