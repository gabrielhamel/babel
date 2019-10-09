/*
** EPITECH PROJETC, 2019
** IStream.hpp
** File descrition:
** Interface for Stream
*/

#pragma once

#include <portaudio.h>

class IStream {
    public:
        virtual ~IStream() = default;
        virtual void OpenStreamRecorder() = 0;
        virtual void OpenStreamPlayer() = 0;
        virtual void StartStream() = 0;
};