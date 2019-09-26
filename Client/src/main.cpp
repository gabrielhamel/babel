/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main
*/

#include <boost/asio.hpp>
#include <iostream>

int main(int ac, char **av)
{
	boost::asio::io_service ios;
	boost::asio::ip::tcp::resolver resolver(ios);
	boost::asio::ip::tcp::resolver::query query("www.developpez.com", "80");
	boost::asio::ip::tcp::resolver::iterator iter = resolver.resolve(query);
	boost::asio::ip::tcp::resolver::iterator end;

	while (iter != end) {
		boost::asio::ip::tcp::endpoint endpoint = *iter++;
		std::cout << endpoint << std::endl;
	}
    return 0;
}
