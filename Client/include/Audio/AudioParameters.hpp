/*
** EPITECH PROJETC, 2019
** AudioParameters.hpp
** File descrition:
** Contains values for the AudioManager
*/

#pragma once

#include <cstddef>

class AudioParameters {
    public:
        const int _sampleRate;
        const int _framePerSecond;
        const float _recordTime;
        const std::size_t _channelNumber;
    
    public:
        AudioParameters(): _sampleRate(44100), _framePerSecond(512), _recordTime(2), _channelNumber(2) { }
        ~AudioParameters();

        int getSampleRate() const { return _sampleRate;}
        int getFramerBuffer() const {return _framePerSecond;}
        float getRecordTime() const {return _recordTime;}
        std::size_t getChannelNumber() const {return _channelNumber;}
};