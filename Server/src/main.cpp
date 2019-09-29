/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main
*/

#include <iostream>
#include "BoostNetworkServer.hpp"

int main(int ac, char **av)
{
    try {
        std::unique_ptr<bbl::srv::INetworkServer> server(new bbl::srv::BoostNetworkServer(8080));
        server->run();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
