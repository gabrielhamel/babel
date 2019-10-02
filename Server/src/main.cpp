/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main
*/

#include <iostream>
#include "SqlClient.hpp"
//#include <iostream>
// #include "BoostNetworkServer.hpp"

int main(int ac, char **av)
{
    // try {
    //     bbl::srv::NetworkManager service;
    //     std::unique_ptr<bbl::srv::INetworkServer> server(new bbl::srv::BoostNetworkServer(8080, service));
    //     server->run();
    // }
    // catch (const std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    //     return 84;
    // }
    try {
        bbl::srv::SqlClient client("storage.sql");
        //client.registerUser("Gabouchet", "de3be2f3");
        client.loginUser("Gabouchet", "de3be2f3");
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
