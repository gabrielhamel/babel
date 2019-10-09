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
    _frameIndex = _audioParameters->_recordTime + _audioParameters->_sampleRate;
    _maxFrameIndex = 0;
}

AudioData::AudioData(int frameIndex, int maxFrameIndex)
{
    _audioParameters = new AudioParameters();
    _frameIndex = frameIndex;
    _maxFrameIndex = maxFrameIndex;
}

AudioData::~AudioData() {}

AudioParameters *AudioData::getAudioParameters() const
{
    return _audioParameters;
}

std::vector<float> AudioData::getRecorderSamples() const
{
    return _recordSamples;
}

float AudioData::getElemRecordSamples(std::size_t index) const
{
    if (_recordSamples.size() >= index)
        return _recordSamples.at(index);

    std::cerr << "Error with the index, it's above the size of recordedSamples" << std::endl;
    return 0;
}

void AudioData::setRecordedSamples(const std::vector<float> recordedSamples)
{
    _recordSamples = recordedSamples;
}

void AudioData::addRecordedSample(const float recordedSamples)
{
    _recordSamples.push_back(recordedSamples);
}