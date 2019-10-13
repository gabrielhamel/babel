/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AudioListener
*/

#pragma once

#include <QtCore/QThread>
#include "IUdpClient.hpp"
#include "AudioManager.hpp"

namespace bbl::cli::audio
{

    class AudioListener : public QThread
    {
        Q_OBJECT
        private:
            IUdpClient *_client;
            AudioManager *_audiomanager;
            bool _again;
        public:
            AudioListener(IUdpClient *client);
            ~AudioListener();
            void run();
            void destroy();
    };

}
