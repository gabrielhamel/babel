/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AudioRecorder
*/

#pragma once

#include "IUdpClient.hpp"
#include "AudioManager.hpp"

namespace bbl::cli::audio
{

    class AudioRecorder {
        public:
            AudioRecorder(IUdpClient *client);
            ~AudioRecorder();
        private:
            IUdpClient *_client;
            AudioManager *_audiomanager;
    };

}
