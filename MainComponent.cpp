#include "MainComponent.h"

MainComponent::MainComponent()
{
    addAndMakeVisible(loadButton);
    loadButton.addListener(this);

    addAndMakeVisible(fftDisplay);

    setSize(1000, 700);
}

MainComponent::~MainComponent() {}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);
}

void MainComponent::resized()
{
    loadButton.setBounds(10, 10, 150, 40);
    fftDisplay.setBounds(10, 60, getWidth() - 20, getHeight() - 70);
}

void MainComponent::buttonClicked(juce::Button* b)
{
    if (b == &loadButton)
    {
        // JUCE 8 最推荐的写法：用成员变量持有 FileChooser
        fileChooser = std::make_unique<juce::FileChooser>(
            "Choose an audio file...",
            juce::File{},
            "*.wav;*.mp3;*.aiff"
        );

        // 异步文件选择（JUCE 8）
        fileChooser->launchAsync(
            juce::FileBrowserComponent::openMode
            | juce::FileBrowserComponent::canSelectFiles,
            [this](const juce::FileChooser& fc)
            {
                auto file = fc.getResult();

                if (file.existsAsFile())
                {
                    audioEngine.loadFile(file);
                    fftDisplay.setAudioEngine(&audioEngine);
                }
            });
    }
}
