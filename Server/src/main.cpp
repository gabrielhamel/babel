/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main
*/

#include <iostream>
#include "Server.hpp"

int main(int ac, char **av)
{
    try {
        bbl::srv::Server server(8080);
        server.run();
    } catch (std::exception &error) {
        std::cerr << error.what() << std::endl;
        return 84;
    }
    return 0;
}
