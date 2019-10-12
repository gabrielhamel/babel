/*
** EPITECH PROJECT, 2019
** BabelFront
** File description:
** MainWindow
*/

#include <iostream>
#include "../../include/Graphic/MainWindow.hpp"

using namespace bbl::cli::graphics;

MainWindow::MainWindow() :
QMainWindow(nullptr)
{
    this->setWindowIcon(QIcon(":/images/favicon.png"));
    this->setFixedSize(QSize(420, 500));
    this->setStyleSheet("background-color: #444444");
    this->setCentralWidget(new SigninForm(this));
}

MainWindow::~MainWindow()
{

}

void MainWindow::goSignup()
{
    this->setCentralWidget(new SignupForm(this));
}

void MainWindow::goSignin()
{
    this->setCentralWidget(new SigninForm(this));
}
