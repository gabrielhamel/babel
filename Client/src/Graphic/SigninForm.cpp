/*
** EPITECH PROJECT, 2019
** BabelFront
** File description:
** SigninForm
*/

#include "../../include/Graphic/SigninForm.hpp"

using namespace bbl::cli::graphics;

SigninForm::SigninForm(QWidget *parent)
{
    _imageLabel = new QLabel(this);
    QImage favicon(":/images/favicon.png");
    _imageLabel->setMinimumHeight(100);
    _imageLabel->setScaledContents(true);
    _imageLabel->setPixmap(QPixmap::fromImage(favicon));
    _imageLabel->setGeometry(30, 37, _imageLabel->width(), _imageLabel->height());

    _logoLabel = new QLabel(this);
    QImage logoFavicon(":/images/bigLogo.png");
    _logoLabel->setMinimumHeight(95);
    _logoLabel->setMinimumWidth(250);
    _logoLabel->setScaledContents(true);
    _logoLabel->setPixmap(QPixmap::fromImage(logoFavicon));
    _logoLabel->setGeometry(135, 41, _logoLabel->width(), _logoLabel->height());

    _loginText = new QLineEdit(this);
    _loginText->setPlaceholderText("Username");
    _loginText->setMaxLength(32);
    _loginText->setMinimumWidth(static_cast<int>(static_cast<float>(parent->width()) * 0.7f));
    _loginText->setMinimumHeight(45);
    _loginText->setGeometry(_loginText->x() + static_cast<int>(static_cast<float>(parent->width()) * 0.15f), _loginText->y() + 200, _loginText->width(), _loginText->height());
    _loginText->setStyleSheet("color: white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");

    _passwordText = new QLineEdit(this);
    _passwordText->setPlaceholderText("Password");
    _passwordText->setMaxLength(32);
    _passwordText->setEchoMode(QLineEdit::Password);
    _passwordText->setMinimumWidth(static_cast<int>(static_cast<float>(parent->width()) * 0.7f));
    _passwordText->setMinimumHeight(45);
    _passwordText->setGeometry(_passwordText->x() + static_cast<int>(static_cast<float>(parent->width()) * 0.15f), _passwordText->y() + 270, _passwordText->width(), _passwordText->height());
    _passwordText->setStyleSheet("color:white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");

    _loginButton = new QPushButton(this);
    _loginButton->setText("Login");
    _loginButton->setMinimumHeight(45);
    _loginButton->setMinimumWidth(static_cast<int>(static_cast<float>(parent->width()) * 0.60f));
    _loginButton->setGeometry(_loginButton->x() + static_cast<int>(static_cast<float>(parent->width()) * 0.20f), _loginButton->y() + 350, _loginButton->width(), _loginButton->height());
    _loginButton->setStyleSheet("QPushButton {color: #fff; background-color: #337ab7; border-color: #2e6da4; border-radius: 9px; margin-bottom: 0; font-weight: 400; border: 1px solid transparent; padding: 9px 12px; font-size: 14px;} QPushButton:hover {background-color: #2269a6; } QPushButton:pressed {background-color: #115895; }");

    _notRegisteredLabel = new QLabel(this);
    _notRegisteredLabel->setText("Don’t have an account ?");
    _notRegisteredLabel->setMinimumWidth(147);
    _notRegisteredLabel->setGeometry(110, 410, _notRegisteredLabel->width(), _notRegisteredLabel->height());
    _notRegisteredLabel->setStyleSheet("color: white; font-size: 13px;");

    _signUpButton = new QPushButton(this);
    _signUpButton->setText("Sign up");
    _signUpButton->setMaximumHeight(18);
    _signUpButton->setGeometry(255, 416, 49, _signUpButton->height());
    _signUpButton->setCursor(Qt::PointingHandCursor);
    connect(_signUpButton, SIGNAL(clicked()), parent, SLOT(goSignup()));
    _signUpButton->setStyleSheet("QPushButton {border: transparent; color: dodgerblue; font-size: 13px; background-color: transparent; } QPushButton:hover {color: deepskyblue;; }");
}

SigninForm::~SigninForm()
{
    delete _imageLabel;
    delete _logoLabel;
    delete _loginText;
    delete _passwordText;
    delete _loginButton;
    delete _notRegisteredLabel;
    delete _signUpButton;
}
