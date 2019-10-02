#include "Form.hpp"

using namespace bbl::cli::graphic::form;

Form::Form::Form() : QWidget(nullptr)
{
    QGridLayout *layout = new QGridLayout();
    int width = 300;
    int height = 100;

    this->setFixedSize(width, height);
    this->button = new QPushButton("register", this);
    this->pseudoField = new QLineEdit();
    this->passwordField = new QLineEdit();
    this->passwordField->setEchoMode(QLineEdit::Password);

    layout->addWidget(new QLabel(tr("Username:")), 0, 0);
    layout->addWidget(new QLabel(tr("Password:")), 1, 0);
    layout->addWidget(this->pseudoField, 0, 1);
    layout->addWidget(this->passwordField, 1, 1);
    layout->addWidget(this->button, 2, 1);

    this->setLayout(layout);
    this->connect(this->button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

Form::Form::~Form()
{
    
}