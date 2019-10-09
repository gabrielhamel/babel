/*
** EPITECH PROJETC, 2019
** AudioManager.hpp
** File descrition:
** Manager for the audio part
*/

#pragma once

#include "AudioData.hpp"
#include "AudioParameters.hpp"
#include "IPortAudio.hpp"
#include "PortAudioInput.hpp"
#include "PortAudioOutput.hpp"
#include "PortAudioStream.hpp"

#include <portaudio.h>
#include <vector>

class AudioManager {
    private:
        AudioData *_data;
        std::vector<IPortAudio *> _inputDevices;
        std::vector<IPortAudio *> _outputDevices;
        IStream *_iStream;

    public:
        AudioManager();
        ~AudioManager();
        void startRecord();
        void playRecord();
        float *getDataSamples() const;
        std::size_t getSizeSamples() const;
        void setDataSamples(float *data);
};
