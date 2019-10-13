/*
** EPITECH PROJECT, 2019
** BabelFront
** File description:
** MainWindow
*/

#pragma once

#include <QtGui/QCloseEvent>
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
            Contacts *_ctForm;
        public:
            MainWindow();
            ~MainWindow();
            void login(const QString &login, const QString &password);
            void signup(const QString &login, const QString &password);
            Client &getClient();
            void goContacts();
            void closeEvent(QCloseEvent *event);
        public slots:
            void goSignup();
            void goSignin();
    };

}
