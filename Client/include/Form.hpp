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
            QPushButton *button;
            QLineEdit *pseudoField;
        protected:
            QGridLayout *layout;
            QLineEdit *passwordField;
        public:
            Form();
            ~Form();
    };
}