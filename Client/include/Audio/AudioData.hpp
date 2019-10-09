/*
** EPITECH PROJETC, 2019
** AudioData.hpp
** File descrition:
** Manager for the audio part
*/

#pragma once

#include "AudioParameters.hpp"

#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

class AudioData {
    public:
        int _frameIndex;
        int _maxFrameIndex;
        std::vector<float> _recordSamples;
        AudioParameters *_audioParameters;

    public:
        AudioData();
        AudioData(int frameIndex, int maxFrameIndex);
        ~AudioData();

        AudioParameters *getAudioParameters() const;
        std::vector<float> getRecorderSamples() const;
        float getElemRecordSamples(std::size_t index) const;
        void setRecordedSamples(const std::vector<float> recordSamples);
        void addRecordedSample(const float recordedSamples);
};