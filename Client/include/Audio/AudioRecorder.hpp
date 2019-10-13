/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AudioRecorder
*/

#pragma once

#include <QtCore/QThread>
#include "IUdpClient.hpp"
#include "AudioManager.hpp"

namespace bbl::cli::audio
{

    class AudioRecorder : public QThread
    {
        Q_OBJECT
        private:
            IUdpClient *_client;
            AudioManager *_audiomanager;
            bool _again;
        public:
            AudioRecorder(IUdpClient *client);
            ~AudioRecorder();
            void run();
            void destroy();
    };

}
