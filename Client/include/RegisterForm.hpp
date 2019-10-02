#pragma once

#include "Form.hpp"

using namespace bbl::cli::graphic::form;

namespace bbl::cli::graphic::form
{

    class RegisterForm : public Form
    {
        private:
            QLineEdit *passwordConfirmField;
        public:
            explicit RegisterForm();
            ~RegisterForm();
    };

}