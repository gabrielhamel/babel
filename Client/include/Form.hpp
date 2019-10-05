#pragma once

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

namespace bbl::cli::graphic::form
{
    class Form : public QWidget
    {
        Q_OBJECT
        private:
            QPushButton *validateButton;
            QLineEdit *pseudoField;
        protected:
            QGridLayout *layout;
            QLineEdit *passwordField;
            QLabel *errorMessage;
        public:
            Form(QString type);
            ~Form();
    };
}