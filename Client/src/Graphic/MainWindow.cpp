/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** MainWindow
*/

#include <QtWidgets/QVBoxLayout>
#include "../../include/Network/BoostTcpClient.hpp"
#include "../../include/Graphic/MainWindow.hpp"

using namespace bbl::cli::graphic;

MainWindow::MainWindow(char *ip, int port, QWidget *parent) :
QMainWindow(parent), cli(new BoostTcpClient(ip, port))
{
    QWidget *centralWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    this->registerButton = new QPushButton(tr("Register"));
    this->loginButton = new QPushButton(tr("Login"));
    this->registerForm = new RegisterForm();
    this->loginForm = new LoginForm();
    this->contactList = new ContactList();

    layout->addWidget(this->registerButton);
    layout->addWidget(this->loginButton);
    centralWidget->setLayout(layout);
    this->setCentralWidget(centralWidget);
    this->registerButton->connect(this->registerButton, SIGNAL(clicked()), this, SLOT(onRegisterButtonPressed()));
    this->loginButton->connect(this->loginButton, SIGNAL(clicked()), this, SLOT(onLoginButtonPressed()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::onRegisterButtonPressed()
{
    this->setCentralWidget(this->registerForm);
}

void MainWindow::onLoginButtonPressed()
{
    this->setCentralWidget(this->loginForm);
}

void MainWindow::showContactList()
{
    this->setCentralWidget(this->contactList);
}