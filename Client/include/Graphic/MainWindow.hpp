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

namespace bbl::cli::graphics
{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT
        public:
            MainWindow();
            ~MainWindow();
        public slots:
            void goSignup();
            void goSignin();
    };

}
