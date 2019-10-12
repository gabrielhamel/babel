/*
** EPITECH PROJECT, 2019
** BabelFront
** File description:
** SignupForm
*/

#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

namespace bbl::cli::graphics
{
    class SignupForm : public QWidget
    {
        Q_OBJECT
        private:
            QPushButton *_signInButton;
            QLineEdit *_loginText;
            QLineEdit *_passwordText;
            QLineEdit *_passwordConfirmationText;
            QPushButton *_backButton;
        public:
            SignupForm(QWidget *parent);
            ~SignupForm();
        public slots:
            void onPasswordEdit(const QString &text);
    };
}
