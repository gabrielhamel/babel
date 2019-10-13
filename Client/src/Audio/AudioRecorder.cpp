/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AudioRecorder
*/

#include "AudioRecorder.hpp"

using namespace bbl::cli::audio;

AudioRecorder::AudioRecorder(IUdpClient *client) :
_client(client), _audiomanager(new AudioManager())
{
    // while (1) {
    //     audiomanager->startRecord();
    //     float *data = audiomanager->getDataSamples();
    //     client->send(Packet((const unsigned char *)data, audiomanager->getSizeSamples()));
    // }
}

AudioRecorder::~AudioRecorder()
{
    delete _audiomanager;
}
