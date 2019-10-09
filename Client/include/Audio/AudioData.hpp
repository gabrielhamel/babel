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
        float *_recordSamples;
        std::size_t _recordSize;
        AudioParameters *_audioParameters;

    public:
        AudioData();
        AudioData(int frameIndex, int maxFrameIndex);
        ~AudioData();
};
