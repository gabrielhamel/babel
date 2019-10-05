#pragma once

#include "../include/Form.hpp"

namespace bbl::cli::graphic::form
{

    class RegisterForm : public Form
    {
        Q_OBJECT
        private:
            QLineEdit *passwordConfirmField;
            QLabel *errorMessage;
        private slots:
            void onPasswordEdit(const QString &text);
        public:
            explicit RegisterForm();
            ~RegisterForm();
    };

}