/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AudioListener
*/

#include "AudioListener.hpp"

using namespace bbl::cli::audio;

AudioListener::AudioListener(IUdpClient *client) :
_client(client), _audiomanager(new AudioManager()), _again(true)
{

}

AudioListener::~AudioListener()
{
    _again = false;
    delete _audiomanager;
}

void AudioListener::run()
{
    std::vector<unsigned char> res;

    while (_again) {
        try {
            res = _client->recv().getData();
        } catch (const std::exception &error) {
            _again = false;
            break;
        }
        _audiomanager->setDataSamples((float *)res.data());
        _audiomanager->playRecord();
    }
}

void AudioListener::destroy()
{
    _client->close();
    _again = false;
}
