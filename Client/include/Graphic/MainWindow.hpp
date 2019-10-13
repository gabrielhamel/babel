/*
** EPITECH PROJECT, 2019
** BabelFront
** File description:
** MainWindow
*/

#pragma once

#include <QtWidgets/QMainWindow>
#include "SigninForm.hpp"
#include "SignupForm.hpp"
#include "Contacts.hpp"
#include "Client.hpp"
#include "BoostTcpClient.hpp"
#include "IWindow.hpp"

namespace bbl::cli::graphics
{

    class MainWindow : public QMainWindow, public IWindow
    {
        Q_OBJECT
        private:
            ITcpClient *_socket;
            Client *_client;
        public:
            MainWindow();
            ~MainWindow();
            void login(const QString &login, const QString &password);
            void signup(const QString &login, const QString &password);
            Client &getClient();
            void goContacts();
        public slots:
            void goSignup();
            void goSignin();
    };

}
