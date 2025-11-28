#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_dsp/juce_dsp.h>

class AudioProcessorEngine
{
public:
    AudioProcessorEngine();

    bool loadFile(const juce::File& file);

    const juce::AudioBuffer<float>& getBuffer() const { return audioBuffer; }
    int getSampleRate() const { return sampleRate; }

private:
    juce::AudioFormatManager formatManager;
    juce::AudioBuffer<float> audioBuffer;
    int sampleRate = 44100;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioProcessorEngine)
};
