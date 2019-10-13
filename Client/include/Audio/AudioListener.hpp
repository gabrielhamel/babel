/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AudioListener
*/

#pragma once

#include "IUdpClient.hpp"
#include "AudioManager.hpp"

namespace bbl::cli::audio
{

    class AudioListener {
        public:
            AudioListener(IUdpClient *client);
            ~AudioListener();
        private:
            IUdpClient *_client;
            AudioManager *_audiomanager;
    };

}
