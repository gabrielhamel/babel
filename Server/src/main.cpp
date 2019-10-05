/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main
*/

#include <iostream>
#include "SqlClient.hpp"
#include <iostream>
#include "BoostNetworkServer.hpp"

using namespace bbl::srv;

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cerr << "Usage:\n\t" << av[0] << " <storage> <port>" << std::endl;
        return 84;
    }
    try {
        IStorage *database = new SqlClient(av[1]);
        NetworkManager service(database);
        std::unique_ptr<INetworkServer> server(new BoostNetworkServer(std::stoi(av[2]), service));
        server->run();
        delete database;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
