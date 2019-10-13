/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include <iostream>
#include "../include/Graphic/MainWindow.hpp"

using namespace bbl::cli::graphics;

int main(int argc, char **argv)
{
    int res;

    try {
        QApplication application(argc, argv);
        MainWindow window;
        window.show();
        res = application.exec();
    } catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
        return 84;
    }
    return res;
}
