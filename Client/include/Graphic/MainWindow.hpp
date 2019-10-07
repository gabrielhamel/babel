/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** MainWindow
*/

#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "../Core/Client.hpp"
#include "ContactList.hpp"
#include "LoginForm.hpp"
#include "RegisterForm.hpp"

using namespace bbl::cli::graphic::form;

namespace bbl::cli::graphic
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
        private:
            Client cli;
            QPushButton *registerButton;
            QPushButton *loginButton;
            RegisterForm *registerForm;
            LoginForm *loginForm;
            ContactList *contactList;
        private slots:
            void onRegisterButtonPressed();
            void onLoginButtonPressed();
        public:
            MainWindow(char *ip, int port, QWidget *parent = nullptr);
            ~MainWindow();
            void showContactList();
    };
}