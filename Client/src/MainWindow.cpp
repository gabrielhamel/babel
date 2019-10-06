/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** MainWindow
*/

#include <QtWidgets/QVBoxLayout>
#include "../include/MainWindow.hpp"

using namespace bbl::cli::graphic;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    this->registerForm = new RegisterForm();
    this->loginForm = new LoginForm();
    this->registerButton = new QPushButton("Register");
    this->loginButton = new QPushButton("Login");

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
