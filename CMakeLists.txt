cmake_minimum_required(VERSION 3.22)

project(AbeFFTAnalyzer VERSION 1.0.0)

include(FetchContent)

# 获取 JUCE
FetchContent_Declare(
    juce
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        8.0.0
)

FetchContent_MakeAvailable(juce)

# 使用 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加 GUI 程序
juce_add_gui_app(AbeFFTAnalyzerApp
    PRODUCT_NAME "Abe FFT Analyzer"
)

# 添加源文件
target_sources(AbeFFTAnalyzerApp PRIVATE
    Source/Main.cpp
    Source/MainComponent.cpp
    Source/MainComponent.h
    Source/AudioProcessorEngine.cpp
    Source/AudioProcessorEngine.h
    Source/FFTDisplay.cpp
    Source/FFTDisplay.h
)

# 链接 JUCE modules
target_link_libraries(AbeFFTAnalyzerApp PRIVATE
    juce::juce_gui_extra
    juce::juce_gui_basics
    juce::juce_graphics
    juce::juce_events
    juce::juce_core
    juce::juce_audio_devices
    juce::juce_audio_basics
    juce::juce_audio_formats
    juce::juce_dsp
)
