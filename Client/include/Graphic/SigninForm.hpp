/*
** EPITECH PROJECT, 2019
** BabelFront
** File description:
** SigninForm
*/

#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

namespace bbl::cli::graphics
{
    class SigninForm : public QWidget
    {
        Q_OBJECT
        private:
            QLabel *_imageLabel;
            QLabel *_logoLabel;
            QLineEdit *_loginText;
            QLineEdit *_passwordText;
            QPushButton *_loginButton;
            QLabel *_notRegisteredLabel;
            QPushButton *_signUpButton;
        public:
            SigninForm(QWidget *parent);
            ~SigninForm();
    };
}
