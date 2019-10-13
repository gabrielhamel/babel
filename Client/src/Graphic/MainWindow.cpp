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
QMainWindow(nullptr), _client(nullptr), _ctForm(nullptr)
{
    auto args = QCoreApplication::arguments();
    if (args.count() < 4)
        throw std::runtime_error("Invalid usage (eg. ./client <remote server ipv4> <remote server port> <your ipv4>");
    _socket = new BoostTcpClient(args[1].toStdString(), args[2].toUInt());
    _client = new Client(_socket);
    setWindowIcon(QIcon(":/images/favicon.png"));
    setFixedSize(QSize(420, 500));
    setStyleSheet("background-color: #444444");
    setWindowTitle("Babel");
    //setCentralWidget(new SigninForm(this));

    // Pour moi
    _client->login("gabriel", "de3be2f3");
    _ctForm = new Contacts(this, args[3].toStdString());
    setCentralWidget(_ctForm);
}

MainWindow::~MainWindow()
{
    if (_client)
        delete _client;
    if (_socket)
        delete _socket;
}

void MainWindow::closeEvent(QCloseEvent *event)
{

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
    auto args = QCoreApplication::arguments();
    _ctForm = new Contacts(this, args[3].toStdString());
    setCentralWidget(_ctForm);
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
