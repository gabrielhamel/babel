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
    _socket = new BoostTcpClient(args[1].toStdString(), args[2].toUInt());
    _client = new Client(_socket);
    setWindowIcon(QIcon(":/images/favicon.png"));
    setFixedSize(QSize(420, 500));
    setStyleSheet("background-color: #444444");
    setWindowTitle("Babel");
    setCentralWidget(new SigninForm(this));
}

MainWindow::~MainWindow()
{
    if (_client)
        delete _client;
    if (_socket)
        delete _socket;
}

void MainWindow::goSignup()
{
    setCentralWidget(new SignupForm(this));
}

void MainWindow::goSignin()
{
    setCentralWidget(new SigninForm(this));
}

void MainWindow::goContacts()
{
    setCentralWidget(new Contacts(this));
}

void MainWindow::login(const QString &login, const QString &password)
{
    try {
        _client->login(login.toStdString(), password.toStdString());
        goContacts();
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
}

void MainWindow::signup(const QString &login, const QString &password)
{
    try {
        _client->registration(login.toStdString(), password.toStdString());
        goSignin();
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
}

bbl::cli::Client &MainWindow::getClient()
{
    return *_client;
}
