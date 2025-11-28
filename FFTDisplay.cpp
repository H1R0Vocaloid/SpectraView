#include "FFTDisplay.h"

FFTDisplay::FFTDisplay()
    : fft(fftOrder)
{
    fftData.resize(fftSize * 2, 0.0f);
    startTimerHz(30);
}

void FFTDisplay::setAudioEngine(AudioProcessorEngine* engine)
{
    audioEngine = engine;
}

void FFTDisplay::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);

    if (!audioEngine)
        return;

    auto& buffer = audioEngine->getBuffer();

    if (buffer.getNumSamples() < fftSize)
        return;

    auto* readPtr = buffer.getReadPointer(0);

    // 复制数据
    std::copy(readPtr, readPtr + fftSize, fftData.begin());

    // 窗函数（正确做法）
    window.multiplyWithWindowingTable(fftData.data(), fftSize);

    // FFT 频域
    fft.performFrequencyOnlyForwardTransform(fftData.data());

    g.setColour(juce::Colours::lime);
    auto w = (float)getWidth();
    auto h = (float)getHeight();

    for (int i = 1; i < fftSize / 2; ++i)
    {
        float x = juce::jmap<float>(i, 0, fftSize / 2, 0.0f, w);
        float magnitude = fftData[i];

        float y = juce::jmap<float>(magnitude, 0.0f, 120.0f, h, 0.0f);

        g.fillRect(juce::Rectangle<float>(x, y, 2.0f, h - y));
    }
}

void FFTDisplay::timerCallback()
{
    repaint();
}
