/*
** EPITECH PROJETC, 2019
** PortAudioInput.hpp
** File descrition:
** File made to use PortAudioInput
*/

#pragma once

#include "AudioParameters.hpp"
#include "IPortAudio.hpp"
#include "IInput.hpp"

#include <portaudio.h>

class PortAudioInput : public IInput, public IPortAudio  {
    private:
        AudioParameters *_audioParameters;
        PaStreamParameters _inputParameters;

    public:
        PortAudioInput(int i);
        ~PortAudioInput();

        PaStreamParameters getParameters() const;
        void setParameters(const PaStreamParameters getInputParameters);
};