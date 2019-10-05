#pragma once

#include "../include/Form.hpp"

namespace bbl::cli::graphic::form
{
    class LoginForm : public Form
    {
        Q_OBJECT
        public:
            LoginForm();
            ~LoginForm();
    };
}