#include "../include/Form.hpp"

using namespace bbl::cli::graphic::form;

Form::Form::Form() : QWidget(nullptr)
{
    int width = 350;
    int height = 150;

    this->setFixedSize(width, height);
    this->button = new QPushButton("register", this);
    this->pseudoField = new QLineEdit(this);
    this->passwordField = new QLineEdit(this);
    this->passwordField->setEchoMode(QLineEdit::Password);

    this->layout = new QGridLayout();
    this->layout->addWidget(new QLabel(tr("Username:")), 0, 0);
    this->layout->addWidget(new QLabel(tr("Password:")), 1, 0);
    this->layout->addWidget(this->pseudoField, 0, 1);
    this->layout->addWidget(this->passwordField, 1, 1);
    this->layout->addWidget(this->button, 3, 1);

    this->setLayout(this->layout);
    this->connect(this->button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

Form::Form::~Form()
{
    
}