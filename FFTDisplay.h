#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_dsp/juce_dsp.h>
#include "AudioProcessorEngine.h"

class FFTDisplay : public juce::Component, private juce::Timer
{
public:
    static constexpr int fftOrder = 11;       // 2048
    static constexpr int fftSize  = 1 << fftOrder;

    FFTDisplay();
    void setAudioEngine(AudioProcessorEngine* engine);

    void paint(juce::Graphics& g) override;

private:
    void timerCallback() override;

    AudioProcessorEngine* audioEngine = nullptr;

    juce::dsp::FFT fft;
    juce::dsp::WindowingFunction<float> window { fftSize, juce::dsp::WindowingFunction<float>::hann };

    std::vector<float> fftData;
};
