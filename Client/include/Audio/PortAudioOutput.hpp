/*
** EPITECH PROJETC, 2019
** PortAudioOutput.hpp
** File descrition:
** File made to use PortAudioOutput
*/

#pragma once

#include "AudioParameters.hpp"
#include "IPortAudio.hpp"
#include "IOutput.hpp"

#include <portaudio.h>

class PortAudioOutput : public IOutput, public IPortAudio {
    private:
        AudioParameters *_audioParameters;
        PaStreamParameters _outputParameters;

    public:
        PortAudioOutput(int i);
        ~PortAudioOutput();

        PaStreamParameters getParameters() const;
        void setParameters(const PaStreamParameters getOutputParameters);
};