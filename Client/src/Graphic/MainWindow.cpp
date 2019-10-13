/*
** EPITECH PROJECT, 2019
** BabelFront
** File description:
** MainWindow
*/

#include <iostream>
#include <QtCore/QCoreApplication>
#include "BoostTcpClient.hpp"
#include "../../include/Graphic/MainWindow.hpp"

using namespace bbl::cli::graphics;

MainWindow::MainWindow() :
QMainWindow(nullptr), _client(nullptr)
{
    auto args = QCoreApplication::arguments();
    if (args.count() < 3)
        throw std::runtime_error("Invalid usage (eg. ./client <ipv4> <port>");
    _client = new BoostTcpClient(args[1].toStdString(), args[2].toUInt());

    this->setWindowIcon(QIcon(":/images/favicon.png"));
    this->setFixedSize(QSize(420, 500));
    this->setStyleSheet("background-color: #444444");
    this->setWindowTitle("Babel");
    this->setCentralWidget(new SigninForm(this));
}

MainWindow::~MainWindow()
{
    if (_client)
        delete _client;
}

void MainWindow::goSignup()
{
    this->setCentralWidget(new SignupForm(this));
}

void MainWindow::goSignin()
{
    this->setCentralWidget(new SigninForm(this));
}

void MainWindow::login(const QString &login, const QString &password)
{
    std::cout << login.toStdString() << " " << password.toStdString() << std::endl;
}
