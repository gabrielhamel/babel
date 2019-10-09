/*
** EPITECH PROJETC, 2019
** IPortAudio.hpp
** File descrition:
** Interface for portaudio
*/

#pragma once

#include <portaudio.h>

class IPortAudio {
    public:
        virtual ~IPortAudio() = default;
        virtual PaStreamParameters getParameters() const = 0;
};