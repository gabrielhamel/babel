/*
** EPITECH PROJETC, 2019
** AudioManager.cpp
** File descrition:
** Manager for the audio part
*/

#include "AudioManager.hpp"

AudioManager::AudioManager()
{
    int numDevices = Pa_GetDeviceCount();
    int currentOutput = 0;
    int currentInput = 0;
    const PaDeviceInfo *deviceInfo;
    _data = new AudioData();

    for (int i = 0; i < numDevices; i++) {
        deviceInfo = Pa_GetDeviceInfo(i);
        if (deviceInfo->maxInputChannels > 0)
            _inputDevices.push_back(new PortAudioInput(i));
        if (deviceInfo->maxOutputChannels > 0)
            _outputDevices.push_back(new PortAudioOutput(i));
        if (i == Pa_GetDefaultInputDevice())
            currentInput = i;
        if (i == Pa_GetDefaultOutputDevice())
            currentOutput = i;
    }
    _iStream = new PortAudioStream(_inputDevices.at(currentInput)->getParameters(), _outputDevices.at(currentOutput)->getParameters(), _data);
}

AudioManager::~AudioManager() {}

void AudioManager::startRecord()
{
    _iStream->OpenStreamRecorder();
    _iStream->StartStream();
    _iStream->OpenStreamPlayer();
    _iStream->StartStream();
}