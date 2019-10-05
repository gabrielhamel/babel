#include "../include/RegisterForm.hpp"

using namespace bbl::cli::graphic::form;

RegisterForm::RegisterForm() : Form(QString("Register"))
{
    this->passwordConfirmField = new QLineEdit(this);
    this->passwordConfirmField->setEchoMode(QLineEdit::Password);
    this->errorMessage = new QLabel("Password aren't the same");
    this->errorMessage->setStyleSheet("color: red");
    this->layout->addWidget(new QLabel("Confirm Password:"), 2, 0);
    this->layout->addWidget(this->passwordConfirmField, 2, 1);
    this->layout->addWidget(this->errorMessage, 3, 0);
    this->setWindowTitle(tr("BABEL - Registration"));
    this->onPasswordEdit("");
    this->connect(this->passwordConfirmField, SIGNAL(textChanged(const QString &)), this, SLOT(onPasswordEdit(const QString &)));
}

RegisterForm::~RegisterForm()
{
    
}

void RegisterForm::onPasswordEdit(const QString &text)
{
    this->errorMessage->setVisible(this->passwordField->text() != this->passwordConfirmField->text());
    this->passwordField->setStyleSheet("border: 1px solid black");
    this->passwordConfirmField->setStyleSheet("border: 1px solid black");
    if (this->errorMessage->isVisible()) {
        this->passwordField->setStyleSheet("border: 1px solid red");
        this->passwordConfirmField->setStyleSheet("border: 1px solid red");
    }
}