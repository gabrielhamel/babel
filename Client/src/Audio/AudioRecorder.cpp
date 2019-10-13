/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AudioRecorder
*/

#include "AudioRecorder.hpp"

using namespace bbl::cli::audio;

AudioRecorder::AudioRecorder(IUdpClient *client) :
_client(client), _audiomanager(new AudioManager()), _again(true)
{

}

AudioRecorder::~AudioRecorder()
{
    _again = false;
    delete _audiomanager;
}

void AudioRecorder::run()
{
    while (_again) {
        _audiomanager->startRecord();
        float *data = _audiomanager->getDataSamples();
        try {
            _client->send(Packet((const unsigned char *)data, _audiomanager->getSizeSamples()));
        } catch (const std::exception &error) {
            _again = false;
            break;
        }
    }
}

void AudioRecorder::destroy()
{
    _client->close();
    _again = false;
}
