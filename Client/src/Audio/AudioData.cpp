/*
** EPITECH PROJETC, 2019
** AudioData.cpp
** File descrition:
** Manager for the audio part
*/

#include "AudioData.hpp"

AudioData::AudioData()
{
    _audioParameters = new AudioParameters();
    _maxFrameIndex = _audioParameters->_recordTime + _audioParameters->_sampleRate;
    _frameIndex = 0;
    int numSamples = _maxFrameIndex * _audioParameters->_channelNumber;
    int numBytes = numSamples * sizeof(float);
    _recordSamples = new float[numBytes];
    _recordSize = numBytes;

    for (int i = 0; i < numSamples; i++)
        _recordSamples[i] = 0;

    if (_recordSamples == NULL )
        throw std::runtime_error("Empty recordSamples");
}

AudioData::AudioData(int frameIndex, int maxFrameIndex)
{
    _audioParameters = new AudioParameters();
    _frameIndex = frameIndex;
    _maxFrameIndex = maxFrameIndex;
}

AudioData::~AudioData() {}
