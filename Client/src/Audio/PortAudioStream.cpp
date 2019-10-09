/*
** EPITECH PROJETC, 2019
** PortAudioStream.cpp
** File descrition:
** File made to use PortAudioStream
*/

#include "PortAudioStream.hpp"

int recordCall(const void *input, void *output, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *Userdata)
{
    const float *rptr = (const float*) input;
    AudioData *data = (AudioData *)output;
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
            if (data->_audioParameters->_channelNumber == 2)
                *wptr++ = *rptr++;
        }
    }
    data->_frameIndex += framesToCalc;

    return finished;
}


int playbackCall(const void *input, void *output, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *Userdata)
{
    AudioData *data = (AudioData *)input;
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
    input = input;
    _output = output;
}

PortAudioStream::~PortAudioStream() {}

void PortAudioStream::OpenStreamRecorder()
{
    Pa_OpenStream(&_stream, &_input, (PaStreamParameters *)this->getData(), _data->_audioParameters->_sampleRate, _data->_audioParameters->_framePerSecond, paClipOff, recordCall, _data);
}

void PortAudioStream::OpenStreamPlayer()
{
    Pa_OpenStream(&_stream, (PaStreamParameters *)this->getData(), &_output, _data->_audioParameters->_sampleRate, _data->_audioParameters->_framePerSecond, paClipOff, playbackCall, _data);
}

AudioData *PortAudioStream::getData() const
{
    return _data;
}

void PortAudioStream::StartStream()
{
    PaError err;
    Pa_StartStream(_stream);
    while ((err = Pa_IsStreamActive(_stream)) == 1);

    CloseStream(_stream);
}

void PortAudioStream::CloseStream(PaStream *stream)
{
    Pa_CloseStream(stream);
    _data->_frameIndex = 0;
}