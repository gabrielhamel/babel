/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** main
*/

#include <QtWidgets/QApplication>
#include "../include/MainWindow.hpp"

using namespace bbl::cli::graphic;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
