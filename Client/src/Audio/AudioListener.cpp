/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AudioListener
*/

#include "AudioListener.hpp"

using namespace bbl::cli::audio;

AudioListener::AudioListener(IUdpClient *client) :
_client(client), _audiomanager(new AudioManager())
{
    // while (1) {
    //     auto res = client->recv().getData();
    //     audiomanager->setDataSamples((float *)res.data());
    //     audiomanager->playRecord();
    // }
}

AudioListener::~AudioListener()
{
    delete _audiomanager;
}
