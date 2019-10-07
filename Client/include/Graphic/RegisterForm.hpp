#pragma once

#include "Form.hpp"

namespace bbl::cli::graphic::form
{

    class RegisterForm : public Form
    {
        Q_OBJECT
        private:
            QLineEdit *passwordConfirmField;
        private slots:
            void onPasswordEdit(const QString &text);
        public:
            explicit RegisterForm();
            ~RegisterForm();
    };

}