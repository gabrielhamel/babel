/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** IWindow
*/

#pragma once

#include <QtWidgets/QMainWindow>
#include "Client.hpp"

namespace bbl::cli::graphics
{

    class IWindow
    {
        public:
            virtual ~IWindow() = default;
            virtual void login(const QString &login, const QString &password) = 0;
            virtual void signup(const QString &login, const QString &password) = 0;
            virtual Client &getClient() = 0;
    };

}
