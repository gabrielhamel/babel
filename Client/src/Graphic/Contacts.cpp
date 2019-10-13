/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Contacts
*/

#include "../../include/Graphic/Contacts.hpp"

using namespace bbl::cli::graphics;

Contacts::Contacts(QMainWindow *parent)
{
    _window = dynamic_cast<IWindow *>(parent);

    parent->setFixedSize(QSize(700, 500));

    _contactsModel = new QStringListModel();
    _contactsList = new QListView(this);
    _contactsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _contactsList->setModel(_contactsModel);
    _contactsList->setGeometry(0, 0, 300, 400);
    _contactsList->setStyleSheet();

    refreshContacts();
}

Contacts::~Contacts()
{
    delete _contactsList;
    delete _contactsModel;
}

void Contacts::refreshContacts()
{
    _contacts = _window->getClient().getContacts();
    QStringList list;
    for (auto &contact : _contacts)
        list << QString::fromStdString(contact);
    _contactsModel->setStringList(list);
}
