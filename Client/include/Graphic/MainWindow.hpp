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
#include "BoostTcpClient.hpp"
#include "IWindow.hpp"

namespace bbl::cli::graphics
{

    class MainWindow : public QMainWindow, public IWindow
    {
        Q_OBJECT
        private:
            ITcpClient *_client;
        public:
            MainWindow();
            ~MainWindow();
            void login(const QString &login, const QString &password);
        public slots:
            void goSignup();
            void goSignin();
    };

}
