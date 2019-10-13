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
#include "BoostUdpClient.hpp"
#include "IWindow.hpp"
#include "AudioListener.hpp"
#include "AudioRecorder.hpp"

namespace bbl::cli::graphics
{
    class Contacts : public QWidget
    {
        Q_OBJECT
        private:
            IWindow *_window;
            IUdpClient *_me;
            IUdpClient *_he;
            audio::AudioListener *_listener;
            audio::AudioRecorder *_recorder;
            std::vector <std::string> _contacts;
            QStringListModel *_contactsModel;
            QListView *_contactsList;
            QLabel *_contactsLabel;
            QLabel *_inviteLabel;
            QPushButton *_contactsReload;
            std::vector <std::string> _invitations;
            QStringListModel *_invitationsModel;
            QListView *_invitationsList;
            QLabel *_invitationsLabel;
            QPushButton *_invitationsReload;
            QPushButton *_acceptInvitationButton;
            QPushButton *_callButton;
            QPushButton *_inviteButton;
            QLineEdit *_contactSearch;
        public:
            Contacts(QMainWindow *parent, const std::string &myIpv4);
            ~Contacts();
            void destroy();
        public slots:
            void refreshContacts();
            void refreshInvitations();
            void acceptInvitation();
            void call();
            void invite();
    };
}
