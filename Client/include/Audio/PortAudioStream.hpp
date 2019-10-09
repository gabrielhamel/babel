/*
** EPITECH PROJETC, 2019
** PortAudioStream.hpp
** File descrition:
** File made to use PortAudioStream
*/

#pragma once

#include <portaudio.h>
#include "AudioData.hpp"
#include "IInput.hpp"
#include "IStream.hpp"
#include "PortAudioInput.hpp"
#include "PortAudioOutput.hpp"

class PortAudioStream : public IStream {
    private:
        AudioData *_data;
        PaStream *_stream;
        PaStreamParameters _input;
        PaStreamParameters _output;

        AudioData *getData() const;
        void CloseStream(PaStream *stream);

    public:
        PortAudioStream(PaStreamParameters input, PaStreamParameters output, AudioData *data);
        ~PortAudioStream();

        void OpenStreamRecorder();
        void OpenStreamPlayer();
        void StartStream();
}; 