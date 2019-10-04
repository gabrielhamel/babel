/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** main
*/

#include <QApplication>
#include "../include/MainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
