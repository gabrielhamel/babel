/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Contacts
*/

#include <iostream>
#include <QtCore/QThread>
#include "../../include/Graphic/Contacts.hpp"

using namespace bbl::cli::graphics;

Contacts::Contacts(QMainWindow *parent, const std::string &myIpv4) :
_he(nullptr), _me(nullptr), _recorder(nullptr)
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

    _acceptInvitationButton = new QPushButton(this);
    _acceptInvitationButton->setIcon(QIcon(QPixmap(":/images/check.png")));
    _acceptInvitationButton->setGeometry(125, 450, 40, 40);
    connect(_acceptInvitationButton, SIGNAL(clicked()), this, SLOT(acceptInvitation()));
    _acceptInvitationButton->setStyleSheet("QPushButton {color: #fff; background-color: #337ab7; border-color: #2e6da4; border-radius: 9px; margin-bottom: 0; font-weight: 400; border: 1px solid transparent; padding: 9px 12px; font-size: 14px;} QPushButton:hover {background-color: #2269a6; } QPushButton:pressed {background-color: #115895; }");

    _callButton = new QPushButton(this);
    _callButton->setIcon(QIcon(QPixmap(":/images/call.png")));
    _callButton->setGeometry(125 + 510, 450, 40, 40);
    connect(_callButton, SIGNAL(clicked()), this, SLOT(call()));
    _callButton->setStyleSheet("QPushButton {color: #fff; background-color: #337ab7; border-color: #2e6da4; border-radius: 9px; margin-bottom: 0; font-weight: 400; border: 1px solid transparent; padding: 9px 12px; font-size: 14px;} QPushButton:hover {background-color: #2269a6; } QPushButton:pressed {background-color: #115895; }");

    _contactSearch = new QLineEdit(this);
    _contactSearch->setPlaceholderText("Username");
    _contactSearch->setMaxLength(32);
    _contactSearch->setMinimumWidth(150);
    _contactSearch->setGeometry(400 - _contactSearch->width() / 2 - 30, 80, _contactSearch->width(), _contactSearch->height() + 10);
    _contactSearch->setStyleSheet("color: white; background-color: #666666; border-radius: 9px; padding-left: 10px; padding-right: 10px; font-size: 20px;");

    _inviteLabel = new QLabel(this);
    _inviteLabel->setText("Search");
    _inviteLabel->setMinimumWidth(190);
    _inviteLabel->setGeometry(330, 20, _inviteLabel->width(), _inviteLabel->height() + 10);
    _inviteLabel->setStyleSheet("color: white; font-size: 38px;");

    _inviteButton = new QPushButton(this);
    _inviteButton->setIcon(QIcon(QPixmap(":/images/check.png")));
    _inviteButton->setGeometry(400 + _contactSearch->width() / 2 - 20, 80, 40, 40);
    connect(_inviteButton, SIGNAL(clicked()), this, SLOT(invite()));
    _inviteButton->setStyleSheet("QPushButton {color: #fff; background-color: #337ab7; border-color: #2e6da4; border-radius: 9px; margin-bottom: 0; font-weight: 400; border: 1px solid transparent; padding: 9px 12px; font-size: 14px;} QPushButton:hover {background-color: #2269a6; } QPushButton:pressed {background-color: #115895; }");

    _me = new BoostUdpClient("0.0.0.0", 0, true);
    _window->getClient().setUdpSetting(myIpv4, _me->getPort());
    _listener = new audio::AudioListener(_me);

    refreshContacts();
    refreshInvitations();

    _listener->start();
}

Contacts::~Contacts()
{
    if (_listener)
        _listener->destroy();
    if (_recorder)
        _recorder->destroy();
    delete _contactsList;
    delete _contactsModel;
    delete _contactsLabel;
    delete _contactsReload;
    delete _invitationsList;
    delete _invitationsModel;
    delete _invitationsLabel;
    delete _invitationsReload;
    delete _acceptInvitationButton;
    delete _callButton;
    delete _inviteButton;
    delete _contactSearch;
    delete _inviteLabel;
    if (_me)    
        delete _me;
    if (_he)
        delete _he;
}

void Contacts::refreshContacts()
{
    try {
        _contacts = _window->getClient().getContacts();
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
    QStringList list;
    for (auto &contact : _contacts)
        list << QString::fromStdString(contact);
    _contactsModel->setStringList(list);
}

void Contacts::refreshInvitations()
{
    try {
        _invitations = _window->getClient().getInvitations();
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
    QStringList list;
    for (auto &invitation : _invitations)
        list << QString::fromStdString(invitation);
    _invitationsModel->setStringList(list);
}

void Contacts::acceptInvitation()
{
    auto selected = _invitationsList->currentIndex().data(Qt::DisplayRole).toString();
    if (selected == "")
        return;
    try {
        _window->getClient().acceptInvitation(selected.toStdString());
        refreshContacts();
        refreshInvitations();
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
}

void Contacts::invite()
{
    auto contact = _contactSearch->text().toStdString();
    if (contact == "")
        return;
    try {
        _window->getClient().requestInvitation(contact);
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
}

void Contacts::call()
{
    auto user = _contactsList->currentIndex().data(Qt::DisplayRole).toString().toStdString();
    if (user == "")
        return;
    try {
        auto settings = _window->getClient().getUdpSettings(user);
        _he = new BoostUdpClient(settings.first, settings.second, false);
        _recorder = new audio::AudioRecorder(_he);
        _recorder->start();
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
}

void Contacts::destroy()
{

}
