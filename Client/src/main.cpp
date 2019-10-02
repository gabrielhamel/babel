/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include <boost/asio.hpp>
#include <iostream>
#include <opus/opus.h>
#include <portaudio.h>
#include "RegisterForm.hpp"

using namespace bbl::cli::graphic::form;

int main(int ac, char **av)
{
	// Boost test
	boost::asio::io_service ios;
    boost::asio::ip::tcp::resolver resolver(ios);
    boost::asio::ip::tcp::resolver::query query("www.developpez.com", "80");
    boost::asio::ip::tcp::resolver::iterator iter = resolver.resolve(query);
    boost::asio::ip::tcp::resolver::iterator end;
	
	while (iter != end) {
		boost::asio::ip::tcp::endpoint endpoint = *iter++;
		std::cout << endpoint << std::endl;
	}

	// Opus test
	opus_strerror(0);

	// Portaudio test
	Pa_GetErrorText(0);
	QApplication app(ac, av);
	RegisterForm window;

    window.show();

	return app.exec();
}
