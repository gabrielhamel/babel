/*
** EPITECH PROJETC, 2019
** AudioManager.cpp
** File descrition:
** Manager for the audio part
*/

#include "AudioManager.hpp"

AudioManager::AudioManager()
{
    PaError err = Pa_Initialize();

    if (err != paNoError)
        throw std::runtime_error("Error with initialize");
    int numDevices = Pa_GetDeviceCount();
    int currentOutput = 0;
    int currentInput = 0;
    const PaDeviceInfo *deviceInfo;
    _data = new AudioData();
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;

    for (int i = 0; i < numDevices; i++) {
        deviceInfo = Pa_GetDeviceInfo(i);
        if (deviceInfo->maxInputChannels > 0) {
            _inputDevices.push_back(new PortAudioInput(i));
            j++;
        }
        if (deviceInfo->maxOutputChannels > 0) {
            _outputDevices.push_back(new PortAudioOutput(i));
            k++;
        }
        if (i == Pa_GetDefaultInputDevice()) {
            l = j - 1;
            currentInput = i;
        }
        if (i == Pa_GetDefaultOutputDevice()) {
            m = k - 1;
            currentOutput = i;
        }
    }
    if (numDevices == 0)
        std::cerr << "No device found" << std::endl;
    _iStream = new PortAudioStream(_inputDevices.at(l)->getParameters(), _outputDevices.at(m)->getParameters(), _data);
}

AudioManager::~AudioManager() {}

void AudioManager::startRecord()
{
    _iStream->OpenStreamRecorder();
    _iStream->StartStream();
}

void AudioManager::playRecord(){
    _iStream->OpenStreamPlayer();
    _iStream->StartStream();
}

float *AudioManager::getDataSamples() const
{
    return _data->_recordSamples;
}

void AudioManager::setDataSamples(float *data)
{
    _data->_recordSamples = data;
}