/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Packet
*/

#pragma once

#include <vector>

namespace bbl::cli
{

    class Packet
    {
        private:
            std::vector<unsigned char> _data;
        public:
            Packet(const std::vector<unsigned char> &data);
            Packet(const unsigned char *data, std::size_t length);
            Packet(const Packet &copy);
            Packet &operator=(const Packet &copy);
            void append(const std::vector<unsigned char> &data);
            void append(const unsigned char *data, std::size_t length);
            const std::vector<unsigned char> &getData() const;
    };

}
