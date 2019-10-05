/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** MainWindow
*/

#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "LoginForm.hpp"
#include "RegisterForm.hpp"

using namespace bbl::cli::graphic::form;

namespace bbl::cli::graphic
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
        private:
            QPushButton *registerButton;
            QPushButton *loginButton;
            RegisterForm *registerForm;
            LoginForm *loginForm;
        private slots:
            void onRegisterButtonPressed();
            void onLoginButtonPressed();
        public:
            MainWindow(QWidget *parent = nullptr);
            ~MainWindow();
    };
}