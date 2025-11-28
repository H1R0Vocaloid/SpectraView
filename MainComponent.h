#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_dsp/juce_dsp.h>
#include "AudioProcessorEngine.h"
#include "FFTDisplay.h"

class MainComponent : public juce::Component,
                      public juce::Button::Listener
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    void buttonClicked(juce::Button* b) override;

private:
    juce::TextButton loadButton { "Load Audio File" };

    FFTDisplay fftDisplay;
    AudioProcessorEngine audioEngine;

    // JUCE 8 正确写法：成员变量持有 FileChooser
    std::unique_ptr<juce::FileChooser> fileChooser;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
