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

    parent->setFixedSize(QSize(800, 500));

    _invitationsLabel = new QLabel(this);
    _invitationsLabel->setText("Invitations");
    _invitationsLabel->setMinimumWidth(200);
    _invitationsLabel->setGeometry(25, 20, _invitationsLabel->width(), _invitationsLabel->height() + 10);
    _invitationsLabel->setStyleSheet("color: white; font-size: 38px;");

    _invitationsReload = new QPushButton(this);
    _invitationsReload->setIcon(QIcon(QPixmap(":/images/refresh.png")));
    _invitationsReload->setGeometry(225, 25, 40, 40);
    connect(_invitationsReload, SIGNAL(clicked()), this, SLOT(refreshInvitations()));
    _invitationsReload->setStyleSheet("QPushButton {color: #fff; background-color: #337ab7; border-color: #2e6da4; border-radius: 9px; margin-bottom: 0; font-weight: 400; border: 1px solid transparent; padding: 9px 12px; font-size: 14px;} QPushButton:hover {background-color: #2269a6; } QPushButton:pressed {background-color: #115895; }");

    _invitationsModel = new QStringListModel();
    _invitationsList = new QListView(this);
    _invitationsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _invitationsList->setModel(_invitationsModel);
    _invitationsList->setGeometry(25, 80, 240, 355);
    _invitationsList->setStyleSheet("color: white; background-color: #666666; border-radius: 9px; padding-top: 10px; padding-bottom: 10px; font-size: 20px;");

    _contactsLabel = new QLabel(this);
    _contactsLabel->setText("Contacts");
    _contactsLabel->setMinimumWidth(200);
    _contactsLabel->setGeometry(25 + 500, 20, _contactsLabel->width(), _contactsLabel->height() + 10);
    _contactsLabel->setStyleSheet("color: white; font-size: 38px;");

    _contactsReload = new QPushButton(this);
    _contactsReload->setIcon(QIcon(QPixmap(":/images/refresh.png")));
    _contactsReload->setGeometry(225 + 500, 25, 40, 40);
    connect(_contactsReload, SIGNAL(clicked()), this, SLOT(refreshContacts()));
    _contactsReload->setStyleSheet("QPushButton {color: #fff; background-color: #337ab7; border-color: #2e6da4; border-radius: 9px; margin-bottom: 0; font-weight: 400; border: 1px solid transparent; padding: 9px 12px; font-size: 14px;} QPushButton:hover {background-color: #2269a6; } QPushButton:pressed {background-color: #115895; }");

    _contactsModel = new QStringListModel();
    _contactsList = new QListView(this);
    _contactsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _contactsList->setModel(_contactsModel);
    _contactsList->setGeometry(25 + 500, 80, 240, 355);
    _contactsList->setStyleSheet("color: white; background-color: #666666; border-radius: 9px; padding-top: 10px; padding-bottom: 10px; font-size: 20px;");

    refreshContacts();
    refreshInvitations();
}

Contacts::~Contacts()
{
    delete _contactsList;
    delete _contactsModel;
    delete _invitationsList;
    delete _invitationsModel;
}

void Contacts::refreshContacts()
{
    _contacts = _window->getClient().getContacts();
    QStringList list;
    for (auto &contact : _contacts)
        list << QString::fromStdString(contact);
    _contactsModel->setStringList(list);
}

void Contacts::refreshInvitations()
{
    _invitations = _window->getClient().getInvitations();
    QStringList list;
    for (auto &invitation : _invitations)
        list << QString::fromStdString(invitation);
    _invitationsModel->setStringList(list);
}