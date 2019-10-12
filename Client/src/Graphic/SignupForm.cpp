/*
** EPITECH PROJECT, 2019
** BabelFront
** File description:
** SignupForm
*/

#include "../../include/Graphic/SignupForm.hpp"

using namespace bbl::cli::graphics;

SignupForm::SignupForm(QWidget *parent)
{
    _loginText = new QLineEdit(this);
    _loginText->setPlaceholderText("Username");
    _loginText->setMaxLength(32);
    _loginText->setMinimumWidth(static_cast<int>(static_cast<float>(parent->width()) * 0.7f));
    _loginText->setMinimumHeight(45);
    _loginText->setGeometry(_loginText->x() + static_cast<int>(static_cast<float>(parent->width()) * 0.15f), _loginText->y() + 100, _loginText->width(), _loginText->height());
    _loginText->setStyleSheet("color: white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");

    _passwordText = new QLineEdit(this);
    _passwordText->setPlaceholderText("Password");
    _passwordText->setMaxLength(32);
    _passwordText->setEchoMode(QLineEdit::Password);
    _passwordText->setMinimumWidth(static_cast<int>(static_cast<float>(parent->width()) * 0.7f));
    _passwordText->setMinimumHeight(45);
    _passwordText->setGeometry(_passwordText->x() + static_cast<int>(static_cast<float>(parent->width()) * 0.15f), _passwordText->y() + 170, _passwordText->width(), _passwordText->height());
    _passwordText->setStyleSheet("color:white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");

    _passwordConfirmationText = new QLineEdit(this);
    _passwordConfirmationText->setPlaceholderText("Password confirmation");
    _passwordConfirmationText->setMaxLength(32);
    _passwordConfirmationText->setEchoMode(QLineEdit::Password);
    _passwordConfirmationText->setMinimumWidth(static_cast<int>(static_cast<float>(parent->width()) * 0.7f));
    _passwordConfirmationText->setMinimumHeight(45);
    _passwordConfirmationText->setGeometry(_passwordConfirmationText->x() + static_cast<int>(static_cast<float>(parent->width()) * 0.15f), _passwordConfirmationText->y() + 240, _passwordConfirmationText->width(), _passwordConfirmationText->height());
    _passwordConfirmationText->setStyleSheet("color:white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");

    _signInButton = new QPushButton(this);
    _signInButton->setText("Sign up");
    _signInButton->setMinimumHeight(45);
    _signInButton->setMinimumWidth(static_cast<int>(static_cast<float>(parent->width()) * 0.60f));
    _signInButton->setGeometry(_signInButton->x() + static_cast<int>(static_cast<float>(parent->width()) * 0.20f), _signInButton->y() + 330, _signInButton->width(), _signInButton->height());
    _signInButton->setStyleSheet("QPushButton {color: #fff; background-color: #337ab7; border-color: #2e6da4; border-radius: 9px; margin-bottom: 0; font-weight: 400; border: 1px solid transparent; padding: 9px 12px; font-size: 14px;} QPushButton:hover {background-color: #2269a6; } QPushButton:pressed {background-color: #115895; }");

    _backButton = new QPushButton(this);
    _backButton->setText("Back to the login");
    _backButton->setMaximumHeight(18);
    _backButton->setGeometry(140, 400, 149, _backButton->height());
    _backButton->setCursor(Qt::PointingHandCursor);
    connect(_backButton, SIGNAL(clicked()), parent, SLOT(goSignin()));
    _backButton->setStyleSheet("QPushButton {border: transparent; color: dodgerblue; font-size: 13px; background-color: transparent; } QPushButton:hover {color: deepskyblue;; }");
    connect(this->_passwordConfirmationText, SIGNAL(textChanged(const QString &)), this, SLOT(onPasswordEdit(const QString &)));
}

SignupForm::~SignupForm()
{
    delete _signInButton;
    delete _loginText;
    delete _passwordText;
    delete _passwordConfirmationText;
    delete _backButton;
}

void SignupForm::onPasswordEdit(const QString &text)
{
    this->_passwordText->setStyleSheet("color:white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");
    this->_passwordConfirmationText->setStyleSheet("color:white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");
    if (this->_passwordText->text() != this->_passwordConfirmationText->text()) {
        this->_passwordText->setStyleSheet("border: 1px solid red; color:white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");
        this->_passwordConfirmationText->setStyleSheet("border: 1px solid red; color:white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");
    }
}
