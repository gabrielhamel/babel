/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Contacts
*/

#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListView>
#include <QtCore/QStringListModel>
#include "IWindow.hpp"

namespace bbl::cli::graphics
{
    class Contacts : public QWidget
    {
        Q_OBJECT
        private:
            IWindow *_window;
            std::vector <std::string> _contacts;
            QStringListModel *_contactsModel;
            QListView *_contactsList;
        public:
            Contacts(QMainWindow *parent);
            ~Contacts();
            void refreshContacts();
    };
}
