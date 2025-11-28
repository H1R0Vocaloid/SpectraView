#include "AudioProcessorEngine.h"

AudioProcessorEngine::AudioProcessorEngine()
{
    formatManager.registerBasicFormats();
}

bool AudioProcessorEngine::loadFile(const juce::File& file)
{
    auto* reader = formatManager.createReaderFor(file);

    if (reader != nullptr)
    {
        sampleRate = (int)reader->sampleRate;
        audioBuffer.setSize(reader->numChannels, (int)reader->lengthInSamples);
        reader->read(&audioBuffer, 0, audioBuffer.getNumSamples(), 0, true, true);
        delete reader;
        return true;
    }
    return false;
}
