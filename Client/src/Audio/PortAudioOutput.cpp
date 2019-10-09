/*
** EPITECH PROJETC, 2019
** PortAudioOutput.cpp
** File descrition:
** File made to use PortAudioOutput
*/

#include "PortAudioOutput.hpp"

PortAudioOutput::PortAudioOutput(int i) : IOutput(), IPortAudio()
{
    _audioParameters = new AudioParameters();
    _outputParameters.device = i;
    _outputParameters.channelCount = _audioParameters->_channelNumber;
    _outputParameters.sampleFormat = paFloat32;
    _outputParameters.suggestedLatency = Pa_GetDeviceInfo(_outputParameters.device)->defaultLowInputLatency;
    _outputParameters.hostApiSpecificStreamInfo = NULL;
}

PortAudioOutput::~PortAudioOutput() {}

PaStreamParameters PortAudioOutput::getParameters() const
{
    return _outputParameters;
}

void PortAudioOutput::setParameters(const PaStreamParameters outputParameters)
{
    _outputParameters = outputParameters;
}