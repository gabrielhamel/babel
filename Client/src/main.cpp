/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <boost/asio.hpp>
#include <iostream>
#include <opus/opus.h>
#include <portaudio.h>

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

	// Qt test
	QApplication app(ac, av);
	QPushButton button("Hello world !");
	button.show();
	return app.exec();
}
