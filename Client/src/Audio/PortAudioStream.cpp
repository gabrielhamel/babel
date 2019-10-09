/*
** EPITECH PROJETC, 2019
** PortAudioStream.cpp
** File descrition:
** File made to use PortAudioStream
*/

#include "PortAudioStream.hpp"

int recordCall(const void *input, void *output, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
    AudioData *data = (AudioData *)userData;
    const float *rptr = (const float*) input;
    float *wptr = &data->_recordSamples[data->_frameIndex * data->_audioParameters->_channelNumber];
    long framesToCalc = 0;
    int finished = 0;
    unsigned long framesLeft = data->_maxFrameIndex - data->_frameIndex;

    if (framesLeft < framesPerBuffer) {
        framesToCalc = framesLeft;
        finished = paComplete;
    }
    else {
        framesToCalc = framesPerBuffer;
        finished = paContinue;
    }

    if (input == NULL) {
        for (long i = 0; i < framesToCalc; i++) {
            *wptr++ = 0.0f;
            if (data->_audioParameters->_channelNumber == 2)
                *wptr++ = 0.0f;
        }
    }
    else {
        for (long i = 0; i < framesToCalc; i++) {
            *wptr++ = *rptr++;
            if (data->_audioParameters->_channelNumber == 2) {
                *wptr++ = *rptr++;
            }
        }
    }
    data->_frameIndex += framesToCalc;

    return finished;
}


int playbackCall(const void *input, void *output, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
    AudioData *data = (AudioData *)userData;
    float *rptr = &data->_recordSamples[data->_frameIndex * data->_audioParameters->_channelNumber];
    float *wptr = (float*) output;
    unsigned int i = 0;
    int finished = 0;
    unsigned int framesLeft = data->_maxFrameIndex - data->_frameIndex;

    if (framesLeft < framesPerBuffer) {
        for (i = 0; i < framesLeft; i++) {
            *wptr++ = *rptr++;
            if (data->_audioParameters->_channelNumber == 2)
                *wptr++ = *rptr++;
        }
        for(; i < framesPerBuffer; i++) {
            *wptr++ = 0;
            if (data->_audioParameters->_channelNumber == 2)
                *wptr++ = 0;
        }
        data->_frameIndex += framesLeft;
        finished = paComplete;
    }
    else {
        for (i = 0; i < framesPerBuffer; i++) {
            *wptr++ = *rptr++;
            if (data->_audioParameters->_channelNumber == 2)
                *wptr++ = *rptr++;
        }
        data->_frameIndex += framesPerBuffer;
        finished = paContinue;
    }

    return finished;
}

PortAudioStream::PortAudioStream(PaStreamParameters input, PaStreamParameters output, AudioData *data): IStream()
{
    _data = data;
    _input = input;
    _output = output;
    _stream = nullptr;
}

PortAudioStream::~PortAudioStream() {}

void PortAudioStream::OpenStreamRecorder()
{
    PaError err = Pa_OpenStream(&_stream, &_input, NULL, _data->_audioParameters->_sampleRate, _data->_audioParameters->_framePerSecond, paClipOff, recordCall, _data);

    if (err == paInvalidDevice)
        throw std::runtime_error("Error with OpenStream");
}

void PortAudioStream::OpenStreamPlayer()
{
    Pa_OpenStream(&_stream, NULL, &_output, _data->_audioParameters->_sampleRate, _data->_audioParameters->_framePerSecond, paClipOff, playbackCall, _data);
}

AudioData *PortAudioStream::getData() const
{
    return _data;
}

void PortAudioStream::StartStream()
{
    PaError err = Pa_Initialize();

    if (err != paNoError)
        throw std::runtime_error("Error with initialize");
    err = Pa_StartStream(_stream);
    if (err == paBadStreamPtr) {
        throw std::runtime_error("Error with start stream");
    }
    while ((err = Pa_IsStreamActive(_stream)) == 1);
    if (err != paNoError)
        throw std::runtime_error("Error with after streamisActive()");
    CloseStream(_stream);
}

void PortAudioStream::CloseStream(PaStream *stream)
{
    Pa_CloseStream(stream);
    _data->_frameIndex = 0;
}