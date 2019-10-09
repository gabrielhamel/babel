/*
** EPITECH PROJETC, 2019
** PortAudioInput.cpp
** File descrition:
** File made to use PortAudioInput
*/

#include "PortAudioInput.hpp"

PortAudioInput::PortAudioInput(int i) : IInput(), IPortAudio()
{
    _audioParameters = new AudioParameters();
    _inputParameters.device = i;
    _inputParameters.channelCount = _audioParameters->_channelNumber;
    _inputParameters.sampleFormat = paFloat32;
    _inputParameters.suggestedLatency = Pa_GetDeviceInfo(_inputParameters.device)->defaultLowInputLatency;
    _inputParameters.hostApiSpecificStreamInfo = NULL;
}

PortAudioInput::~PortAudioInput() {}

PaStreamParameters PortAudioInput::getParameters() const
{
    return _inputParameters;
}

void PortAudioInput::setParameters(const PaStreamParameters inputParameters)
{
    _inputParameters = inputParameters;
}